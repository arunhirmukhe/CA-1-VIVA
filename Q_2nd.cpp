#include<iostream>
using namespace std;

/*
Create Binary tree and perform following operations:
a. Create
b. Display In-order traversal
c. Depth of a tree
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
        int maxDepth(node *rt);
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

int tree::maxDepth(node *rt){
    if (rt == NULL)
        return -1;
    else
    {
        
        int lDepth = maxDepth(rt->left);
        int rDepth = maxDepth(rt->right);
    
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
    
}

int main()
{
    tree t1;
    for(int i = 0; i<7; i++){
        t1.createTree();
    }
    cout<<endl;
    cout<<"Inorder Display"<<endl;
    t1.displayIn(t1.root);
    cout<<endl;
    cout<<"Maximum depth of tree is "<<t1.maxDepth(t1.root)<<endl;

}