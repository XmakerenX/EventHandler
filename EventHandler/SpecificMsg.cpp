#include "SpecificMsg.h"

template<class TObj>
SpecificMsg<TObj>::SpecificMsg(TObj* pToObj, callbackFunc callback, int msgId)
	: m_pToOBJ(pToObj), m_callback(callback),m_msgId(msgId)
{
}

template<class TObj>
SpecificMsg<TObj>::~SpecificMsg()
{
}

template<class TObj>
int SpecificMsg<TObj>::GetId()
{
	return m_msgId;
}

template<class TObj>
void SpecificMsg<TObj>::FireMsg()
{
	m_pToOBJ.m_callback();
}
