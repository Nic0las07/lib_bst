#include <iostream>
#include "BST.h"

int main()
{
    Node* root = new Node(25);
    root->insertR_ite(15);
    root = root->insertR(50);
    root = root->insertR(10);
    root->insertR_ite(22);
    root = root->insertR(35);
    root->insertR_ite(70);
    root = root->insertR(4);
    root = root->insertR(12);
    root->insertR_ite(18);
    root = root->insertR(24);
    root = root->insertR(31);
    root->insertR_ite(44);
    root->insertR_ite(66);
    root = root->insertR(90);

    std::cout << root->findValue(45) << std::endl;

    root = root->nodeEraser(35);
    root = root->nodeEraser(4);
    root = root->nodeEraser(31);
    root = root->nodeEraser(25);

    root->inOrder();
    std::cout << std::endl;
    root->preOrder();
    std::cout << std::endl;
    root->postOrder();

    std::cout << std::endl << root->BST_height();

    std::cout << std::endl << root->isBst();
    
    return 0;
}