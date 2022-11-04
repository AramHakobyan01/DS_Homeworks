#ifndef SINGLELINKEDLIST
#define SINGLELINKEDLIST

#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node();
    explicit Node(int data);
};

class SingleLinkedList {
    Node* head;
public:
    SingleLinkedList() { head = nullptr; }
    void Insert(int);
    void PrintList();
    bool Empty();
    Node* Min();
    void Reverse();
    void SortedMarge(SingleLinkedList, SingleLinkedList);
private:
    Node* HalperToMarde(Node*, Node*);
};

#endif //SINGLELINKEDLIST
