#ifndef ORD_LIST_H
#define ORD_LIST_H

#include "list.h"

template<typename T>
class ord_list : public list<T>
{
    typedef singlePointer_Node<T> Node_T;
    typedef Node_T * pNode_T;

    private:
        void add_rec(T&d,pNode_T &pCurrent);
        bool inner_find(T&d, pNode_T *&pointer);
        bool find_rec(T&d, pNode_T& pCurrent);

        bool comp_eq(T a,T b) const{
            if(m_order==asc)
                return a<=b;
            return a>=b;
        }
        bool comp(T a,T b) const{
            if(m_order==asc)
                return a<b;
            return a>b;
        }

    protected:
        order_class m_order;

    public:
        ord_list(bool unique=0){this->m_pHead=0; this->m_size=0; this->m_unique=unique; m_order=asc;}
        virtual ~ord_list(){}

        inline void setOrder(order_class order);
        void clean();

        inline void add_rec(T&d) {return add_rec(d, this->m_pHead);}
        inline void invert() {if(m_order==asc) setOrder(desc); else setOrder(asc);}
        inline bool find(T&d, pNode_T *&pointer) {pointer=&this->m_pHead; return inner_find(d,pointer);}
        bool find_rec(T&d){pNode_T tmp=this->m_pHead; return find_rec(d,tmp);}
        T* find_max();
        void make_ord_list(list<T>& A, order_class order);
};

template<typename T>
void ord_list<T>::setOrder(order_class order)
{
    if(m_order!=order)
    {
        list<T>::invert();
        m_order=order;
    }
}

template<typename T>
void ord_list<T>::clean()
{
    sizet size=this->m_size;
    for(sizet i=0;i<size;i++)
        this->pop_front();
}

template<typename T>
void ord_list<T>::add_rec(T&d,pNode_T &pCurrent)
{
    if(this->m_unique && pCurrent)
        if(pCurrent->m_dato==d)
            return;

    if(!pCurrent || !comp(pCurrent->m_dato,d)) //pCurrent->dato >= d en caso asc
    {
        pCurrent=new Node_T(d,pCurrent);
        this->m_size++;
        return;
    }
    add_rec(d,pCurrent->m_pNext);
}

template<typename T>
bool ord_list<T>::inner_find(T&d, pNode_T *&pointer)
{
    while(*pointer)
    {
        if((*pointer)->m_dato==d)
            return true;
        if(!comp_eq((*pointer)->m_dato,d))
            return false;
        pointer=&((*pointer)->m_pNext);
    }
    return false;
}

template<typename T>
bool ord_list<T>::find_rec(T&d, pNode_T& pCurrent)
{
    if(!pCurrent)
        return false;
    if(pCurrent->m_dato==d)
        return true;
    if(!comp_eq(pCurrent->m_dato,d))
        return false;
    return find_rec(d, pCurrent->m_pNext);
}

template<typename T>
T* ord_list<T>::find_max()
{
    if(!this->m_pHead) return 0;
    if(m_order==asc)
        return &this->at(this->m_size-1);
    return &this->m_pHead->m_dato;
}

//recibe una lista ordenada, borra todo lo que tiene dentro y copia todos los elementos de A a la actual lista ordenada manteniendo el orden dado
template<typename T>
void ord_list<T>::make_ord_list(list<T>& A, order_class order)
{
    clean();
    this->m_unique=A.m_unique;
    setOrder(order);

    sizet A_size=A.size();
    pNode_T p=A.m_pHead;

    for(sizet i=0; i<A_size; i++)
    {
        add_rec(p->m_dato);
        p=p->m_pNext;
    }
}

#endif // ORD_LIST_H
