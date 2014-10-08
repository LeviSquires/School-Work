#if !defined(LIST_H__)
#define LIST_H__

#include <ostream>
#include <exception>
using std::ostream;
#include "node.h"


//class Node;


template
<class T>

class List
{
public:
    List();
    ~List();
    void Clear();
    //Adds to the front 
    void PushFront(const T& data);
    //adds to the back
    void PushBack(const T&  data);
    //removes from the front
    void PopFront();
    //removes from the back
    void PopBack();
    //gets the back value
    const T&  Back() const;
    //gets the front value
    const T&  Front() const;

    bool Empty() const {return m_pFront == 0;}

   

    List& operator=(const List& list);
    List(const List& list);

private:    
    Node<T>* m_pFront;
    Node<T>* m_pBack;
    ostream& OutPut(ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const List& lst);
    
};

/*
template
<class T>
std::ostream& operator<<(std::ostream& os, const List<T>& lst)
{
	lst.OutPut(os);
	return os;
}
*/

template
<class T>
List<T>::List() : m_pFront(0), m_pBack(0)
{
    
}


template
<class T>
List<T>::~List()
{
    Clear();
}    

template
<class T>
void List<T>::Clear()
{
    
    //delete 
    if(!m_pFront)
    {
        return;
    }
	/*
    delete m_pFront;
    m_pFront = 0;
    m_pBack = 0;
    */
    
    //Iterative version
    Node<T>* p = m_pFront;
    Node<T>* pnext = m_pFront -> m_pNext;
    while(p != 0)
    {
        delete p;
        p = pnext;
        if(p != 0)
        {    
            pnext = p -> m_pNext;
        }
    }    
    m_pFront = 0;
    m_pBack = 0;
    
}


template
<class T>
List<T>& List<T>::operator=(const List<T>& list)
{
    if(this == &list)
    {
        return *this;
    } 
    Clear();
    if(list.Empty() == true)
    {
        return *this;
    }    

    Node<T>* p = list.m_pFront;
    while(p != 0)
    {
        PushBack(p -> m_Data);
        p = p -> m_pNext;        
    }    
    return *this;
}


template
<class T>
List<T>::List(const List<T>& list)  : m_pFront(0), m_pBack(0)
{
    if(list.Empty() == true)
    {
        return;
    }    
    Node<T>* p = list.m_pFront;
    while(p != 0)
    {
        PushBack(p -> m_Data);
        p = p -> m_pNext;        
    }    
}



    
template
<class T>
void List<T>::PushFront(const T& data)
{
    //create a new node
    Node<T>* p = new Node<T>(data);
    
    //Empty list    
    if(!m_pFront)
    {
        m_pFront = p;
        m_pBack = p;
    }
    else //Not empty list
    {
        p -> m_pNext = m_pFront;
        m_pFront -> m_pPrev = p;
        m_pFront = p;
    }
}
    
template
<class T>
void List<T>::PushBack(const T& data)
{
    Node<T>* p =  new Node<T>(data);
    
    if(!m_pBack)
    {
        m_pFront = p;
        m_pBack = p;        
    }
    else
    {
        p -> m_pPrev = m_pBack;
        m_pBack -> m_pNext = p;
        m_pBack = p;
    }       
}    

template
<class T>
void List<T>::PopFront()
{
    if(m_pFront == 0)
    {
        //Fuggetaboutit
        return;
    }
    if(m_pBack == m_pFront)
    {
        Clear();
        return;
    }
    Node<T>* p = m_pFront;
    m_pFront = m_pFront -> m_pNext;
    p -> m_pNext = 0;
    m_pFront -> m_pPrev = 0;    
    delete p;
}

template
<class T>
void List<T>::PopBack()
{
    if(m_pBack == 0)
    {
        //Fuggetaboutit
        return;
    }
    if(m_pBack == m_pFront)
    {
        Clear();
        return;
    }
    Node<T>* p = m_pBack;
    m_pBack = m_pBack -> m_pPrev;
    p -> m_pPrev = 0;
    m_pBack -> m_pNext = 0;
    delete p;
}


template
<class T>
ostream& List<T>::OutPut(ostream& os) const
{
    if(Empty() == true)
    {
        os << "<empty>";
    }
    else
    {
        m_pFront -> OutputNode(os);
    }
    return os;    
}    


template
<class T>
const T& List<T>::Back() const
{
    if(m_pBack == 0)
    {
        throw std::domain_error("List has no back member.");
    }
    return m_pBack -> GetData();
}

template
<class T>
const T& List<T>::Front() const
{
    if(m_pFront == 0)
    {
        throw std::domain_error("List has no front member.");
    }
    return m_pFront -> GetData();;    
}
    



#endif

