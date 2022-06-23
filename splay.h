#ifndef SPLAY_H__
#define SPLAY_H__

#include <iostream>
#include <string>
using namespace std;

class SplayTree;

// Implementa as estruturas de dados necessarias para o splay tree

class SplayNode
{
    friend class SplayTree;
    public:
        SplayNode(int key);
        SplayNode(int key, SplayNode *left, SplayNode *right);
        SplayNode* getLeft();
        SplayNode* getRight();
        SplayNode* getParent();
        int        getKey();
        void setLeft(SplayNode *left);
        void setRight(SplayNode *right);
        void setKey(int key);
        void setParent(SplayNode *parent);
        
  private:
    int key;
    SplayNode *left;
    SplayNode *right;
    SplayNode *parent;
};

class SplayTree
{   

    public:
        SplayTree();
        void       insert(int key);
        void       remove(int key);
        SplayNode*  max();
        SplayNode*  min();
        SplayNode* find(int key);
        void       print();
        ~SplayTree();
    private:
        // Funções auxiliares
        void print(SplayNode* node, const std::string& prefix, bool isLeft, std::ostream& out);
        void rotateLeft(SplayNode *node);
        void rotateRight(SplayNode *node);
        void splay(SplayNode *node);
        void deallocateMemory(SplayNode *node);

        // Ponteiro para o no raiz da arvore
        SplayNode *root;
};


#endif /* SPLAY_H__ */
