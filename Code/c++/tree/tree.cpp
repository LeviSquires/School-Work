#include "tree.h"

Tree::Tree() : _pRoot(0)
{
}

void Tree::Clear()
{
	delete _pRoot;
	_pRoot = 0;
}

bool Tree::Insert(int data)
{
	if(isEmpty())
	{
		_pRoot = new TreeNode(data);
		return true;
	}
	return _pRoot -> Insert(data);
}

bool TreeNode::Insert(int data)
{
	if(data == _data)
	{
		return false;
	}
	if(data > _data)
	{
		if(_pRight == 0)
		{
			_pRight = new TreeNode(data);
			return true;
		}
		else
		{
			return _pRight -> Insert(data);
		}
	}
	if(_pLeft == 0)
	{
		_pLeft = new TreeNode(data);
		return true;
	}
	return _pLeft -> Insert(data);
}

void TreeNode::InOrder(std::ostream& os) const
{
	if(_pLeft)
	{
		_pLeft -> InOrder(os);
	}
	os << _data << " ";
	if(_pRight)
	{
		_pRight -> InOrder(os);
	}
}

void TreeNode::PreOrder(std::ostream& os) const
{
	os << _data << " ";
	if(_pLeft)
	{
		_pLeft -> PreOrder(os);
	}
	if(_pRight)
	{
		_pRight -> PreOrder(os);
	}
}

void TreeNode::PostOrder(std::ostream& os) const
{
	if(_pLeft)
	{
		_pLeft -> PostOrder(os);
	}
	if(_pRight)
	{
		_pRight -> PostOrder(os);
	}
	os << _data << " ";
}

void Tree::InOrder(ostream& os) const
{
	if(isEmpty())
	{
		os << "<empty>" << endl;
	}
	else
	{	
		_pRoot -> InOrder(os);
	}
}

void Tree::PreOrder(ostream& os) const
{
	if(isEmpty())
	{
		os << "<empty>" << endl;
	}
	else
	{	
		_pRoot -> PreOrder(os);
	}
}

void Tree::PostOrder(ostream& os) const
{
	if(isEmpty())
	{
		os << "<empty>" << endl;
	}
	else
	{	
		_pRoot -> PostOrder(os);
	}
}
