#include"AVL.h"
#include<iostream>
enum {HEIGHT,INSERT,PREORDER,INORDER,POSTORDER,EXIT};
int main()
{
    int num;
    AVL<int> tree; 
    while (std::cin>>num)
    {
        switch (num)
        {
        case HEIGHT:
            std::cout<<height(tree)<<std::endl;
            break;
        case INSERT:
            std::cout<<"please input a int argv: ";
            int temp;
            while (!std::cin>>temp)
                std::cout<<"\nplease input a int argv: ";
            insert(tree,temp);
            break;
        case PREORDER:
            preorder(tree);
            break;
        case INORDER:
            inorder(tree);
            break;
        case POSTORDER:
            postorder(tree);
            break;
        case EXIT:
            std::cout<<"Bye!\n";
            return 0;
        default:
            std::cout<<"error input"<<std::endl;
            break;
        }
    }
    return 0;
}