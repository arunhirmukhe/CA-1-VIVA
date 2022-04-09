#include<iostream>
using namespace std;

/*
Create Binary tree and perform following operations:
a. Create
b. Display In-order traversal
c. Create a copy of a tree
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
        node *copyTree(node *rt);
        tree(){
            root = NULL;
        }
};

void tree::createTree(){
    node *newNode = new node();
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

node *tree::copyTree(node *rt){
    if (rt == NULL){
        return NULL;
    }
    node *root_copy = new node();
    root_copy->data = rt->data;
    root_copy->left = copyTree(rt->left);
    root_copy->right = copyTree(rt->right);
    return root_copy;
}

int main()
{
    tree t1;
    for(int i = 0; i<5; i++){
        t1.createTree();
    }
    cout<<endl;
    //cout<<"Inorder Display"<<endl;
    //t1.displayIn(t1.root);
    //cout<<endl;

    node *clone = t1.copyTree(t1.root);
    t1.displayIn(clone);
}