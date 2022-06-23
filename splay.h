#ifndef SPLAY_H__
#define SPLAY_H__

#include <iostream>
#include <string>
using namespace std;
class SplayTree;

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
        SplayTree(): root(nullptr) {}
        void       insert(int key);
        void       remove(int key);
        SplayNode* find(int key);
        void       print();
        ~SplayTree();
    private:
        void print(SplayNode* node, const std::string& prefix, bool isLeft, std::ostream& out);
        void rotateLeft(SplayNode *node);
        void rotateRight(SplayNode *node);
        void splay(SplayNode *node);
        void deallocateMemory(SplayNode *node);
        SplayNode *root;
}


#endif /* SPLAY_H__ */
