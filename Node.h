#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <memory>

template<typename T>
class Node
{

public:
    Node<T> *pLeft;
    Node<T> *pRight;
    T val;

    Node<T>(T val)
    {
        this->val = val;
        pLeft = pRight = nullptr;
    }

     Node<T>(const Node<T>& src)
     : val(src.val)
     {
         if(src.pLeft)
            pLeft = *src.pLeft;
         if(src.pRight)
            pRight = *src.pRight;
     }
    // Node& operator=(const Node&); -> to be implemented
};


#endif // NODE_H_INCLUDED
