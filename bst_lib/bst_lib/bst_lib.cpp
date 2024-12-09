#include <iostream>
#include "BST.h"

int main()
{
    Node* root;
    std::cin >> root;

    root = root->insertR(15);
    root = root->insertI(50);
    root = root->insertR(10);
    root = root->insertI(22);
    root = root->insertR(35);
    root = root->insertR(70);
    root = root->insertI(4);
    root = root->insertR(12);
    root = root->insertI(18);
    root = root->insertR(24);
    root = root->insertI(31);
    root = root->insertR(44);
    root = root->insertI(66);
    root = root->insertR(90);

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

    std::cout << '\n' << '\n' << '\n' << '\n';

    std::cout << * root  << * root << * root;

    std::cout << '\n' << '\n' << '\n' << '\n';
    
    return 0;
}