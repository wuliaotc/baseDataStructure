#if !defined(_AVL_TREE_)
#define _AVL_TREE_

template <typename T>
struct AVLnode
{
    T data;
    AVLnode<T> *lchild, *rchild;
};
template <typename T>
class AVL
{
private:
    AVLnode<T> * root;
public:
    //获取(子)树的高度
    int height(AVLnode<T> *);
    
    //获取子树高度差
    int diff(AVLnode<T> *);
    AVLnode<T> *rr_rotation(AVLnode<T> *);
    AVLnode<T> *ll_rotation(AVLnode<T> *);
    AVLnode<T> *lr_rotation(AVLnode<T> *);
    AVLnode<T> *rl_rotation(AVLnode<T> *);
    AVLnode<T> *balance(AVLnode<T> *);
    AVLnode<T> *insert(AVLnode<T> *, T);
    
    // void display(AVLnode<T> *, int d);
    void inorder(AVLnode<T> *);
    void preorder(AVLnode<T> *);
    void postorder(AVLnode<T> *);
    AVL()
    {
        root=nullptr;
    }
    friend void inorder(AVL<T> &);
    friend void preorder(AVL<T> &);
    friend void postorder(AVL<T> &);
    friend AVLnode<T> *insert(AVL<T> &,T v);
    friend int height(AVL<T> &);
};

#endif // _AVL_TREE_
