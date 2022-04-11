/*
Implement binary search tree and perform following operations:
a. Insert
b. Display In-order traversal
c. Delete (Case 1: Node to be deleted is the leaf)
*/

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left,*right;
    node(){
        left = NULL;
        right = NULL;
    }

};

class tree{
    public:
    node *root;
    node *parent;
    tree(){
        parent = NULL;
        root = NULL;
    }
    
    void createTree();
    void insertData(node *root, node *newNode);
    void inDisp(node *root);
    void deleteTree(int key,node *root, node *parent);
    void deleteNode(node *root, node *parent);
};

void tree::createTree(){
    node *newNode = new node;
    cout<<"Enter Data: ";
    cin>>newNode->data;
    if(root == NULL){
        root = newNode;
    } 
    else{
        insertData(root, newNode);
    }
}

void tree::insertData(node *root, node *newNode){
    if(root->data > newNode->data){
        if(root->left == NULL){
            root->left = newNode;
        }
        else{
            insertData(root->left, newNode);
        }
    }
    else{
        if(root->right == NULL){
            root->right = newNode;
        }
        else{
            insertData(root->right,newNode);
        }
    }
}

void tree::inDisp(node *root){
    if(root!=NULL){
        inDisp(root->left);
        cout<<root->data<<" ";
        inDisp(root->right);
    }
}

void tree::deleteTree(int key,node *root, node *parent){
    if(root->data == key){
        deleteNode(root,parent);
    }
    else if(root->data > key){
        parent = root;
        deleteTree(key, root->left, parent);
    }
    else{
        parent = root;
        deleteTree(key, root->right, parent);
    }
}

void tree::deleteNode(node *root, node *parent){
    if(parent->left == root){
        parent->left = NULL;
    }
    else{
        parent->right = NULL;
    }
    
}

int main(){
    tree t1;
    for(int i = 0; i<7; i++){
        t1.createTree();
    }
    cout<<"Inorder Display : ";
    t1.inDisp(t1.root);
    cout<<endl;
    int key;
    cout<<"Enter the number you wanna delete: ";
    cin>>key;
    t1.deleteTree(key, t1.root,t1.parent);
    cout<<"After deletion of leaf node: "<<endl;
    t1.inDisp(t1.root);
}