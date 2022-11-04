#include "BinarySearchTree.h"

#include <iostream>

Node *Tree::Search(int elem) {
    Node *temp = this->head;
    while (temp != nullptr) {
        if (temp->data == elem) {
            return temp;
        }
        if (elem < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->left;
        }
    }
    return nullptr;
}

void Tree::Insert(int elem) {
    Node *temp = this->head;
    Node *current = nullptr;
    while (temp != nullptr) {
        current = temp;
        if (elem < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    temp = new Node(elem, current);
    if (current == nullptr) {
        this->head = temp;
    } else {
        if (elem < current->data) {
            current->left = temp;
        } else {
            current->right = temp;
        }
    }
}

void Tree::PrintInorder(Node *node) {
    if (node == nullptr) {
        return;
    }
    PrintInorder(node->left);
    std::cout << node->data << " ";
    PrintInorder(node->right);
}

void Tree::PrintInorder() {
    PrintInorder(this->head);
}

Node *Tree::DeleteNode(Node *root, int k) {
    if (root == nullptr) {
        return root;
    }
    if (root->data > k) {
        root->left = DeleteNode(root->left, k);
        return root;
    } else if (root->data < k) {
        root->right = DeleteNode(root->right, k);
        return root;
    }
    if (root->left == nullptr) {
        Node *temp = root->right;
        delete root;
        return temp;
    } else if (root->right == nullptr) {
        Node *temp = root->left;
        delete root;
        return temp;
    } else {
        Node *succParent = root;
        Node *succ = root->right;
        while (succ->left != nullptr) {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        root->data = succ->data;
        delete succ;
        return root;
    }
}

void Tree::DeleteNode(int k) {
    head = DeleteNode(this->head, k);
}
