#include "splay.h"
/*
    Implement the SplayNode class
 */
SplayNode::SplayNode(int key): key(key), left(nullptr), right(nullptr), parent(nullptr)
{ }

SplayNode::SplayNode(int key, SplayNode *left, SplayNode *right): key(key), left(left), right(right), parent(nullptr)
{ }

int SplayNode::getKey()
{
    return key;
}

SplayNode* SplayNode::getLeft()
{
    return left;
}

SplayNode* SplayNode::getRight()
{
    return right;
}

SplayNode* SplayNode::getParent()
{
    return parent;
}

void SplayNode::setLeft(SplayNode *left)
{
    this->left = left;
}

void SplayNode::setRight(SplayNode *right)
{
    this->right = right;
}

void SplayNode::setParent(SplayNode *parent)
{
    this->parent = parent;
}

void SplayNode::setKey(int key)
{
    this->key = key;
}

/*
   Implement the SplayNode class
*/

// Cria um SplayTree vazia
SplayTree::SplayTree(): root(nullptr)
{ }

// Implementação da rotina de Rotação à Esquerda
/*
       Y                             X     
      / \        rotate left        / \    
     X   ^      <------------      ^   Y   
    / \ /C\                       /A\ / \  
   ^  ^                               ^  ^ 
  /A\/B\                             /B\/C\
  */
void SplayTree::rotateLeft(SplayNode *x)
{
    SplayNode *y = x->right;
    if(y == nullptr)
        return;
    x->right = y->left;
    if (y->left != nullptr)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;   
}

/*
    Implementação da rotina de Rotação à Direita
       Y                             X     
      / \                           / \    
     X   ^                         ^   Y   
    / \ /C\                       /A\ / \  
   ^  ^         ------------>         ^  ^ 
  /A\/B\         rotate right        /B\/C\

*/ 
void SplayTree::rotateRight(SplayNode *y)
{
    SplayNode *x = y->left;
    if(x == nullptr)
        return;
    y->left = x->right;
    if (x->right != nullptr)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == nullptr)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;  
    x->right = y;
    y->parent = x;
}

// Implemente a rotina de splay. 
// O parâmetro node é o nó que deve ser splayado.
void SplayTree::splay(SplayNode *node)
{
    
}

SplayNode* SplayTree::find(int key)
{
    SplayNode *node = root;
    SplayNode *parent = nullptr;
    while (node != nullptr && node->key != key)
    {
        parent = node;
        if (key < node->key)
            node = node->left;
        else
            node = node->right;
    }
    // TODO: chame a rotina de splay para o no encontrado a raiz. 
    //       Se no for null, eleve o pai.
    return node;
}

void SplayTree::insert(int key)
{
    SplayNode *node = new SplayNode(key);
    SplayNode *x    = root;
    SplayNode *y    = nullptr;
    while(x != nullptr)
    {
        y = x;
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    node->parent = y;
    if (y == nullptr)
        root = node;
    else if (key < y->key)
        y->left = node;
    else
        y->right = node;

    // TODO: chame a rotina de splay para elevar o node ao nível da raiz
}

// Retorna o nó que contem a maior chave
SplayNode* SplayTree::max()
{
    SplayNode *node = root;
    if(node == nullptr)
        return nullptr;
    while (node->right != nullptr)
        node = node->right;
    return node;
}

// Retorna o nó que contem a menor chave
SplayNode* SplayTree::min()
{
    SplayNode *node = root;
    if(node == nullptr)
        return nullptr;
    while (node->left != nullptr)
        node = node->left;
    return node;
}

void SplayTree::remove(int key)
{
     // TODO: Verifique a implementação da rotina de remoção
     SplayNode *node = find(key);
    if (node == nullptr)
            return;

    if(node->key != key)
        return;
    
   SplayNode* r1 = node->left;
   SplayNode* r2 = node->right;
   if(r1 == nullptr)
        root = r2;
    else
    {

        while(r1->right != nullptr)
            r1 = r1->right;

        splay(r1);
        r1->right = r2;
        if(r2 != nullptr)
            r2->parent = r1;
        root = r1;
    }
    delete node;
}

void SplayTree::print_tree(SplayNode* node, const std::string& prefix, bool isLeft, std::ostream& out)
{
    if(node == nullptr)
        return;
    
    out << prefix;
    out << (isLeft ? "├──" : "└──" );

    // print the value of the node
    out <<"["<<node->getKey()<<"]" << std::endl;

    print_tree(node->getLeft() , prefix + (isLeft ? "│   " : "    "), true, out);
    print_tree(node->getRight(), prefix + (isLeft ? "│   " : "    "), false, out);
}

void SplayTree::print_in_order(SplayNode* node, std::ostream& out)
{
    if(node == nullptr)
        return;
    print_in_order(node->left, out);
    out << node->key << " ";
    print_in_order(node->right, out);
}


void SplayTree::print_in_order()
{
    print_in_order(root, std::cout);
    std::cout << std::endl;
}

void SplayTree::print_tree()
{
    print_tree(root, "", true, std::cout);
    std::cout << std::endl;
}

void SplayTree::deallocateMemory(SplayNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    deallocateMemory(node->getLeft());
    deallocateMemory(node->getRight());
    delete node;
}

SplayTree::~SplayTree()
{
    deallocateMemory(root);
    root = nullptr;
}