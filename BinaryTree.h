struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value);
};

class BinaryTree{
    public:
    Node* root;

    //Constructor
    BinaryTree();

    Node* insert(Node* node, int value);
    //Recorrido
    Node* search(Node* node, int value);
    //void preorder(Node* node);

    Node* removeNode(Node* node, int value);
    Node* findMin(Node* node); //Encontrar el valor mínimo del árbol
    void inOrderTraversal(Node* node);
    void preOrderTraversal(Node* node);
    void postOrderTraversal(Node* node);


};