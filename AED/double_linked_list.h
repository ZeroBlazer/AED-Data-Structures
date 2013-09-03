#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include "foundations.h"

template<typename T>
class double_linked_list
{
    typedef doublePointer_Node<T> Node_T;
    typedef Node_T * pNode_T;

    protected:
        pNode_T m_pHead;
        pNode_T m_pTail;

        sizet m_size;
        bool m_unique;

    private:
        /*bool inner_find(T &d, pNode_T *&);
        void add_rec(T &d,pNode_T &pCurrent);
        bool find_rec(T &d, pNode_T &pCurrent);
        void invert(pNode_T father, pNode_T son, pNode_T grandSon);*/

    public:

        double_linked_list(bool unique=0) : m_pHead(0), m_pTail(0), m_size(0), m_unique(unique) {}
        virtual ~double_linked_list();

        inline sizet size() {return m_size;}
        T& at(sizet);
        inline T& operator [](sizet position) {return at(position);}

        //bool find(T&, pNode_T* &);

        void push_front(T&);
        void push_back(T&);
        /*void pop_front();
        void pop_back();
        void remove(T &);
        inline void add_rec(T &d) {return add_rec(d,m_pHead);}
        inline bool find_rec(T &d) {return find_rec(d,m_pHead);}
        void invert();
        T *find_max();
        sizet count();
        list<T>* op_intersection(list<T> &second);
        list<T>* op_union(list<T> &second);
        sizet count(T &d);*/
};

template<typename T>
double_linked_list<T>::~double_linked_list()
{
    pNode_T tmp1 = m_pHead,
            tmp2;
    while(tmp1!=m_pTail)
    {
        tmp2 = tmp1->m_pNext;
        delete tmp1;
        tmp1 = tmp2;
    }
}

template<typename T>
T& double_linked_list<T>::at(sizet position)
{
    if(position>=m_size || position<0)
        throw 0;

    pNode_T tmp;

    if(position<=(m_size-1)/2)
    {
        tmp=m_pHead;
        for(; position; position--)
            tmp=tmp->m_pNext;
    }
    else
    {
        tmp=m_pTail;
        for(sizet _pos=m_size-1; _pos!=position; _pos--)
            tmp=tmp->m_pPrev;
    }
    return tmp->m_dato;
}

template<typename T>
void double_linked_list<T>::push_front(T &d)
{
    /*if(m_unique)
        if(find_rec(d))
            return;*/

    pNode_T nu = new Node_T (d);
    if(!m_pHead)
    {
        nu->m_pPrev=nu->m_pNext=nu;
        m_pTail=nu;
    }
    else
    {
        nu->m_pNext=m_pHead;
        nu->m_pPrev=m_pTail;

        m_pTail->m_pNext=nu;
        m_pHead->m_pPrev=nu;
    }
    m_pHead=nu;
    m_size++;
}

template<typename T>
void double_linked_list<T>::push_back(T&d)
{
    /*if(m_unique)
    {
        pNode_T* tmp0;
        if(find(d,tmp0))
            return;
        (*tmp0)=new Node_T (d);
        m_size++;
        return;
    }*/

    pNode_T nu = new Node_T (d);
    if(!m_pHead)
    {
        nu->m_pPrev=nu->m_pNext=nu;
        m_pHead=nu;
    }
    else
    {
        nu->m_pNext=m_pHead;
        nu->m_pPrev=m_pTail;

        m_pTail->m_pNext=nu;
        m_pHead->m_pPrev=nu;
    }
    m_pTail=nu;
    m_size++;
}

#endif // DOUBLE_LINKED_LIST_H
