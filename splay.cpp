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

SplayTree::SplayTree(): root(nullptr)
{ }

void SplayTree::rotateLeft(SplayNode *X)
{
    SplayNode *Y = X->parent;
    SplayNode *right  = node->getRight();
    if (parent != nullptr)
    {
        if (parent->getLeft() == node)
        {
            parent->setLeft(right);
        }
        else
        {
            parent->setRight(right);
        }
    }
    else
    {
        root = right;
    }
    right->setParent(parent);
    node->setRight(right->getLeft());
    if (node->getRight() != nullptr)
    {
        node->getRight()->setParent(node);
    }
    right->setLeft(node);
    node->setParent(right);
}

/*
       Y                             X     
      / \        rotate left        / \    
     X   ^      <------------      ^   Y   
    / \ /C\                       /A\ / \  
   ^  ^         ------------>         ^  ^ 
  /A\/B\         rotate right        /B\/C\

*/

    
void SplayTree::rotateRight(SplayNode *Y)
{
    SplayNode *X    = Y->left;
    Y->left   = X->right;
    X->right  = Y; 
    Y->parent = X;
    // return X;
}

void SplayTree::splay(SplayNode *node)
{
    /*
    while (node->getParent() != nullptr)
    {
        SplayNode *parent = node->getParent();
        SplayNode *grandparent = parent->getParent();
        if (grandparent == nullptr)
        {
            if (parent->getLeft() == node)
            {
                rotateRight(parent);
            }
            else
            {
                rotateLeft(parent);
            }
        }
        else
        {
            if (grandparent->getLeft() == parent)
            {
                if (parent->getLeft() == node)
                {
                    rotateRight(grandparent);
                    rotateRight(parent);
                }
                else
                {
                    rotateLeft(grandparent);
                    rotateRight(parent);
                }
            }
            else
            {
                if (parent->getLeft() == node)
                {
                    rotateRight(grandparent);
                    rotateLeft(parent);
                }
                else
                {
                    rotateLeft(grandparent);
                    rotateLeft(parent);
                }
            }
        }
    }
    */
}

SplayNode* SplayTree::find(int key)
{
    SplayNode* parent = nullptr;
    SplayNode *node = root;
    while (node != nullptr)
    {
        parent = node->getParent();
        if (node->getKey() == key)
        {
            splay(node);
            return node;
        }
        else if (node->getKey() > key)
        {
            node = node->getLeft();
        }
        else
        {
            node = node->getRight();
        }
    }
    splay(parent);
    return parent;
}

void SplayTree::insert(int key)
{
    SplayNode *node = new SplayNode(key);
    if (root == nullptr)
    {
        root = node;
    }
    else
    {
        SplayNode *parent = find(key);
        if (parent->getKey() > key)
        {
            parent->setLeft(node);
        }
        else
        {
            parent->setRight(node);
        }
        node->setParent(parent);
    }
}

void SplayTree::remove(int key)
{
     //TODO: 

}

void SplayTree::print(SplayNode* node, const std::string& prefix, bool isLeft, std::ostream& out)
{
    if(node == nullptr)
        return;
    
    out << prefix;
    out << (isLeft ? "├──" : "└──" );

    // print the value of the node
    out <<"["<<node->getKey()<<"]" << std::endl;

    print(node->getLeft() , prefix + (isLeft ? "│   " : "    "), true, out);
    print(node->getRight(), prefix + (isLeft ? "│   " : "    "), false, out);
}

void SplayTree::print()
{
    print(root, "", true, std::cout);
}

SplayNode::~SplayNode()
{
    delete left;
    delete right;
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