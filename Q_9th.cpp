/*
Implement binary search tree and perform following operations:
a. Insert
b. Display In-order traversal
c. Display level wise
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
    bool printLevel(node *root, int level);
    void levelOrderTraversal(node *root);
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

bool tree::printLevel(node *root, int lvl){
    if(root == NULL){
        return false;
    }
    if(lvl == 1){
        cout<<root->data<<" ";
        return true;
    }
    bool left = printLevel(root->left, lvl - 1);
	bool right = printLevel(root->right, lvl - 1);

}

void tree::levelOrderTraversal(node *root){
    int lvl = 1;
    while(printLevel(root, lvl)){
        lvl++;
        cout<<endl;
    }
}

int main(){
    tree t1;
    for(int i = 0; i<10; i++){
        t1.createTree();
    }
    cout<<"Inorder Display : ";
    t1.inDisp(t1.root);
    cout<<endl;
    t1.levelOrderTraversal(t1.root);
}