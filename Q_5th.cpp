#include<iostream>
using namespace std;

/*
Construct and expression tree from postfix expression and perform recursive and
non-recursive In-order, pre-order and post-order traversals.
Input: postfix expression
a. Create tree
b. All traversals
*/

class node{
    public:
    char data;
    node *left;
    node *right;
};

class expTree{
    public:
    int top;
    expTree(){
        top = -1;
    }
    node *arr[50];
    node *pop();
    char eqn[50];
    void creatTree();
    int checkSymbol(char el);
    void push(node *root);
    void display(node *root);
    /*Displays*/
    void inDisp(node *root);
    void postDisp(node *root);
    void preDisp(node *root);
};

node *expTree::pop(){
    top--;
    return(arr[top+1]);
}

void  expTree::push(node *root){
    top++;
    arr[top] = root;
}

int expTree::checkSymbol(char el){

    if(el=='+'||el=='-'||el=='/'||el=='*'){
        return 2;
    }
    else if((el>='a'||el<='z') && (el>='A'||el<= 'Z')){
        return 1;
    }
}

void expTree::creatTree(){
    node *ptr1,*ptr2;
    cout<<"Enter Equation: ";
    cin>>eqn;
    char symbol;
    symbol = eqn[0];
    for(int i = 1; symbol != '\0'; i++){
        int checkNum = checkSymbol(symbol);
        
        if(checkNum == 1){
            node *newNode = new node;
            newNode->data = symbol;
            newNode->left = NULL;
            newNode->right = NULL;
            push(newNode);
        }
        else if (checkNum == 2){
            ptr1 = pop();
            ptr2 = pop();
            node *newNode = new node;
            newNode->data = symbol;
            newNode->left = ptr2;
            newNode->right = ptr1;
            push(newNode);
        }
        symbol = eqn[i];    
    }
}

void expTree::inDisp(node *root){
    if(root!=NULL){
        inDisp(root->left);
        cout<<root->data;
        inDisp(root->right);
    }

}

void expTree::preDisp(node *root){
    if(root != NULL){
        cout<<root->data;
        preDisp(root->left);
        preDisp(root->right);
    }
}

void expTree::postDisp(node *root){
    if(root != NULL){
        postDisp(root->left);
        postDisp(root->right);
        cout<<root->data;
    }
}
int main(){
        expTree t1;
        t1.creatTree();
        cout<<"Inorder"<<endl;
        t1.inDisp(t1.arr[0]);
        cout<<endl;
        cout<<"Postorder"<<endl;
        t1.postDisp(t1.arr[0]);
        cout<<endl;
        cout<<"Preorder"<<endl;
        t1.preDisp(t1.arr[0]);
        cout<<endl;
}