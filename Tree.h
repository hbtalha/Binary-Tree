#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <iostream>
#include <utility>
#include "Node.h"

template<typename T>
class BinaryTree
{
    Node<T>* root;
    Node<T>* insertAtSub(T i, Node<T>*) const;
    Node<T>* deleteAtSub(T i, Node<T>*) const;
    int countNodes(Node<T> *p) ;
    void printSub(Node<T> *p) const;
    bool containSub(T i, Node<T>*) const;
    Node<T>* minValue(Node<T>*) const;
    Node<T>* maxValue(Node<T>*) const;
    Node<T>* _getLast(Node<T>*) const;
    Node<T>* _getFirst(Node<T>*) const;
    void deallocate(Node<T>*) const;
    int nodes = 0;

public:
    BinaryTree ()
    {
        root = nullptr;
    }

    ~BinaryTree()
    {
        // deallocate(root);
    }

    void insert(T i)
    {
        root = insertAtSub(i, root);
    }
    void print()
    {
        printSub(root);
    };

    bool find(T i)
    {
        return containSub(i, root);
    }

    void erase(T i)
    {
        if(find(i))
            root = deleteAtSub(i, root);
        else
            return;
    }

    void test() const
    {
        //deallocate(root);
        //   std::cout << root->pLeft->val << std::endl;

        //std::cout << root->pRight->pRight->pRight->pLeft->pRight->val << endl;
    }

    void showFirst() const;
    void showLast() const;

    int size()
    {
        nodes = 0;
        countNodes(root);
        return nodes + 1;
    }

    int getNumberLeftNodes()
    {
        nodes = 0;
        countNodes(root->pLeft);
        return nodes + 1;
    }

    int getNumberRightNodes()
    {
        nodes = 0;
        countNodes(root->pRight);
        return nodes + 1;
    }
};

template<typename T>
void BinaryTree<T>::deallocate(Node<T> *p) const
{
    while(1)
    {
        if(p == nullptr)
        {
            break;
        }
        else if(p->pLeft != nullptr)
        {
            deallocate(p->pLeft);
            p->pLeft = nullptr;
        }
        else if(p->pRight != nullptr)
        {
            deallocate(p->pRight);
            p->pRight = nullptr;
        }
        else
        {
            free(p);
            return;
        }
    }
}

template<typename T>
int  BinaryTree<T>::countNodes(Node<T> *p)
{
    if(!p)
        return 0;
    if (p->pLeft)
    {
        ++nodes;
        countNodes(p->pLeft);
    }
    if (p->pRight)
    {
        ++nodes;
        countNodes(p->pRight);
    }

    return nodes;
}

template<typename T>
Node<T>* BinaryTree<T>::insertAtSub(T i, Node<T> *p) const
{
    if( ! p )
        return new Node<T>(i);
    else if (i < p->val)
        p->pLeft = insertAtSub(i, p->pLeft);
    else if (i > p->val)
        p->pRight = insertAtSub(i, p->pRight);

    p->pRight->pLeft ;


    return p;
}

template<typename T>
void BinaryTree<T>::printSub(Node<T> *p) const
{
    if(p)
    {
        printSub(p->pLeft);
        std::cout << p->val << std::endl;
        printSub(p->pRight);
    }
}

template<typename T>
bool BinaryTree<T>::containSub(T i, Node<T> *p) const
{
    if (!p)
        return false;
    else if(i == p->val)
        return true;
    else if (i <= p->val)
        containSub(i, p->pLeft);
    else
        containSub(i, p->pRight);
}

template<typename T>
Node<T> *BinaryTree<T>::minValue(Node<T> *p) const
{
    Node<T> *current = p;

    while(current && current->pLeft)
        current = current->pLeft;

    return current;
}

template<typename T>
Node<T> *BinaryTree<T>::maxValue(Node<T> *p) const
{
    Node<T> *current = p;

    while(current && current->pRight)
        current = current->pRight;

    return current;
}

template<typename T>
void BinaryTree<T>::showLast() const
{
    Node<T> *last = maxValue(root);

    if(last)
        std::cout << last->val;
    else
        std::cout << "";
}

template<typename T>
void BinaryTree<T>::showFirst() const
{
    Node<T> *first = minValue(root);

    if(first)
        std::cout << first->val;
    else
        std::cout << "";
}

template<typename T>
Node<T>* BinaryTree<T>::deleteAtSub(T i, Node<T>* p) const
{
    if (i < p->val)
        p->pLeft = deleteAtSub(i, p->pLeft);
    else if (i > p->val)
        p->pRight = deleteAtSub(i, p->pRight);
    else if(i == p->val)
    {
        if ( ! p->pLeft)
        {
            Node<T> *temp = p->pRight;
            delete p;

            return temp;
        }
        else if ( ! p->pRight)
        {
            Node<T> *temp = p->pLeft;
            delete p;

            return temp;
        }

        Node<T> *temp = minValue(p->pRight);

        p->val = temp->val;

        p->pRight = deleteAtSub(p->val, p->pRight);
    }

    return p;
}


/*
template<typename T>
Node<T>* BinaryTree<T>::_getLast(Node<T> *p)
{
    if( !p )
        return p;

    Node<T> *maxLeft = maxValue(p);
    Node<T> *maxRight = maxValue(p);

    if ( ! maxLeft && ! maxRight)
        return p;
    else if ( ! maxLeft)
        return maxRight;
    else if ( ! maxRight)
        return maxLeft;

    Node<T> *last = maxLeft;

    if(maxLeft->val < maxRight->val)
        last = maxRight;

    return last;
}

template<typename T>
Node<T>* BinaryTree<T>::_getFirst(Node<T> *p)
{
    if( !p )
        return p;

    Node<T> *minLeft = minValue(p);
    Node<T> *minRight = minValue(p);

    if( ! minLeft && ! minRight)
        return p;
    else if ( ! minLeft)
        return minRight;
    else if ( ! minRight)
        return minLeft;

    Node<T> *first = minLeft;

    if(minLeft->val > minRight->val)
        first = minRight;

    return first;
}
*/

#endif // TREE_H_INCLUDED
