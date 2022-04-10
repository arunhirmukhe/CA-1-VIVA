#include<iostream>
using namespace std;

/*
Implement binary search tree and perform following operations:
a. Insert
b. Display In-order traversal
c. Search
*/

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
    int flag = 0;
    node *root;
    tree(){
        root = NULL;
    }
    void createTree();
    void insertData(node *root, node *newNode);
    void inDisp(node *root);
    int search(int key,node *root);
};

void tree::createTree(){
    node *newNode = new node;
    cout<<"Enter Data: ";
    cin>>newNode->data;
    if (root == NULL){
        root = newNode;
    }
    else{
        insertData(root, newNode);
    }
}

void tree:: insertData(node *root, node *newNode){
    if(root->data > newNode->data){
        if(root->left == NULL){
            root->left = newNode;
        }
        else{
            insertData(root->left,newNode);
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

int tree::search(int key, node *root){
    if(root!=NULL){
        if(key == root->data){
            flag = 1;
            }
        else if(key > root->data){
            search(key,root->right);
        }
        else if(key<root->data){
            search(key,root->left);
        }
    }
    return flag;
}

void tree::inDisp(node *root){
    if(root != NULL){
        inDisp(root->left);
        cout<<root->data<<" ";
        inDisp(root->right);
    }
}

int main(){
    tree t1;
    for(int i = 0; i<5; i++){
        t1.createTree();
    }
    cout<<endl;
    t1.inDisp(t1.root);
    cout<<endl;
    int key;
    cout<<"Enter the number you wanna search: ";
    cin>>key;
    int searchVal = t1.search(key, t1.root);
    if(searchVal == 1){
        cout<<key<<" is present in tree"<<endl;
    }
    else{
        cout<<"No Such Value as "<<key<<endl;
    }
}