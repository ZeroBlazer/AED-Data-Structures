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

        //comp -> asc (<) , desc (>)
        bool comp_eq(T a,T b) const{
            if(m_order)
                return a<=b;
            return a>=b;
        }
        bool comp(T a,T b) const{
            if(m_order)
                return a<b;
            return a>b;
        }

    protected:
        bool m_order; //1 asc, 0 desc

    public:
        ord_list(bool unique=0){this->m_pHead=0; this->m_size=0; this->m_unique=unique; m_order=1;}
        virtual ~ord_list(){}

        inline void setOrder(bool order){if(m_order!=order) {list<T>::invert(); m_order=order;}}
        inline void add_rec(T&d){return add_rec(d, this->m_pHead);}
        inline void invert(){setOrder(!m_order);}
        inline bool find(T&d, pNode_T *&pointer) {pointer=&this->m_pHead; return inner_find(d,pointer);}
};

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

void add

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



#endif // ORD_LIST_H
