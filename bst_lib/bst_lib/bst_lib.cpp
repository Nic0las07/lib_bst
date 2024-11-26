#include <iostream>
#include "BST.h"

int main()
{
    Node* root = new Node(25);
    root->insertR(15);
    root->insertR(50);
    root->insertR(10);
    root->insertR(22);
    root->insertR(35);
    root->insertR(70);
    root->insertR(4);
    root->insertR(12);
    root->insertR(18);
    root = root->insertI(24);
    root = root->insertI(31);
    root->insertR(44);
    root->insertR(66);
    root = root->insertI(90);

    std::cout << root->searchI(45) << std::endl;
    std::cout << root->searchI(44) << std::endl;

    root = root->deleteNode(35);
    root = root->deleteNode(4);
    root = root->deleteNode(31);
    root = root->deleteNode(25);

    root->inOrder();
    std::cout << std::endl;
    root->preOrder();
    std::cout << std::endl;
    root->postOrder();

    std::cout << std::endl << root->BST_height();

    std::cout << std::endl << root->isBst();
    
    return 0;
}