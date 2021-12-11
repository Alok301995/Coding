#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node * right;

    Node(){
        data = NULL;
        left =nullptr;
        right = nullptr;
    }
    Node(int data){
        data = data;
        left = nullptr;
        right = nullptr;
    }
};



class BST{
    public:
        Node *root;

    BST(){
        root = nullptr;
    }

    Node* insertBST(int data){
        if(root == nullptr){
            // Empty root
            root = new Node(data);
        }
        if(root ->data > data){
            root ->left = insertBST(data);
        }
        else if(root ->data < data ){
            root ->right  = insertBST(data);
        }
        return root;
    }
    

    int searchBST(Node *root ,int key){

    }

    

    

};