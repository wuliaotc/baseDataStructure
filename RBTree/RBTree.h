#if !defined(RBTREE_H_)
#define RBTREE_H_
enum Color{RED,BLACK};
struct Node
{
    //节点储存的值
    int value;
    //节点颜色
    Color color;
    //父节点 根节点的父节点设为哨兵,所有叶节点叶节点也指向哨兵
    Node * parrent;
    //右子树
    Node * rchild;
    //左子树
    Node * lchild;
    //构造函数
    Node(Color c,struct Node * p,int v):color(c),value(v),parrent(p),rchild(nullptr),lchild(nullptr){}
    Node()=default;
};

class RBTree
{
private:
    
public:
    Node * root;
    Node * nil;
    RBTree();
    void ll_rotation(Node *);
    void rr_rotation(Node *);
    void lr_rotation(Node *);
    void rl_rotation(Node *);
    void insert_Node(Node * node);
    void delete_Node(Node * node);
};

RBTree::RBTree()
{
    root=nullptr;

    nil=new Node();
    nil->color=BLACK;
    nil->lchild=nullptr;
    nil->rchild=nullptr;
    nil->parrent=nullptr;
    // nil->value=
}

#endif // RBTREE_H_
