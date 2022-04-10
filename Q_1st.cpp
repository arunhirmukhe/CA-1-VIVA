#include<iostream>
using namespace std;

/*
Create Binary tree and perform following operations:
a. Create
b. Insert
c. Display (using all 3 traversals with recursion)
*/

class node{
    public:
        int data;
        node *left;
        node *right;
        node(){
            left = NULL;
            right = NULL;
        }
};

class tree{
    public:
        node *root;
        void createTree();
        void insertData(node *n1,node *n2);
        void displayIn(node *rt);
        void displayPos(node *rt);
        void displayPre(node *rt);
        tree(){
            root = NULL;
        }
};

void tree::createTree(){
    node *newNode = new node;
    cout<<"Enter Data : ";
    cin>>newNode->data;
    if (root == NULL){
        root = newNode;
    }
    else{
        insertData(root,newNode);
    }
}

void tree::insertData(node *n1,node *n2){
    if(n1->data>n2->data){
        if(n1->left == NULL){
            n1->left = n2;
        }
        else{
            insertData(n1->left,n2);
        }
    }
    else{
        if(n1->right == NULL){
            n1->right = n2;
        }
        else{
            insertData(n1->right,n2);
        }
    }
}

void tree::displayIn(node *rt){
    if(rt != NULL){
        displayIn(rt->left);
        cout<<rt->data<<" ";
        displayIn(rt->right);
    }
}

void tree::displayPos(node *rt){
    if(rt != NULL){
        displayIn(rt->left);
        displayIn(rt->right);
        cout<<rt->data<<" ";
    }
}

void tree::displayPre(node *rt){
    if(rt != NULL){
        cout<<rt->data<<" ";
        displayIn(rt->left);
        displayIn(rt->right);
    }
}

int main(){
    tree t1;
    for(int i = 0; i<5; i++){
        t1.createTree();
    }
    cout<<endl;
    cout<<"Inorder Display"<<endl;
    t1.displayIn(t1.root);
    cout<<endl;
    cout<<"Postorder Display"<<endl;
    t1.displayPos(t1.root);
    cout<<endl;
    cout<<"Preorder Display"<<endl;
    t1.displayPre(t1.root);
}