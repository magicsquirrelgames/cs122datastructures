#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

// NODE ===================================================================
template<typename T>
class Node
{
    private:
        Node<T> *left;
        Node<T> *right;
        T data;
    public:
        Node() {left = nullptr; right = nullptr;}
        Node(T newData) {left = nullptr; right = nullptr; data = newData;}

        Node<T>* getLeft() {return left;}
        Node<T>* getRight() {return right;}

        void setLeft(Node<T>* newLeft) {left = newLeft;}
        void setRight(Node<T>* newRight) {right = newRight;}

        T getData() {return data;}
};

// TREE ===================================================================
template <typename T>
class BST
{
    // PRIVATE VARIABLES AND FUNCTIONS
    private:
        Node<T>* root;

        // INSERT HELPER
        void insert(T newData, Node<T>* current)
        {
            if(newData < current->getData()) // data is less, go left
            {
                if(current->getLeft() == nullptr)
                    current->setLeft(new Node<T>(newData));
                else
                    insert(newData, current->getLeft());
            }
            else if(newData > current->getData()) // data is more, go right
            {
                if(current->getRight() == nullptr)
                    current->setRight(new Node<T>(newData));
                else
                    insert(newData, current->getRight());
            }               
        }

        // PRINT HELPER
        void print(Node<T>* current)
        {
            if(current == nullptr) return;

            print(current->getLeft());
            cout << current->getData() << ",";
            print(current->getRight());
        }

        // GET HELPER
        bool get(T data, Node<T>* current)
        {
            if(current == nullptr) return false;

            if(current->getData() == data)
                return true;
            else if(data > current->getData())
                return get(data, current->getRight());
            else if(data < current->getData())
                return get(data, current->getLeft());
            else
                return false;
        }

    // PUBLIC VARIABLES AND FUNCTIONS
    public:

        // CONSTRUCTOR
        BST() {root = nullptr;}

        // INSERT
        void insert(T newData)
        {
            if(root == nullptr)
                root = new Node<T>(newData);
            else
                insert(newData, root);
        }

        // PRINT
        void print()
        {
            print(root);
            cout << endl;
        }

        // GET
        bool get(T data)
        {
            return get(data, root);
        }
};