#include <iostream>
#include "list.h"

void Node::Display(std::ostream& os) const
{
    os << _data;
	if(_pNext)
	{
	    os << " ";
		_pNext -> Display(os);
	}
}



List::List() : _pFront(0), _pBack(0)
{
}

List::~List()
{
	Clear();
}

bool List::IsEmpty() const
{
//    return _pFront == 0;
	
	if(_pFront == 0)
	{
	    return true;
	}
	return false;	
}

void List::PushFront(int data)
{
	Node* p = new Node(data);
	if(IsEmpty())
	{
		_pFront = p;
		_pBack = p;
		return;
	}
	p -> _pPrev = _pFront;
	_pFront -> _pNext = p;
	_pFront = p;
}

void List::PushBack(int data)
{
	Node* p = new Node(data);
	if(IsEmpty())
	{
		_pFront = p;
		_pBack = p;
		return;
	}
	p -> _pNext = _pBack;
	_pBack -> _pPrev = p;
	_pBack = p;
	
}

void List::PopFront()
{
	//do nothing on an empty list
	if(IsEmpty())
	{
	    //Not totally happy with this but we will deal with it later.
	    return;
	}
	if(_pFront == _pBack)
	{
	    delete _pFront;
		_pFront = 0;
		_pBack = 0;
		return;
	}
	Node* p = _pFront;
	_pFront = _pFront -> _pPrev;
	_pFront -> _pNext = 0;
	delete p;
	
	
}

void List::PopBack()
{
	//do nothing on an empty list
	if(IsEmpty())
	{
	    //Not totally happy with this but we will deal with it later.
	    return;
	}
	if(_pFront == _pBack)
	{
	    delete _pFront;
		_pFront = 0;
		_pBack = 0;
		return;
	}
	Node* p = _pBack;
	_pBack = _pBack -> _pNext;
	_pBack -> _pPrev = 0;
	delete p;
}

int List::Front() const
{
    if(IsEmpty())
	{
		//What the hell do we do???!
		return 0;
	}
	return _pFront -> _data;
	
}

int List::Back() const
{
    if(IsEmpty())
	{
		//What the hell do we do???!
		return 0;
	}
	return _pBack -> _data;
	
}

unsigned List::Size() const
{
    if(IsEmpty())
	{
	    return 0;
	}
	if(_pBack == _pFront)
	{
	    return 1;
	}

	/*
	//Walk the list -- Iteration
	unsigned ret = 0;
	Node* p = _pFront;
	while(p)
	{
	    p = p -> _pPrev;
		++ret;
	}
    return ret;
	*/

	//How do we do this recursively?
	return _pFront -> Count();	
}

void List::Clear()
{
	if(IsEmpty())
	{
		return;
	}
	
	Node* p = _pFront;
	Node* prev = p -> _pPrev;
	
	while(p)
	{
	    delete p;
	    p = prev;
		if(prev)
		{
		    prev = p -> _pPrev;
		}
	}
	_pFront = 0;
	_pBack = 0;
	
}

void List::Display(std::ostream& os) const
{
   if(IsEmpty())
   {
       os << "<empty>";
	   return;
   }
   _pBack -> Display(os); 
}



