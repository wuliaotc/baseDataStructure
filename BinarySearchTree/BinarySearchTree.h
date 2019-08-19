#if !defined(_BINARY_SEARCH_TREE_)
#define _BINARY_SEARCH_TREE_

#include "baseBinarySearchTree.h"

template <typename T>
class BinarySearchTree : public BST<T>
{
private:

public:
    BinarySearchTree()=default;
    ~BinarySearchTree();
    virtual node<T>& Search(T);
    void Insert(T v);
    virtual void Delete(T);
};



#endif // _BINARY_SEARCH_TREE_