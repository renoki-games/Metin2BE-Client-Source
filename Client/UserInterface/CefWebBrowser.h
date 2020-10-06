#pragma once

#include "CefClientApp.h"
#include "CefClientHandler.h"

extern "C" {
	int CefWebBrowser_Startup(HINSTANCE hInstance);
	void CefWebBrowser_Cleanup();
	void CefWebBrowser_Destroy();
	int CefWebBrowser_Show(HWND parent, const char* addr, const RECT* rcWebBrowser);
	void CefWebBrowser_Hide();
	void CefWebBrowser_Move(const RECT* rcWebBrowser);

	int CefWebBrowser_IsVisible();
	const RECT& CefWebBrowser_GetRect();
};
