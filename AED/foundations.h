#ifndef FOUNDATIONS_H
#define FOUNDATIONS_H

#include <iostream>

typedef size_t sizet;

enum order_class{asc,desc};

/** Basic Node Class with just one pointer to next Node */
template <typename T>
class singlePointer_Node
{
    public:
        T m_dato;
        singlePointer_Node<T> * m_pNext;

    public:
        singlePointer_Node(T&d) : m_dato(d), m_pNext(0) {}
        singlePointer_Node(T&d, singlePointer_Node<T> * next) : m_dato(d), m_pNext(next) {}
        virtual ~singlePointer_Node(){}
};

/** Node Class with two pointers */
template <typename T>
class doublePointer_Node
{
    public:
        T m_dato;
        doublePointer_Node<T> * m_pPrev;
        doublePointer_Node<T> * m_pNext;

    public:
        doublePointer_Node(T&d) : m_dato(d), m_pPrev(0), m_pNext(0) {}
        doublePointer_Node(T&d, doublePointer_Node<T> * prev, doublePointer_Node<T> * next) : m_dato(d), m_pPrev(prev), m_pNext(next) {}
        virtual ~doublePointer_Node(){}
};

#endif // FOUNDATIONS_H
