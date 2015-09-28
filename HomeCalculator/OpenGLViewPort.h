#pragma once
#include <windows.h>
#include <tchar.h>
#include <gl/gl.h>
#include <gl/glu.h>

using namespace std;

class OpenGLViewPort
{
private:
	
	HWND hWnd;
	WNDCLASSEX wcex;
	HDC hDC;
	HGLRC hRC;
public:
	OpenGLViewPort();
	OpenGLViewPort(HWND owner, int x, int y, int width, int height);
	virtual ~OpenGLViewPort();
	
	void enableOpenGL();
	void disableOpenGL();
	void show(int cmdShow);
	void testOpenGL();
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)                  /* handle the messages */
		{
		case WM_DESTROY:
			PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
			break;
		default:                      /* for messages that we don't deal with */
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		return 0;
	}
};

