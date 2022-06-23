#include <iostream>
#include <string>

using namespace std;

#include "splay.h"

int main()
{
    SplayTree splayTree;
    splayTree.insert(20);
    splayTree.insert(10);
    splayTree.insert(30);
    splayTree.insert(5);
    splayTree.insert(15);
    splayTree.insert(25);
    splayTree.insert(35);
    splayTree.insert(1);

    splayTree.print();

    SplayNode* node = splayTree.find(10);
    if (node == nullptr)
    {
        cout << "Node not found" << endl;
    }
    return 0;
    
}
