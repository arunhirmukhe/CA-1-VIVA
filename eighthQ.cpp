/*
Implement binary search tree and perform following operations:
a. Insert
b. Display In-order traversal
c. Mirror image
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
    tree(){
        root = NULL;
    }
    void createTree();
    void insertData(node *root, node *newNode);
    void inDisp(node *root);
    node *mirrorNode = NULL;
    node *mirrorTree(node *root);
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

node *tree::mirrorTree(node *root){
    if(root!=NULL){
        if(mirrorNode == NULL){
            mirrorNode = root;
            mirrorTree(mirrorNode->left);
            mirrorTree(mirrorNode->right);
            node *temp = new node;
            temp = mirrorNode->left;
            mirrorNode->left = mirrorNode->right;
            mirrorNode->right = temp;
        }

        else{
            node *newNodeMirr = new node;
            node *temp = new node;
            mirrorTree(newNodeMirr->left);
            mirrorTree(newNodeMirr->right);
            temp = newNodeMirr->left;
            newNodeMirr->left= newNodeMirr->right;
            newNodeMirr->right = temp;
        }
    }
    return mirrorNode;
}

int main(){
    tree t1;
    for(int i = 0; i<10; i++){
        t1.createTree();
    }
    cout<<"Inorder Display : ";
    t1.inDisp(t1.root);
    cout<<endl;
    node *mirror = t1.mirrorTree(t1.root);
    cout<<"Inorder Display : ";
    t1.inDisp(mirror);
}