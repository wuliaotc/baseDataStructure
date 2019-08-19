#if !defined(_BASE_BINARY_SEARCH_TREE_)
#define _BASE_BINARY_SEARCH_TREE_

template <typename T>
struct node
{
    T value;
    node<T> *lchild, *rchild;
    node(T value = {}) : value(value), lchild(nullptr), rchild(nullptr) {}
};

template <typename T>
class BST
{
private:
    node<T> *root;
    void DeleteTree();
public : 
    BST() : root(nullptr){};
    bool empty(){return root == nullptr;};
    node<T> *Root()const{return root;} ;
    virtual void Insert(T)= 0;
    virtual void Delete(T)= 0;
    virtual node<T> & Search(T);
};
template <typename T>
node<T>& BST<T>::Search(T v)
{
    node<T> * currentNode=root;
    while (currentNode != nullptr)
    {
        if (currentNode->value > v)
            currentNode = currentNode->lchild;
        else if (currentNode->value < v)
            currentNode = currentNode->rchild;
        else
            return currentNode;
    }
    return (node<T>&)nullptr;
    
}
#endif // _BASE_BINARY_SEARCH_TREE_
