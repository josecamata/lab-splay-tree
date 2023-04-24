#ifndef SPLAY_H__
#define SPLAY_H__

#include "splay_node.h"

template <typename T>
class SplayTree
{   

    public:
        SplayTree();
        void           insert(T key);
        void           remove(T key);
        SplayNode<T>*  max();
        SplayNode<T>*  min();
        SplayNode<T>*  find(T key);
        void       print_tree();
        void       print_in_order();
        SplayNode<T>* rotateLeft(SplayNode<T> *node);
        SplayNode<T>* rotateRight(SplayNode<T> *node);
        ~SplayTree();
    private:
        // Funções auxiliares
        void print_tree(SplayNode<T>* node, const std::string& prefix, bool isLeft, std::ostream& out);
        void print_in_order(SplayNode<T>* node, std::ostream& out);

        void splay(SplayNode<T> *node);
        void clean(SplayNode<T> *node);

        // Ponteiro para o no raiz da arvore
        SplayNode<T> *root;
};

/*
   Implement the SplayNode class
*/

// Cria um SplayTree vazia
template <typename T>
SplayTree<T>::SplayTree(): root(nullptr)
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
 
template <typename T>
SplayNode<T>* SplayTree<T>::rotateLeft(SplayNode<T> *x)
{
    SplayNode<T> *y = x->right;
    if(y == nullptr)
        return x;
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
    return y;
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
template <typename T>
SplayNode<T>* SplayTree<T>::rotateRight(SplayNode<T> *y)
{
    SplayNode<T> *x = y->left;
    if(x == nullptr)
        return y;
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
    return x;
}

// Implemente a rotina de splay. 
// O parâmetro node é o nó que deve ser splayado.
template <typename T>
void SplayTree<T>::splay(SplayNode<T> *x)
{
    /*
    while X is not the root:
    if X is a child of the root:
        // ZIG:
        Rotate about the root to bring X to the root
    else:
        P := X.parent
        G := P.parent  // the grandparent of N
        if X and P are both left or both right children:
            // ZIG-ZIG:
            Rotate about G then about P to bring X up two levels
        else:
            // ZIG-ZAG:
            Rotate about P then about G to bring X up two levels
    */

   while(x != this->root)
   {
        //
        // Se X é filho a esquerda da raiz
        if(x == this->root->left) {
            // Zig Direita
            x = this->rotateRight(root);
            this->root = x;

        } // Se X é filho a direita da raiz
        else if(x == this->root->right)
       
        {
                x = this->rotateLeft(root);
                this->root = x;
        }
        else
        {
            SplayNode<T> *P = x->parent;
            SplayNode<T> *G = P->parent;
            // X é filho a esquerda de P e P é filho a esquerda de G ou
            // X é filho a direita de P e P é filho a direita de G
            if( (x == P->left && P == G->left) || (x == P->right && P == G->right) )
            {
                // Zig-Zig 
                if(x == P->left)
                {
                    // TODO: Rotacionar G para a direita e P para a direita



                }
                else
                {
                    // TODO: Rotacionar G para a esquerda e P para a esquerda
      


                }
            }
            else
            {
                // Zig-Zag
                if(x == P->left)
                {
                    // TODO: Rotacionar P para a direita e G para a esquerda
             
                }
                else
                {
                    // TODO: Rotacionar P para a esquerda e G para a direita
                    

                }
            }

        }

   }
 
}

template <typename T>
SplayNode<T>* SplayTree<T>::find(T key)
{
    SplayNode<T> *node = root;
    SplayNode<T> *parent = nullptr;
    while (node != nullptr && node->key != key)
    {
        parent = node;
        if (key < node->key)
            node = node->left;
        else
            node = node->right;
    }

    if(node == nullptr)
    {
        if(parent != nullptr)
            this->splay(parent);
    }
    else
        this->splay(node);
    return node;
}

template <typename T>
void SplayTree<T>::insert(T key)
{
    SplayNode<T> *node = new SplayNode<T>(key);
    SplayNode<T> *x    = root;
    SplayNode<T> *y    = nullptr;
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
    this->splay(node);

}

// Retorna o nó que contem a maior chave
template <typename T>
SplayNode<T>* SplayTree<T>::max()
{
    SplayNode<T> *node = root;
    if(node == nullptr)
        return nullptr;
    while (node->right != nullptr)
        node = node->right;
    return node;
}

// Retorna o nó que contem a menor chave
template <typename T>
SplayNode<T>* SplayTree<T>::min()
{
    SplayNode<T> *node = root;
    if(node == nullptr)
        return nullptr;
    while (node->left != nullptr)
        node = node->left;
    return node;
}

template <typename T>
void SplayTree<T>::remove(T key)
{
     // TODO: Verifique a implementação da rotina de remoção
     
    SplayNode<T> *node = find(key);
    if (node == nullptr)
            return;

    if(node->key != key)
        return;
    
   SplayNode<T>* r1 = node->left;
   SplayNode<T>* r2 = node->right;
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

template <typename T>
void SplayTree<T>::print_tree(SplayNode<T>* node, const std::string& prefix, bool isLeft, std::ostream& out)
{
    
    
    out << prefix;
    out << (isLeft ? "├──" : "└──" );

    // print the value of the node
    if(node == nullptr)
    {
        out << "[null]" << std::endl;
        return;
    }
    out <<"["<<node->getKey()<<"]" << std::endl;

    print_tree(node->getLeft() , prefix + (isLeft ? "│   " : "    "), true, out);
    print_tree(node->getRight(), prefix + (isLeft ? "│   " : "    "), false, out);
}

template <typename T>
void SplayTree<T>::print_in_order(SplayNode<T>* node, std::ostream& out)
{
    if(node == nullptr)
        return;
    print_in_order(node->left, out);
    out << node->key << " ";
    print_in_order(node->right, out);
}


template <typename T>
void SplayTree<T>::print_in_order()
{
    print_in_order(root, std::cout);
    std::cout << std::endl;
}

template <typename T>
void SplayTree<T>::print_tree()
{
    print_tree(root, "", false, std::cout);
    std::cout << std::endl;
}

template <typename T>
void SplayTree<T>::clean(SplayNode<T> *node)
{
    if (node == nullptr)
    {
        return;
    }
    clean(node->left);
    clean(node->right);
    delete node;
}

template <typename T>
SplayTree<T>::~SplayTree()
{
    clean(root);
    root = nullptr;
}


#endif /* SPLAY_H__ */
