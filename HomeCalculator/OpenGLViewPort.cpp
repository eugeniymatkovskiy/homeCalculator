#include "OpenGLViewPort.h"


OpenGLViewPort::OpenGLViewPort()
{
}


OpenGLViewPort::~OpenGLViewPort()
{
	DestroyWindow(this->hWnd);
}

OpenGLViewPort::OpenGLViewPort(HWND owner, int x, int y, int width, int height)
{
	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = OpenGLViewPort::WindowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = GetModuleHandle(NULL);
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "OpenGLViewPort";
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&wcex);

	hWnd = CreateWindowEx(0,
		"OpenGLViewPort",
		NULL,
		WS_CHILDWINDOW,
		x,
		y,
		width,
		height,
		owner,
		NULL,
		GetModuleHandle(NULL),
		NULL);
}

void OpenGLViewPort::show(int cmdShow)
{
	ShowWindow(this->hWnd, cmdShow);
}

void OpenGLViewPort::enableOpenGL()
{
	PIXELFORMATDESCRIPTOR pfd;

	int iFormat;

	/* get the device context (DC) */
	this->hDC = GetDC(hWnd);

	/* set the pixel format for the DC */
	ZeroMemory(&pfd, sizeof(pfd));

	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;

	iFormat = ChoosePixelFormat(hDC, &pfd);

	SetPixelFormat(hDC, iFormat, &pfd);

	/* create and enable the render context (RC) */
//	this->hRC = wglCreateContext(hDC);

	// wglMakeCurrent(hDC, hRC);
}

void OpenGLViewPort::disableOpenGL()
{
	//wglMakeCurrent(NULL, NULL);
	//wglDeleteContext(this->hRC);
	ReleaseDC(this->hWnd, this->hDC);
}

void OpenGLViewPort::testOpenGL()
{
	//glClearColor(1.0f, 0.5f, 0.5f, 0.5f);
}