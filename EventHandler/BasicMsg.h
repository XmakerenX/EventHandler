#pragma once

class BasicMsg
{
public:
	virtual void operator() () = 0;
	virtual void FireMsg	() = 0;

	int GetId();

protected:
	int m_msgId;
};
