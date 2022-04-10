#include<iostream>
using namespace std;

/*
Create Binary tree and perform following operations:
d. Create
e. Display In-order traversal
f. Display leaf-nodes
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
        void displayLeaf(node *rt);
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



void tree::displayLeaf(node *rt){
        if(rt != NULL){
        displayLeaf(rt->left);
        if(rt->left == NULL){
            if(rt->right == NULL){
                cout<<rt->data<<endl;
            }
        }
        displayLeaf(rt->right);
    }
}


int main()
{
    tree t1;
    for(int i = 0; i<10; i++){
        t1.createTree();
    }
    cout<<endl;
    t1.displayLeaf(t1.root);
}