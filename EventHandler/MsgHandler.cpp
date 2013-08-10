#include "MsgHandler.h"


MsgHandler::MsgHandler(void)
{
}


MsgHandler::~MsgHandler(void)
{
}

void MsgHandler::RegisterMsg(BasicMsg* msg)
{
	m_msgs[msg->GetId()] = msg;
}

void MsgHandler::Invoke(int msgId)
{
	m_msgs[msgId]->FireMsg();
}

LRESULT CALLBACK MsgHandler::StaticWndProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	// If this is a create message, trap the 'this' pointer passed in and store it within the window.
	if ( Message == WM_CREATE ) SetWindowLong( hWnd, GWL_USERDATA, (LONG)((CREATESTRUCT FAR *)lParam)->lpCreateParams);

	// Obtain the correct destination for this message
	MsgHandler * Destination = (MsgHandler*)GetWindowLong( hWnd, GWL_USERDATA );

	// If the hWnd has a related class, pass it through
	if (Destination) return Destination->WinProc( hWnd, Message, wParam, lParam );

	// No destination found, defer to system...
	return DefWindowProc( hWnd, Message, wParam, lParam );
}

LRESULT MsgHandler::WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	Invoke(message);
}