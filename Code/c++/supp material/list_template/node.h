#if !defined(NODE_H__)
#define NODE_H__

#include <ostream>
using  std::ostream;

template
<class T>
class Node
{
    Node(const T&  data);
    ~Node();
    const T& GetData() const;
    ostream& OutputNode(ostream& os);
    T m_Data;
    Node* m_pPrev;
    Node* m_pNext; 
    template <class T> friend class List;   
};
    
template
<class T>
Node<T>::Node(const T& d) : m_Data(d), m_pPrev(0), m_pNext(0)
{
    
}

template
<class T>
Node<T>::~Node()
{
/*
    if(m_pNext == 0)
    {
        return;
    }    
    delete m_pNext;
*/        
}

template
<class T>
const T& Node<T>::GetData() const
{
    return m_Data;
}            

template
<class T>
ostream& Node<T>::OutputNode(ostream& os)
{
    os << m_Data << std::endl;
    if(m_pNext != 0)
    {
        m_pNext -> OutputNode(os);
    }    
    return os;
}    

    






#endif


