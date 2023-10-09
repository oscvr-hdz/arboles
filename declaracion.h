#ifndef DECLARACION_H
#define DECLARACION_H

#include <vector>

class Node 
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data);
    static std::vector<int> lista; 
};

Node* insert(Node* root, int data);
void preorden(Node* root);
void postorden(Node* root);
void simetrico(Node* root);
void lista_simetrica(Node* root);
bool busqueda(const std::vector<int>& array, int item);
void Eliminar(Node* &root, int valor);

#endif
