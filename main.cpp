#include <iostream>
#include <string>

using namespace std;

#include "splay.h"

// Testa algumas funções da arvore de busca.
int main()
{
    // Cria um SplayTree vazia
    SplayTree splayTree;

    // Insere alguns elementos
    splayTree.insert(10);
    splayTree.insert(20);
    splayTree.insert(30);
    //splayTree.insert(5);
    //splayTree.insert(15);
    //splayTree.insert(25);
    //splayTree.insert(35);
    //splayTree.insert(1);

    // Imprime a arvore
    splayTree.print_tree();

    // Busca por um nó  
    SplayNode* node = splayTree.find(20);
    if (node == nullptr)
    {
        cout << "Node not found" << endl;
        return 0;
    }
    
    // Aplica rotação a direita
    SplayNode* r = splayTree.rotateLeft(node);
    cout <<" r->key = " << r->getKey() << endl;
    if(r->getParent() != nullptr)
        cout << "Rotate left: " << r->getKey() << " " << r->getParent()->getKey() << endl;
        
    // Imprime a arvore
    splayTree.print_tree();

    // Busca por um nó  
    /*
    node = splayTree.find(5);
    if (node == nullptr)
    {
        cout << "Node not found" << endl;
        return 0;
    }
    */

    //Aplica rotação a direita
    //splayTree.rotateLeft(node);
        
    // Imprime a arvore
    //splayTree.print_tree();
    splayTree.print_in_order();

    return 0;
}
