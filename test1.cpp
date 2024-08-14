

#include <iostream>
#include <string>

using namespace std;

#include "splay.h"

// Testa inserção

int main()
{
    int array[] = {10, 2, 20, 34 , 30, 5, 33, 15};
    int size = sizeof(array)/sizeof(array[0]);

    // Cria um SplayTree vazia
    SplayTree<int> splayTree;

    for(int i = 0; i < size; i++) {
        splayTree.insert(array[i]);
    }

   splayTree.print_tree();
   auto key = splayTree.get_root_key();
   if(key != 15)
       return -1;

   return 0; 
}