#include "declaracion.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    Node* root = nullptr;
    int nodos;
    int elemento;
    int orden;
    int decision;
    int elementoBuscar;
    
    do {
        cout << "¿Cuantos nodos tendra tu arbol? ";
        cin >> nodos;
        for(int i = 0; i < nodos; i++){
            cout << "ingresa el elemento: ";
            cin >> elemento;
            root = insert(root, elemento);
        }
	lista_simetrica(root);
        do {
            cout << "¿Que deseas hacer? (ingresa el numero correspondiente al orden)" << endl;
            cout << "1 - Recorrer el arbol" << endl;
            cout << "2 - Buscar un elemento en el arbol" << endl;
            cout << "3 - Eliminar un elemento del arbol" << endl;
            cout << "4 - Salir" << endl;
            cin >> decision;

            switch (decision) {
                case 1:
                    cout << "¿En que recorrido quieres que se muestre el arbol? (ingresa el numero correspondiente al orden)" << endl;
                    cout << "1 - Preorden" << endl;
                    cout << "2 - Postorden" << endl;
                    cout << "3 - Simetrico" << endl;
                    cin >> orden;

                    switch (orden) {
                        case 1:
                            cout << "Preorden:" << endl;
                            preorden(root);
                            break;
                        case 2:
                            cout << "Postorden:" << endl;
                            postorden(root);
                            break;
                        case 3:
                            cout << "Simétrico:" << endl;
                            simetrico(root);
                            break;
                        default:
                            cout << "Ingresa un valor valido." << endl;
                    }
                    break;
                case 2:
                    
                    cout << "Elemento a buscar: ";
                    cin >> elementoBuscar;
                    if (busqueda(Node::lista, elementoBuscar)){
                        cout << "El elemento " << elementoBuscar << " está en el árbol." << endl;
                    }else{
                        cout << "El elemento " << elementoBuscar << " no está en el árbol." << endl;
                    }
                    break;
                case 3:
                    
                    int valorEliminar;
                    cout << "Elemento a eliminar: ";
                    cin >> valorEliminar;
                    if (busqueda(Node::lista, valorEliminar)){
                    	Eliminar(root, valorEliminar);
                    	for(auto it = Node::lista.begin(); it != Node::lista.end(); ++it) {
    				if (*it == valorEliminar) {
        				Node::lista.erase(it);
        				break;
    			}
    		    }
                    	cout << "Elemento eliminado." << endl;
                    	break;
                    } else {
                    	cout << valorEliminar << " no existe" << endl;
                    
                    }
                case 4:
                    break;
                default:
                    cout << "Ingresa un valor valido." << endl;
            }
        } while (decision != 4);

        Node::lista.clear();

        cout << "¿Deseas realizar otra operación? (1 para sí, 0 para no): ";
        cin >> decision;
    } while (decision == 1);

    return 0;
}
