Assignment 18

Pseudo Code

	Started by making both Tree and TreeNode template classes. This was done by replacing any int data types with <T> 
and adding template<class T> before any functions.

	Drew a tree transversal using the three transversal's provided(See included paper for details).

	Implemented copy constructor and assignment operator(got help from fellow students to figure this out).
	
template<class T>
void Tree<T>::operator=(const Tree<T>& tree)
{
	Clear(); //clears the _pRoot pointer
	_pRoot = new TreeNode<T>(tree._pRoot->_data); //after _pRoot has been cleared assigns it to a new TreeNode passing in the values of tree.
	_pRoot->CloneChildren(tree._pRoot); //Uses the CloneChildren function to copy over _pRoots for Tree that is being assigned.
}

template<class T>
Tree<T>::Tree(const Tree& tree) //same as the assignment operator except no need to clear _pRoot since it hasn't been assigned yet when dealing with a new tree.
{
	_pRoot = new TreeNode<T>(tree._pRoot->_data);
	_pRoot->CloneChildren(tree._pRoot);
}

	Implemented a recursive CloneChildren function(got help from fellow students to figure this out).
	
void CloneChildren(const TreeNode<T>* p)
  {
	  if (p->_pLeft) //clones left
	  {
		  _pLeft = new TreeNode<T>(p->_pLeft->_data); //sets _pLeft to a new TreeNode and attaches to the implied object.
		  _pLeft->CloneChildren(p->_pLeft); //recursively calls the function.
	  }
	  if (p->_pRight) //clones right
	  {
		  _pRight = new TreeNode<T>(p->_pRight->_data);
		  _pRight->CloneChildren(p->_pRight);
	  }
  }
