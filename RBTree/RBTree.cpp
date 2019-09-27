#include"RBTree.h"

void RBTree::rr_rotation(Node * oldParrent)
{
    
    Node * newParrent=oldParrent->rchild;

    oldParrent->rchild=newParrent->lchild;
    if(newParrent->lchild!=nil)
        newParrent->lchild->parrent=oldParrent;
    newParrent->parrent=oldParrent->parrent;

    if(oldParrent->parrent==nil)
        root=newParrent;
    else if(oldParrent==oldParrent->parrent->lchild)
        oldParrent->parrent->lchild=newParrent;
    else oldParrent->parrent->rchild=newParrent;

    newParrent->lchild=oldParrent;
    oldParrent->parrent=newParrent;

    newParrent->parrent=oldParrent->parrent;
    oldParrent->parrent=newParrent;
    oldParrent->rchild->parrent=oldParrent;
}