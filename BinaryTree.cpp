#include <iostream>
#include "BinaryTree.h"
using namespace std;

//(*node).data acceder valor del nodo
Node::Node(int value){
    data = value;
    left = nullptr;
    right = nullptr;
}
BinaryTree::BinaryTree(){
    root = nullptr;
}
//Puntero inicializado como una estructura
Node* BinaryTree::insert(Node* node, int value){
    if(node == nullptr){
        return new Node(value); //node = 50
    }
    if(value < node->data){
        node->left = insert(node->left, value);
    }else{
        node->right = insert(node->right, value);
    }
    return node; //Regresa todo el árbol

}
Node* BinaryTree::search(Node* node, int value){
    if(node == nullptr || node->data == value){
        return node; //Nodo encontrado o no existe
    }
    if(value < node->data){
        return search(node->left, value);
    }else{
        return search(node->right, value);
    }
}
// Encontrar el nodo con el valor mínimo (sucesor in-order)
Node* BinaryTree::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}
Node* BinaryTree::removeNode(Node* node, int value){
    if (node == nullptr) {
        return node; // El árbol está vacío o no se encontró el nodo
    }

    // Recorrer el árbol para encontrar el nodo a eliminar
    if (value < node->data) {
        node->left = removeNode(node->left, value);
    } else if (value > node->data) {
        node->right = removeNode(node->right, value);
    } else {  // Nodo encontrado
        // Caso 1: Nodo sin hijos (hoja)
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        // Caso 2: Nodo con un solo hijo
        else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        // Caso 3: Nodo con dos hijos
        else {
            Node* successor = findMin(node->right); // Sucesor in-order
            node->data = successor->data; // Reemplazar el valor
            node->right = removeNode(node->right, successor->data); // Eliminar sucesor
        }
    }
    return node;


}
// In-Order: Izquierdo → Raíz → Derecho
void BinaryTree::inOrderTraversal(Node* node) {
    if (node == nullptr) return;
    inOrderTraversal(node->left);
    cout << node->data << " ";
    inOrderTraversal(node->right);
}

// Pre-Order: Raíz → Izquierdo → Derecho
void BinaryTree::preOrderTraversal(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

// Post-Order: Izquierdo → Derecho → Raíz
void BinaryTree::postOrderTraversal(Node* node) {
    if (node == nullptr) return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->data << " ";
}
