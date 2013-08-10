#ifndef  _GAMEWIDNWO_H
#define  _GAMEWINDOW_H

#include <Windows.h>
#include <d3dx9.h>
#include <string>
#include "MsgHandler.h"

class GameWindow
{
public:
	GameWindow(void);
	virtual ~GameWindow(void);

	bool	InitInstance		(HINSTANCE hInstance, LPCTSTR lpCmdLine, int iCmdShow );
	bool    CreateDisplay		(HINSTANCE hInstance,bool windowed);
	bool	CreateDisplayWindow (HINSTANCE hInstance);

	int     BeginGame			( );
	bool    ShutDown			( );

private:
	//-------------------------------------------------------------------------
	// Private Variables For This Class
	//-------------------------------------------------------------------------
	HWND                     m_hWnd;             // Main window HWND
	HICON                    m_hIcon;            // Window Icon
	HMENU                    m_hMenu;            // Window Menu

	bool m_bGameRunning;

	std::string m_captionText;

	const UINT kWidth;
	const UINT KHeight;
};

#endif  //_GAMEWINDOW_H