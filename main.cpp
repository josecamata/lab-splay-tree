#include <iostream>
#include <string>

using namespace std;

#include "splay.h"

// Testa algumas funções da arvore de busca.
int main()
{
    int array[] = {10, 20, 30, 5, 15};
    int size = sizeof(array)/sizeof(array[0]);

    // Cria um SplayTree vazia
    SplayTree<int> splayTree;

    for(int i = 0; i < size; i++) {
        std::cout << "Inserting " << array[i] << std::endl;
        splayTree.insert(array[i]);
        std::cout << "Tree after inserting " << array[i] << std::endl;
        splayTree.print_tree();

    }

    std::cout << "Tree after splaying 20" << std::endl;
    // Busca por um nó  
    auto node = splayTree.find(20);
    if (node == nullptr)
    {
        cout << "Node not found" << endl;
        return 0;
    }
    // Imprime a arvore
    splayTree.print_tree();

    // Busca por um nó   
    std::cout << "Tree after splaying 5" << std::endl;
    node = splayTree.find(5);
    if (node == nullptr)
    {
        cout << "Node not found" << endl;
        return 0;
    }

    // Imprime a arvore
    splayTree.print_in_order();


    // Remove um nó
    splayTree.remove(15);

    std::cout << "Tree after removing 15" << std::endl;
    splayTree.print_tree();


    return 0;
}
