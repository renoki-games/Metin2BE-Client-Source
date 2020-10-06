#include "StdAfx.h"
#include "Locale_inc.h"

#ifdef CEF_BROWSER
#include <string>
#include <algorithm>
#include <windows.h>

#pragma comment (lib, "libcef.lib")
#ifdef _DEBUG
#pragma comment (lib, "libcef_dll_wrapper_debug.lib")
#else
#pragma comment (lib, "libcef_dll_wrapper.lib")
#endif

#include "../../extern/include/cef/cef_app.h"
#include "../../extern/include/cef/cef_browser.h"
#include "CefWebBrowser.h"

ClientHandler* g_handler = 0;

static const char* CEF_WEBBROWSER_CLASSNAME = "WEBBROWSER";
static HINSTANCE gs_hInstance = NULL;
static HWND gs_hWndCefWebBrowser = NULL;
static HWND gs_hWndParent = NULL;

LRESULT CALLBACK MessageWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, message, wParam, lParam);
}

HWND CreateMessageWindow(HINSTANCE hInstance)
{
	WNDCLASSEX wc = {
		0
	};

	wc.cbSize = sizeof(wc);
	wc.lpfnWndProc = MessageWndProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = "ClientMessageWindow";
	RegisterClassEx(&wc);
	return CreateWindow("ClientMessageWindow", 0, 0, 0, 0, 0, 0, HWND_MESSAGE, 0, hInstance, 0);
}

LRESULT CALLBACK CefWebBrowser_WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		return(true);
	case WM_SIZE:
		return(0);
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int CefWebBrowser_Show(HWND hParent, const char* addr, const RECT* rc)
{
	if (gs_hWndCefWebBrowser)
		return 0;

	gs_hWndParent = hParent;
	gs_hWndCefWebBrowser = CreateWindowEx(0, // Optional window styles.
		CEF_WEBBROWSER_CLASSNAME, // Window class
		"m2CefBrowser", // Window text
		WS_CHILD | WS_VISIBLE, // Window style
		rc->left, // Size and position (Left)
		rc->top, // Size and position (Top)
		rc->right - rc->left, // Size and position (Right)
		rc->bottom - rc->top, // Size and position (Bottom)
		hParent, // Parent window
		NULL, // Menu
		gs_hInstance, // Instance handle
		0 // Additional application data
	);

	if (gs_hWndCefWebBrowser == NULL)
		return 0;

	CefMainArgs main_args(gs_hInstance);
	CefRefPtr<ClientApp> app(new ClientApp);

	int exit_code = CefExecuteProcess(main_args, app.get(), NULL);
	if (exit_code >= 0)
		exit(exit_code);

	RECT rect;
	GetClientRect(gs_hWndCefWebBrowser, &rect);

	CefSettings settings;
	settings.multi_threaded_message_loop = true;
#if !defined(_DEBUG)
	settings.log_severity = LOGSEVERITY_DISABLE;
#endif
	CefInitialize(main_args, settings, app.get(), NULL);

	CefWindowInfo info;
	CefBrowserSettings b_settings;

	CefRefPtr<CefClient> client(new ClientHandler);
	g_handler = (ClientHandler*)client.get();

	std::string path = (LPTSTR)addr;
	CefRefPtr<CefCommandLine> command_line = CefCommandLine::GetGlobalCommandLine();
	// command_line->AppendArgument("disable-extensions");
	// info.SetAsPopup(NULL, "m2CefBrowser");

	if (!command_line->HasSwitch("disable-gpu-shader-disk-cache")) {
		// Don't create a "GPUCache" directory when cache-path is unspecified.
		command_line->AppendSwitch("disable-gpu-shader-disk-cache");
	}

	if (command_line->HasSwitch("url"))
		path = command_line->GetSwitchValue("url");

	info.SetAsChild(gs_hWndCefWebBrowser, rect);
	CefBrowserHost::CreateBrowser(info, client.get(), path, b_settings, NULL, NULL);

	ShowWindow(gs_hWndCefWebBrowser, SW_SHOW);
	UpdateWindow(gs_hWndCefWebBrowser);

	int result = 1;

	if (!settings.multi_threaded_message_loop)
	{
		// Run the CEF message loop. This function will block until the application
		// recieves a WM_QUIT message.
		CefRunMessageLoop();
	}
	else
	{
		return result;
	}

	SetFocus(gs_hWndCefWebBrowser);

	CefShutdown();
	return result;
}

void CefWebBrowser_Move(const RECT* rc)
{
	MoveWindow(gs_hWndCefWebBrowser, rc->left, rc->top, rc->right - rc->left, rc->bottom - rc->top, 1);
}

void CefWebBrowser_Hide()
{
	if (!gs_hWndCefWebBrowser)
		return;

	ShowWindow(gs_hWndCefWebBrowser, SW_HIDE);

	if (IsWindow(gs_hWndCefWebBrowser))
		DestroyWindow(gs_hWndCefWebBrowser);

	gs_hWndCefWebBrowser = NULL;

	SetFocus(gs_hWndParent);
}

int CefWebBrowser_IsVisible()
{
	return (gs_hWndCefWebBrowser != NULL);
}

void CefWebBrowser_Destroy()
{
	CefWebBrowser_Hide();
}

int CefWebBrowser_Startup(HINSTANCE hInstance)
{
	/*
	if (OleInitialize(NULL) != S_OK)
		return 0;
	*/

	CefMainArgs main_args(hInstance);
	CefRefPtr<ClientApp> app(new ClientApp);

	int exit_code = CefExecuteProcess(main_args, app.get(), NULL);
	if (exit_code >= 0)
		exit(exit_code);

	{
		WNDCLASSEX wc;
		ZeroMemory(&wc, sizeof(WNDCLASSEX));
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.hInstance = hInstance;
		wc.lpfnWndProc = CefWebBrowser_WindowProc;
		wc.lpszClassName = CEF_WEBBROWSER_CLASSNAME;
		RegisterClassEx(&wc);
	}

	gs_hInstance = hInstance;
	return 1;
}

void CefWebBrowser_Cleanup()
{
	if (gs_hInstance)
		UnregisterClass(CEF_WEBBROWSER_CLASSNAME, gs_hInstance);

	CefShutdown();
	// OleUninitialize();
}

#endif // __CEF_WEB_BROWSER__
