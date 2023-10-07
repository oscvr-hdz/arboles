#include "declaracion.h"
#include <iostream>
#include <vector>

using namespace std;

Node::Node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

vector<int> Node::lista; 

Node* insert(Node* root, int data)
{
    if (root == nullptr) 
    {
        return new Node(data);
    }
    else 
    {
        if (data == root -> data)
        {
            cout << "El valor " << data << " ya existe" << endl;
        } 
        else if(data > root -> data){
            root -> right = insert(root->right,data);
        } 
        else if(data < root -> data){
            root -> left = insert(root->left, data);
        }
    }
    return root;
}

void preorden(Node* root){
    if (root){
        cout << root->data << endl;
        preorden(root->left);
        preorden(root->right);
    }
}

void postorden(Node* root){
    if (root){
        postorden(root->left);
        postorden(root->right);
        cout << root->data << endl;
    }
}

void simetrico(Node* root){
    if (root){
        simetrico(root -> left);
        cout << root -> data << endl;
        simetrico(root -> right);
    }
}

void lista_simetrica(Node* root){
    if (root){
    	lista_simetrica(root -> left);
    	Node::lista.push_back(root->data);
        lista_simetrica(root -> right);
    }
}

bool busqueda(const vector<int>& array, int item) {
    int longitud = array.size() / 2;

    if (array.size() == 1 && array[0] != item) {
        return false;
    }

    if (array[longitud] == item) {
        return true;
    }

    if (array[longitud] > item) {
        vector<int> nuevoArray(array.begin(), array.begin() + longitud);
        return busqueda(nuevoArray, item);
    }

    if (item > array[longitud]) {
        vector<int> nuevoArray(array.begin() + longitud, array.end());
        return busqueda(nuevoArray, item);
    }

    return false;
}

void Eliminar(Node* &root, int valor) {
    if (root == nullptr) {
        return;
    }

    if (valor < root->data) {
        Eliminar(root->left, valor);
    } else if (valor > root->data) {
        Eliminar(root->right, valor);
    } else {
        // Caso 1: El nodo es una hoja
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        // Caso 2: El nodo tiene un solo hijo
        else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Caso 3: El nodo tiene dos hijos
        else {
            Node* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            root->data = temp->data;
            Eliminar(root->right, temp->data);
        }
        
    }
}
