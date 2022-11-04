#include "SingleLinkedList.h"

Node::Node() {
    data = 0;
    next = nullptr;
}

Node::Node(int data) {
    this->data = data;
    this->next = nullptr;
}

void SingleLinkedList::Insert(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void SingleLinkedList::PrintList() {
    Node* temp = head;
    if (head == nullptr) {
        std::cout << "List empty" << std::endl;
        return;
    }
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

bool SingleLinkedList::Empty() {
    if (head == nullptr) {
        return true;
    }
    return false;
}

Node* SingleLinkedList::Min() {
    Node* min = head;
    Node* temp = head;
    while (temp->next != nullptr) {
        if(temp->next->data <= min->data) {
            min = min->next;
        }
        temp = temp->next;
    }
    return min;
}

void SingleLinkedList::Reverse() {
    Node* current = head;
    Node* temp;
    Node* temp2 = nullptr;
    while (current != nullptr) {
        temp = current->next;
        current->next = temp2;
        temp2 = current;
        current = temp;
    }
    head = temp2;
}

void SingleLinkedList::SortedMarge(SingleLinkedList a, SingleLinkedList b) {
    head = HalperToMarde(a.head, b.head);
}

Node* SingleLinkedList::HalperToMarde(Node* a, Node* b) {
    Node* result = nullptr;
    if (a == nullptr) {
        return b;
    }
    else if (b == nullptr) {
        return a;
    }
    if (a->data <= b->data) {
        result = a;
        result->next = HalperToMarde(a->next, b);
    } else {
        result = b;
        result->next = HalperToMarde(a, b->next);
    }
    return result;
}