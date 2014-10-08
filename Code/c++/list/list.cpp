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

List::List() : _pFront(NULL), _pBack(NULL)
{
}

List::~List()
{
	Clear();
}

bool List::IsEmpty() const
{
	if(_pFront == NULL)
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
		return;
	}
	if(_pFront == _pBack)
	{
		delete _pFront;
		_pFront = NULL;
		_pBack = NULL;	
		return;
	}
	Node* p = _pFront;
	_pFront = _pFront -> _pPrev;
	_pFront -> _pNext = NULL;
	delete p;
}

void List::PopBack()
{
	if(IsEmpty())
	{
		return;
	}
	if(_pFront == _pBack)
	{
		delete _pBack;
		_pFront = NULL;
		_pBack = NULL;	
		return;
	}
	Node* p =_pBack;
	_pBack = _pBack -> _pNext;
	_pBack -> _pPrev = NULL;
	delete p;
}

int List::Front() const
{
	if(IsEmpty())
	{
		//what do we do here?
		return 0;
	}
	return _pFront -> _data;
}

int List::Back() const
{
	if(IsEmpty())
	{
		//what do we do here?
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
	if(_pFront == _pBack)
	{
		return 1;
	}
	//Walk of the list - iteration
	unsigned ret = 0;
	Node* p = _pFront;
	while(p)
	{
		p = p -> _pPrev;
		++ret;
	}
	return ret;
	//done recursively
	//return _pFront -> Count();
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
	_pFront = NULL;
	_pBack = NULL;
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

/*
	
	
	

	
	void Display();

	

	void Insert(int data, unsigned after);
*/
