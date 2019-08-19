#include "BinarySearchTree.h"

template <typename T>
void BinarySearchTree<T>::Insert(T v)
{

    node<T> *currentNode = this.root;
    while (currentNode != nullptr)
    {
        if (currentNode->value > v)
            currentNode = currentNode->lchild;
        else if (currentNode->value < v)
            currentNode = currentNode->rchild;
        else
            return;
    }

    currentNode = new node<T>(v);
    return;
}