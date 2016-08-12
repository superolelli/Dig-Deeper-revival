#include "Subject.hpp"



//erases the particular observer from the list
void CSubject::RemoveObserver(CObserver *_observer)
{
	std::list<CObserver*>::iterator i;

	for (i = m_pObserverList.begin(); i != m_pObserverList.end(); i++)
	{
		if ((*i) == _observer)
		{
			i = m_pObserverList.erase(i);
			return;
		}
	}
}




void CSubject::Notify(int _subject, int _action, int _object)
{
	//notifies the action to each observer
	for (CObserver *obs : m_pObserverList)
		obs->OnNotify(_subject, _action, _object);
}