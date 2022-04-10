#include<iostream>
using namespace std;

/*Construct and expression tree from prefix expression and perform recursive and
non-recursive In-order, pre-order and post-order traversals.
Input: prefix expression
a. Create tree
b. All traversals
*/

class node{
    public:
    char data;
    node *left,*right;
};

class tree{
    public:
    int top;

    tree(){
        top = -1;
    }
    node *pop();
    node *arr[30]; //stores operands and operator

    char eqn[30]; //storing equation 
    void createTree();
    int checkSymbol(char ele);
    void push(node *root);

    void inDisp(node *root); // inorder display
    void postDisp(node *root); // postorder display
    void preDisp(node *root); // preorder display
};

void tree::push(node *root){
    top++;
    arr[top] = root;
}

node *tree::pop(){
    top--; // overwrite possible
    return (arr[top+1]);
}

int tree::checkSymbol(char ele){
    if(ele=='+' || ele=='-' || ele=='/' || ele=='*'){
        return 2;
    }
    else if((ele>='a' && ele<='z') || (ele>='A' && ele<='Z')){
        return 1;
    }
    else{
        return 3;
    }
}

void tree::createTree(){
    node *ptr1,*ptr2;
    cout<<"Enter Equation: ";
    cin>>eqn; // *+AB+CD
    // calculating size of equation
    int size = 0;
    for(int i = 0; eqn[i] != '\0'; i++){
        size++;
    }
    char symbol; 
    for(int i = size-1; i >= 0; i--){
        symbol = eqn[i];
        int val = checkSymbol(symbol);
        if(val == 1){
            node *newNode = new node;
            newNode->data = symbol;
            newNode->left = NULL;
            newNode->right = NULL;
            push(newNode);
        }
        else if(val == 2){
            ptr1 = pop();
            ptr2 = pop();
            node *newNode = new node;
            newNode->data = symbol;
            newNode->left = ptr1;
            newNode->right = ptr2;
            push(newNode);
        }
    }
}



void tree::inDisp(node *root){
    if(root!=NULL){
        inDisp(root->left);
        cout<<root->data;
        inDisp(root->right);
    }
}

void tree::postDisp(node *root){
    if(root!=NULL){
        postDisp(root->left);
        postDisp(root->right);
        cout<<root->data;
    }
}

void tree::preDisp(node *root){
    if(root != NULL){
        cout<<root->data;
        preDisp(root->left);
        preDisp(root->right);
    }
}

int main(){
    tree t1;
    t1.createTree();
    cout<<"Inorder"<<endl;
    t1.inDisp(t1.arr[0]);
    cout<<endl;
    cout<<"PreOrder"<<endl;
    t1.preDisp(t1.arr[0]);
    cout<<endl;
    cout<<"PosOrder"<<endl;
    t1.postDisp(t1.arr[0]);
}