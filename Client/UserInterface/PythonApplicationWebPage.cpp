#include "StdAfx.h"
#include "PythonApplication.h"

#ifdef CEF_BROWSER
#include "CefWebBrowser.h"
#else
#include "../CWebBrowser/CWebBrowser.h"
#endif

bool CPythonApplication::IsWebPageMode()
{
#ifdef CEF_BROWSER
	return CefWebBrowser_IsVisible() ? true : false;
#else
	return WebBrowser_IsVisible() ? true : false;
#endif
}

void CPythonApplication::ShowWebPage(const char* c_szURL, const RECT& c_rcWebPage)
{
#ifdef CEF_BROWSER
	if (CefWebBrowser_IsVisible())
#else
	if (WebBrowser_IsVisible())
#endif
		return;

	m_grpDevice.EnableWebBrowserMode(c_rcWebPage);
#ifdef CEF_BROWSER
	if (!CefWebBrowser_Show(GetWindowHandle(), c_szURL, &c_rcWebPage))
#else
	if (!WebBrowser_Show(GetWindowHandle(), c_szURL, &c_rcWebPage))
#endif
	{
		TraceError("CREATE_WEBBROWSER_ERROR:%d", GetLastError());
	}

	SetCursorMode(CURSOR_MODE_HARDWARE);
}

void CPythonApplication::MoveWebPage(const RECT& c_rcWebPage)
{
#ifdef CEF_BROWSER
	if (CefWebBrowser_IsVisible())
#else
	if (WebBrowser_IsVisible())
#endif
	{
#ifdef CEF_BROWSER
		CefWebBrowser_Move(&c_rcWebPage);
#else
		WebBrowser_Move(&c_rcWebPage);
#endif
	}
}

void CPythonApplication::HideWebPage()
{
#ifdef CEF_BROWSER
	if (CefWebBrowser_IsVisible())
	{
		CefWebBrowser_Hide();
#else
	if (WebBrowser_IsVisible())
	{
		WebBrowser_Hide();
#endif

		m_grpDevice.DisableWebBrowserMode();

		if (m_pySystem.IsSoftwareCursor())
			SetCursorMode(CURSOR_MODE_SOFTWARE);
		else
			SetCursorMode(CURSOR_MODE_HARDWARE);
	}
}
