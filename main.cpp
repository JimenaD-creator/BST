#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main(){
    BinaryTree tree;
    //Es lo que va acarreando la dirección de memoria
    tree.root = tree.insert(tree.root, 50); //tree.root es un nullptr
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 70);
    tree.root = tree.insert(tree.root, 90);
    tree.root = tree.insert(tree.root, 100);
    cout << endl << tree.root;

    int valueToSearch = 30;
    Node* result = tree.search(tree.root, valueToSearch);
    cout << endl << result -> data<<endl;
    if (result) {
        cout << "\nNodo encontrado: " << result->data << endl;
    } else {
        cout << "Nodo no encontrado." << endl;
    }



    // Recorridos

    cout << "\n\nIn-Order Traversal: ";
    tree.inOrderTraversal(tree.root);
    cout << endl;
   

    cout << "Pre-Order Traversal: ";
    tree.preOrderTraversal(tree.root);
    cout << endl;

    cout << "Post-Order Traversal: ";
    tree.postOrderTraversal(tree.root);
    cout << endl << endl;

    // Eliminar un nodo
    cout << "\nEliminando nodo 70...\n";
    tree.root = tree.removeNode(tree.root, 70);

    cout << "In-Order Traversal despues de eliminar: ";
    tree.inOrderTraversal(tree.root);
    cout << endl;
}