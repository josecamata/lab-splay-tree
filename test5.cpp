
#include <iostream>
#include <string>

using namespace std;

#include "splay.h"

int main()
{
    int array[] = {10, 2, 20, 34 };
    int size = sizeof(array)/sizeof(array[0]);

    // Cria um SplayTree vazia
    SplayTree<int> splayTree;

    for(int i = 0; i < size; i++) {
        splayTree.insert(array[i]);
    }
        
    splayTree.print_tree();

    for(int i = 0; i < size; i++) {
        splayTree.remove(array[i]);
        splayTree.print_tree();
    }

    if(splayTree.is_empty() == false)
        return -1;

   return 0; 
}