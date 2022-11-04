#include <iostream>

#include "BinarySearchTree.h"

int main() {
    Tree tree;
    tree.Insert(60);
    tree.Insert(20);
    tree.Insert(15);
    tree.Insert(30);
    tree.Insert(35);
    tree.Insert(50);
    tree.Insert(90);
    tree.PrintInorder();
    tree.DeleteNode(35);
    std::cout << std::endl;
    tree.PrintInorder();
    return 0;
}
