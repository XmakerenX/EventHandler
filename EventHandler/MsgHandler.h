#ifndef  _MSGHANDLER_H
#define  _MSGHANDLER_H

#include <unordered_map>
#include <Windows.h>
#include "BasicMsg.h"
#include "SpecificMsg.h"

class MsgHandler
{
public:
	MsgHandler(void);
	virtual ~MsgHandler(void);

	//template<class OBJ>
	void RegisterMsg(BasicMsg* msg);

	void Invoke(int msgId);

	static LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
	LRESULT				    WinProc		 (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	//template<class OBJ>
	std::unordered_map<int, BasicMsg* > m_msgs;  
};

#endif  //_MSGHANDLER_H