#include <ostream>

class Node
{
	Node(int data) : _data(data), _pNext(nullptr), _pPrev(nullptr)
	{
	}
	unsigned Count() const
	{
		if(!_pPrev)
		{
			return 1;
		}
		return 1 + _pPrev -> Count();
	}
	void Display(std::ostream& os) const;
	int _data;
	Node* _pNext;
	Node* _pPrev;
	friend class List;
};




class List
{
public :
	List();
	~List();
	void PushFront(int data);
	void PushBack(int data);
	int Front() const;
	int Back() const;
	void PopFront();
	void PopBack();
	void Display(std::ostream& os) const;
	unsigned Size() const;
	bool IsEmpty() const;
	void Clear();
	void Insert(int data, unsigned after);
	
private :
	Node* _pFront;
	Node* _pBack;
};



