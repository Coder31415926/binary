// binary tree and search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/**
    make class to hold tree

**/

#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INORDER 1
#define PREORDER 2
#define POSTORDER 3
//Node structure

struct node
{
    int value = 0;
    int balance = 0;
    struct node* leftChild = nullptr;
    struct node* rightChild = nullptr;

    node(int val)
    {
        value = val;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

class binaryTree
{
    void inOrder(node* node);
    void postOrder(node* node);
    void preOrder(node* node);
public:
    node* root = nullptr;
    void insert(int value);
    node* search(int value);
    void Print(int i);
    

};



void binaryTree::insert(int value)
{
    if (this->root == nullptr)
    {
        this->root = new node(value);
        return;
    }
        
    struct node* current_node = root;

    while (true)
    {
        //Go left
        //std::cout << current_node;
        if (value < current_node->value)
        {
            current_node->balance--;
            //If dead end, add new node and end loop
            if (current_node->leftChild == nullptr)
            {
                current_node->leftChild = new node(value);
                return;
            }

            else
            {
                current_node = current_node->leftChild;
                continue;
            }
        }
        //go right
        else
        {
            current_node->balance++;
            //If dead end, add new node and end loop
            if (current_node->rightChild == nullptr)
            {
                current_node->rightChild = new node(value);
                return;
            }

            else
            {
                current_node = current_node->rightChild;
                continue;
            }
        }
    }

}

node* binaryTree::search(int value)
{
    struct node* current_node = root;

    while (true)
    {
        //If value is matched, return node
        if (value == current_node->value)
            return current_node;

        //Go left
        if (value < current_node->value)
        {
            //check if child exists
            if (current_node->leftChild == nullptr)
                return nullptr;
            else
            {
                current_node = current_node->leftChild;
                continue;
            }
        }
        //go right
        else
        {
            //check if child exists
            if (current_node->rightChild == nullptr)
                return nullptr;
            else 
            {
                current_node = current_node->rightChild;
                continue;

            }
            
        }

    }
}

//Recursive function to print the tree in order PRIVATE
void binaryTree::inOrder(node* node)
{
    if (node == nullptr)
        return;

    inOrder(node->leftChild);

    std::cout << node->value << " BALANCE: " << node->balance << std::endl;

    inOrder(node->rightChild);
}

//recursive to print child, child node
void binaryTree::postOrder(node* node)
{
    if (node == nullptr)
        return;

    postOrder(node->leftChild);

    postOrder(node->rightChild);

    std::cout << node->value << std::endl;
}

//recursive to print node,  child, child
void binaryTree::preOrder(node* node)
{
    if (node == nullptr)
        return;
    std::cout << node->value << std::endl;

    preOrder(node->leftChild);

    preOrder(node->rightChild);

}

//Public print function, prints in order.
void binaryTree::Print(int i)
{
    switch (i)
    {
    case INORDER:
        inOrder(root);
        break;
    
    case PREORDER:
        preOrder(root);
        break;

    case POSTORDER:
        postOrder(root);
        break;

    default:
        break;
    }

}




int main()
{
    binaryTree myTree;

    //Don't look at this, just fills array with random values 1-100 and shuffles.
    std::vector<int> v;
    myTree.insert(50);
    for (int i = 0; i < 100; i++)
    {
        v.push_back(i);

    }
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(v.begin(), v.end(), g);

    for(auto n : v)
    {
        //put values into the tree and print it to see random order
       myTree.insert(n);
       std::cout << n << std::endl;
    }

    std::cout <<  "order " << INORDER << std::endl;
    
    myTree.Print(INORDER);


}


