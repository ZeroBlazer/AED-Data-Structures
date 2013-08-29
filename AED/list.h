#ifndef LIST_H
#define LIST_H

#include "foundations.h"

template<typename T>
class list
{
    typedef Node<T> * pNode_T;

    protected:
        pNode_T m_pHead;
        sizet m_size;

    private:
        bool inner_find(T&d, Node<T> ** &);
    public:
        list() : m_pHead(0), m_size(0) {}
        virtual ~list() {}

        sizet size() {return m_size;}
        T& at(sizet);
        T& operator [](sizet position) {return at(position);}
        void showList();

        bool find(T&, Node<T> ** &);

        void push_front(T&);
        void push_back(T&);
        void pop_front();
        void pop_back();
        void remove(T&);
};

#endif // LIST_H

template<typename T>
T& list<T>::at(sizet position)
{
    if(position>=m_size || position<0)
        throw 0;

    pNode_T tmp=m_pHead;
    while(position)
    {
        tmp=tmp->m_pNext;
        position--;
    }
    return tmp->m_dato;
}

void showList();

template<typename T>
void list<T>::push_front(T&d)
{
    pNode_T nu = new Node<T> (d);
    if(m_pHead)
        nu->m_pNext=m_pHead;
    m_pHead=nu;
    m_size++;
}

template<typename T>
void list<T>::push_back(T&d)
{
    pNode_T nu = new Node<T> (d);

    if(!m_pHead)
        m_pHead=nu;
    else
    {
        pNode_T tmp= m_pHead;

        while(tmp->m_pNext)
            tmp=tmp->m_pNext;

        tmp->m_pNext=nu;
    }
    m_size++;
}

/** Starts looking up d since pointer */
template<typename T>
bool list<T>::inner_find(T&d, Node<T> ** &pointer)
{
    while(*pointer)
    {
        if((*pointer)->m_dato==d)
            return true;
        pointer=&((*pointer)->m_pNext);
    }
    return false;
}

/** Looks up data d on the list, starting since head */
template<typename T>
bool list<T>::find(T&d, Node<T> ** &pointer)
{
    pointer=&m_pHead;
    return inner_find(d,pointer);
}
//-------------------------a---------------------------
template<typename T>
void list<T>::pop_front()
{
    if(!m_pHead)
        return;

    pNode_T tmp=m_pHead;
    m_pHead=m_pHead->m_pNext;

    delete tmp;
    m_size--;
}
//-------------------------b---------------------------
template<typename T>
void list<T>::pop_back()
{
    if(!m_size)
        return;

    pNode_T tmp=m_pHead;
    pNode_T father;

    while(tmp->m_pNext)
    {
        father=tmp;
        tmp=tmp->m_pNext;
    }
    delete tmp;

    if(m_size!=1)
        father->m_pNext=0;
    m_size--;
}
//-------------------------c--------------------------
/** Removes all the Nodes with the same data than given d */
template<typename T>
void list<T>::remove(T&d)
{
    pNode_T *tmp=&m_pHead;
    pNode_T mem;

    while (inner_find(d, tmp))
    {
        mem=(*tmp);
        (*tmp)=(*tmp)->m_pNext;
        delete mem;
        m_size--;
    }
}