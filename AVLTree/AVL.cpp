#include "AVL.h"

//获取树的高度
template <typename T>
int AVL<T>::height(AVLnode<T> *node)
{
    int h = 0;
    if (node != nullptr)
    {
        int lh = height(node->lchild);
        int rh = height(node->rchild);

        h = std::max(lh, rh) + 1;
    }
    return h;
}
//获取左右子树的高度差
template <typename T>
int AVL<T>::diff(AVLnode<T> *node)
{
    int lh = height(node->lchild);
    int rh = height(node->rchild);

    return lh - rh;
}
//rr旋转 parent指定是平衡因子失衡的节点
//返回调整后的子树的根
template <typename T>
AVLnode<T> *AVL<T>::rr_rotation(AVLnode<T> *parent)
{
    // avl *t;
    // t = parent->r;

    // parent->r = t->l;
    // t->l = parent;
    // cout << "Right-Right Rotation";
    // return t;

    //比如
    /*
        ----2----
        |       |
        1       3---- -2 parrent          ----4----
                    |                     |        |
                    4----  -1 node        3        5
                        |
                        5   0
    */
    //失衡节点
    AVLnode<T> *node = parent->rchild;

    //这条不太懂 为什么不是 parent->rchild=nullptr
    /*
        当平衡因子被打破的节点距离插入的节点并非为2时(即不接近),会出现
        parent-rchild需要挂上node->left的情况
    */
    parent->rchild=node->lchild;
    node->lchild=parent;
    return node;
}
//ll旋转 parent指定是平衡因子失衡的节点
//返回调整后的子树的根
template <typename T>
AVLnode<T> *AVL<T>::ll_rotation(AVLnode<T> *parent)
{
    AVLnode<T> * node=parent->lchild;

    //同rr,这里不太懂
    parent->lchild=node->rchild;
    node->rchild=parent;
    return node;
}
//lr旋转 parent指定是平衡因子失衡的节点
//先右旋后左旋
//返回调整后的子树的根
template <typename T>
AVLnode<T> *AVL<T>::lr_rotation(AVLnode<T> *parent)
{
    AVLnode<T> * node=parent->lchild;
    parent->lchild=rr_rotation(node);
    return ll_rotation(parent);
}
template <typename T>
AVLnode<T> *AVL<T>::rl_rotation(AVLnode<T> *parent)
{
    AVLnode<T> * node=parent->rchild;
    parent->rchild=rr_rotation(node);
    return ll_rotation(parent);
}
//调整平衡
template<typename T>
AVLnode<T> *AVL<T>::balance(AVLnode<T> *node)
{
    int bal_factor=diff(node);
    if (bal_factor>1)//左子树导致不平衡
    {
        //这里为什么要用>0而不是==1
        if (diff(node->lchild)==1)//ll,左旋
            return ll_rotation(node);
        else//lr 先右旋后左旋
            return lr_rotation(node);
    }
    else if (bal_factor<-1)//右子树导致不平衡
    {
        //同上
        if (diff(node->rchild)==-1)//rr
            return rr_rotation(node);
        else
            return rl_rotation(node);
    } 
    return node;//如果已经平衡了,返回当前节点 表示该节点已平衡不需要检查
}
//向树中插入v
template<typename T>
AVLnode<T> *insert(AVLnode<T> * t, T v)
{
    //树为空,需要构造
    if(t==nullptr)
    {
        t=new AVLnode<T>;
        t->lchild=nullptr;
        t->rchild=nullptr;
        t->data=v;
        return t;
    }
    else if (v<t->data)
    {
        t->lchild=insert(t->lchild,v);
        //调整平衡
        t=balance(t);
    }
    //大于等于意味着该树允许储存多个相同值
    else if (v>=t->rchild)
    {
        t->lchild=insert(t->rchild,v);
        balance(t);
    }
    return t;
}