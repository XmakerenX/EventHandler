#ifndef  _SPECIFIC_H
#define  _SPECIFIC_H

template<class TObj>
class SpecificMsg : public BasicMsg
{
public:
	typedef void (*callbackFunc) ();

	SpecificMsg(TObj* pToObj, callbackFunc callback, int msgId);
	virtual ~SpecificMsg();

	virtual void FireMsg();

private:
	TObj* m_pToOBJ;
	callbackFunc m_callback;
};

#endif  //_SPECIFIC_H
