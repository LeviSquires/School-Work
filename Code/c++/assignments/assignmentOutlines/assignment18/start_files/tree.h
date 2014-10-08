#if !defined(TREE_H__)
#define TREE_H__

#include <ostream>

using namespace std;

class TreeNode
{

  TreeNode(int data) : _pLeft(0), _pRight(0), _data(data)
  {
  }
  
  ~TreeNode()
  {
    //You can call delete safely on a NULL pointer.
    delete _pLeft;
    delete _pRight;
  }
  
  void InOrder(std::ostream& os) const;
  void PreOrder(std::ostream& os) const;
  void PostOrder(std::ostream& os) const;
  
  bool Insert(int data);

  TreeNode* _pLeft;
  TreeNode* _pRight;
  int _data;
  friend class Tree;
};


class Tree
{
public:  
  Tree();
  ~Tree()
  {
    Clear();
  }
  
  void Clear();
  
  bool Insert(int data);
  bool IsEmpty() const
  {
    return _pRoot == 0;
  }
  
  void InOrder(ostream& os)const;
  void PreOrder(ostream& os)const;
  void PostOrder(ostream& os)const;
  
  
private:
  TreeNode* _pRoot;
  
  
  
};













#endif