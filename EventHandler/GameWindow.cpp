#include "GameWindow.h"

//-----------------------------------------------------------------------------
// Name : CGameWin (constructor)
//-----------------------------------------------------------------------------
GameWindow::GameWindow(void)
	: kWidth(1024), KHeight(768) ,m_captionText("Game Window")
{
	m_bGameRunning = true;
}

//-----------------------------------------------------------------------------
// Name : CGameWin (destructor)
//-----------------------------------------------------------------------------
GameWindow::~GameWindow(void)
{
}

//-----------------------------------------------------------------------------
// Name : CreateDisplay 
// Desc : creates the window for the game and the directx device
//-----------------------------------------------------------------------------
bool GameWindow::CreateDisplay(HINSTANCE hInstance,bool windowed)
{
	D3DDEVTYPE deviceType=D3DDEVTYPE_HAL;

	if ( !CreateDisplayWindow(hInstance) )
		return false;

// 	if ( FAILED( CreateDevice(windowed) ) )
// 		return false;

	// 	if ( !CreateGUIObjects() )
	// 		return false;

	return true;
}

//-----------------------------------------------------------------------------
// Name : CreateDisplayWindow 
// Desc : holds the game message loop
//-----------------------------------------------------------------------------
bool GameWindow::CreateDisplayWindow(HINSTANCE hInstance)
{
	//Creating the window 
	WNDCLASS wc;
	wc.style         = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wc.lpfnWndProc   = StaticWndProc; 
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInstance;
	wc.hIcon         = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor       = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName  = 0;
	wc.lpszClassName = m_captionText.c_str();

	if( !RegisterClass(&wc) ) 
	{
		::MessageBox(0, "RegisterClass() - FAILED", 0, 0);
		return false;
	}

	//TODO: make Adjust Window Rect work ! somehow .....
// 	RECT rc2;
// 	rc2.top = 0;
// 	rc2.left = 0;
// 	rc2.bottom = 480;
// 	rc2.right = 640;
// 	AdjustWindowRect (&rc2,WS_OVERLAPPEDWINDOW,FALSE);

	m_hWnd = ::CreateWindowEx(WS_EX_CLIENTEDGE,  m_captionText.c_str(), m_captionText.c_str(), WS_OVERLAPPEDWINDOW|WS_VISIBLE , 0, 0, kWidth + 16 + 4, KHeight + 38 + 4, NULL, NULL, hInstance,(void*)this);

	if( !m_hWnd )
	{
		::MessageBox(NULL,"failed to create a window","lolz",MB_OK);
		return false;
	}

	::ShowWindow(m_hWnd, SW_SHOW);
	::UpdateWindow(m_hWnd);

// 	RECT rcd;
// 	GetClientRect(m_hWnd,&rcd);

	return true;
}


//-----------------------------------------------------------------------------
// Name : BeginGame 
// Desc : holds the game message loop
//-----------------------------------------------------------------------------
int GameWindow::BeginGame()
{
	MSG		msg;

	// Start main loop
	while (m_bGameRunning)
	{
		// Did we receive a message, or are we idling ?
		while ( PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) ) 
		{
			if (msg.message == WM_QUIT)
			{
				m_bGameRunning =  false;
				break;
			}
			TranslateMessage( &msg );
			DispatchMessage ( &msg );
		} 

		// Advance Game Frame.
		//m_timer->frameAdvanced();
		//FrameAdvance(m_timer->getTimeElapsed());
		// End If messages waiting
	}
	return 0;
}

//-----------------------------------------------------------------------------
// Name : ShutDown 
// Desc : shut down the game and calls the release function to clear the allocated memory
//-----------------------------------------------------------------------------
bool GameWindow::ShutDown()
{
	//m_GuiDilaogResManger.OnD3D9DestroyDevice();

	// Destroy Direct3D Objects
// 	if ( m_pD3DDevice ) 
// 	{
// 		int x;
// 		wtf = m_pD3DDevice->Release();
// 		x = 0;
// 	}

// 	if ( m_pD3D       ) 
// 	{
// 		int x;
// 		wtf = m_pD3D->Release();
// 		x = 0;
// 	}
// 	m_pD3D          = NULL;
// 	m_pD3DDevice    = NULL;

	// Destroy menu, it may not be attached
	if ( m_hMenu ) DestroyMenu( m_hMenu );
	m_hMenu         = NULL;

	// Destroy the render window
	SetMenu( m_hWnd, NULL );
	if ( m_hWnd ) DestroyWindow( m_hWnd );
	m_hWnd          = NULL;

// 	if (m_pCameras)
// 	{
// 		for (UINT i = 0; i < 2; i++)
// 			if (m_pCameras[i])
// 				delete m_pCameras[i];
// 	}
	//delete m_pCamera;

	//Release();

	//m_gameRunning = false;
	// Shutdown Success
	return true;
}