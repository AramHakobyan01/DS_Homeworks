#include <iostream>

#include "SingleLinkedList.h"

int main() {
    SingleLinkedList list;
    list.Insert(1);
    list.Insert(2);
    list.Insert(3);
    list.Insert(4);
    std::cout << "Elements of the list are: ";
    list.PrintList();
    std::cout << std::endl;
    std::cout << list.Min()->data;
    list.Reverse();
    std::cout << "Reverse: ";
    list.PrintList();
    SingleLinkedList list2;
    list2.Insert(1);
    list2.Insert(2);
    list2.Insert(3);
    list2.Insert(9);
    SingleLinkedList list3;
    list3.Insert(5);
    list3.Insert(6);
    list3.Insert(7);
    list3.Insert(8);
    list2.SortedMarge(list2, list3);
    std::cout << std::endl << std::endl;
    list2.PrintList();
    return 0;
}
