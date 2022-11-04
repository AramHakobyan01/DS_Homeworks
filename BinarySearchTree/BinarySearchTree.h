#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE
struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Node(int data, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr) :
            data(data), left(left), right(right), parent(parent) {}
};

class Tree {
public:
    Tree() : head(nullptr) {}
    Node* Search(int);
    void Insert(int);
    void PrintInorder();
    void PrintInorder(Node*);
    Node* DeleteNode(Node*, int);
    void DeleteNode(int);
private:
    Node* head;
};
#endif //BINARYSEARCHTREE
