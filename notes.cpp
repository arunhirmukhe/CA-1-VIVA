// Main function of the C++ program.

#include <iostream>
using namespace std;
class BSTNode
{
 public:
    int data;
    BSTNode *left,*right;
};
class BSTree
{
   public:
   BSTNode *root,*temp,*root1;
   BSTree()
   {
       root=NULL;
       temp=NULL;
   }
   void insertNode(BSTNode *root1,BSTNode *temp1);
   void createNode();
   int searchNode(BSTNode *root,int value);
   void displayBSTree(BSTNode *root);
   BSTNode* mirrorImage(BNode *root);
   void displayLevel-wise();
   void deleteNode(BSTNode *root1,int key);
};
void BSTree::insertNode(BSTNode *root1,BSTNode *temp1)
{if(root1->data<temp->data)//insert temp node at right
    {
        if(root1->right==NULL)
        {
            root1->right=temp;
        }
        else
        {
            insertNode(root1->right,temp);
        }
            
    }
    else
    {
        if(root1->left==NULL)
        {
            root1->left=temp;
        }
        else
        {
            insertNode(root1->left,temp);
        }
    }
    
}
void BSTree::createNode()
{
    char ans='y';
    do
    {    
        temp=new BSTNode();
        cout<<"\nEnter The Element:";
        cin>>temp->data;
        temp->left=NULL;
        temp->right=NULL;
        if(root==NULL)
        {
            root=temp;
        }
        else
        {
            insertNode(root,temp);
        }
        cout<<"\nDo You Want to Enter More Elements?(y/n)";
        cin>>ans;
    }while(ans=='y'||ans=='Y');
    
}
int BSTree::searchNode(BSTNode *root2,int value)
{   
       if(root2!=NULL)
       {
           if(value==root2->data)
          {
            cout<<"true= "<<endl;
            return 1;
            
            }
            else if(value<root2->data)
            {
             cout<<"in left"<<endl;
            searchNode(root2->left,value);
           
            }
            else //if(value>root->data)
            {
            cout<<"in right"<<endl;
            searchNode(root2->right,value);
            
            }
       }
        else
        {
            cout<<"false= "<<endl;
            return 0;
        }
  
    
}
void BSTree::displayBSTree(BSTNode *root1)
{
    if(root1!=NULL)
    {
        displayBSTree(root1->left);
        cout<<root1->data<<" ";
        displayBSTree(root1->right);
    }
    
    
}

BSTNode* BSTree::mirrorImage(BNode *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        BNode *temp1=new BNode;
        temp1->data=root->data;
        temp1->left=copyTree(root->right);
        temp1->right=copyTree(root->left);
        return temp1;
        
    }
        
    
}
    
}
/*void BSTree::DisplayLevel-wise()
{
    
}*/
void BSTree::deleteNode(BSTNode *root1,int key)
{
    int flag=0,status=0;
    BSTNode *prev,*x,*l,*r,*lleaf,*prev1,*lleafRight;
    //Searching for the entered data
    //status will check whether the parent node has the target leaf node as left or right
    //so that it can become NULL after deletion
    while(1)
    {
        if(key==root1->data)
        {
            flag=1;
            break;
        }
        else if(key<root->data)//no left child
        {
            if(root1->left==NULL)
            {
                break;
            }
            //if root1 is left child
            prev=root1;
            root1=root1->left;
            status=1;
        }
        else if(key>root1->data)
        {
            if(root1->right==NULL)//no right child
            {
                break;
            }
            prev=root1;
            root1=root1->right;
            status=2;
        }

    }
    if(flag==1)
    {
        if(root1->left==NULL&&root1->right==NULL)//case1:leaf node
        {
          if(status==1)
          {
              prev->left==NULL;
          }
          if(status==2)
          {
              prev->right==NULL;
          }
            delete root1;
            cout<<"Deletion operation of leaf node is successful!!";
        }
    }
    else
    {
        cout<<"\nData not found!!!";
    }
    if(root1->left==NULL && root1->right!=NULL)//root1 has right child case2
    {
        p=root1->right;
        if(status==1)
        {
            prev->left=p;
        }
        else
        {
            prev->right=p;
        }
        delete root1;
        cout<<"Deletion operation of  node having right child only is successful!!";
        
    }
    else
    {
        cout<<"\nData not found!!!";
    }
    if(root1->left!=NULL&&root1->right==NULL)//root1 has left child case 2
    {
        q=root1->left;
        if(status==1)
        {
            prev->left=q;
        }
        else
        {
            prev->right=q;
        }
        delete root1;
        cout<<"Deletion operation of  node having left child only is successful!!";
        
    }
    else
    {
        cout<<"\nData not found!!!";
    }
    if(root1->left!=NULL && root1->right!=NULL)//case3 root1 has both child
    {
        lleaf=root1->right;
        if(lleaf->left==NULL)
        {
            prev->left=lleaf;
            lleaf->left=root1->left;
        }
        else
        {
            lleafRight=root1->right;
            lleaf=root1->right;
            while(lleaf->right!=NULL)
            {
                prev1=lleaf;
                lleaf=lleaf->left;
            }
            prev1->left=NULL;
            prev->left=lleaf;
            lleaf->left=root1->left;
            lleaf->right=lleafRight;
                
                
        }
    }    
    else
    {
        cout<<"\nData not found!!!";
    }
}


int main()
{
    BSTree bt;
    BSTNode *croot;
    int choice,val,Val,key;
    int flag=0;
    do
    {
        cout<"\n\tMain Menu:";
        cout<<"\n1.Create";
        cout<<"\n2.Display";
        cout<<"\n3.Search";
        cout<<"\n4.Deletion of node";
        cout<<"\n5.Mirror image of tree";
        cout<<"\n6.Exit";
        cout<<"\nEnter Your Choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                    bt.createNode();
                    break;
            case 2:
                    if(bt.root==NULL)
                    {
                        cout<<"Tree is empty.."<<endl;
                    }
                    else
                    {
                        bt.displayBSTree(bt.root);
                    }
                    break;
            case 3://traversal
                    if(bt.root==NULL)
                    {
                        cout<<"Tree is empty.."<<endl;
                    }
                    else
                    {
                        
                        
                        cout<<"Enter the node to be search::\n";
                        cin>>val;
                        flag=bt.searchNode(bt.root,val);
                        
                        if(flag==1)
                        {
                            cout<<"The node is found!!"<<endl;
                        }
                        else //if(flag==false)
                        {
                            cout<<"The node is not present!!"<<endl;
                        }
                    
                    }
                        /*cout<<"\n Preorder traversal\n";
                        bt.preorderTraversal(bt.root);
                        cout<<"\n Postorder traversal\n";
                        bt.postorderTraversal(bt.root);*/
                    break;
            case 4:
                    if(bt.root==NULL)
                    {
                        cout<<"Tree is empty.."<<endl;
                    }
                    else
                    {
                        cout<<"Enter the node data to be deleted::";
                        cin>>key;
                        bt.deleteNode(bt.root,key);
                        
                       
                    }
                    break;
            case 5:
                    if(bt.root==NULL)
                    {
                        cout<<"Tree is empty.."<<endl;
                    }
                    else
                    {
                        
                    }
                    break;
            case 6:
                    if(bt.root==NULL)
                    {
                        cout<<"Tree is empty.."<<endl;
                    }
                    else
                    {
                        cout<<"This is a Mirror image of previous tree";
                        croot=bt.copyTree(bt.root);
                        bt.displayTree(croot);
                        cout<<"\n Inorder traversal\n";
                        bt.inorderTraversal(bt.root);
                        cout<<"\n Preorder traversal\n";
                        bt.preorderTraversal(bt.root);
                        cout<<"\n Postorder traversal\n";
                        bt.postorderTraversal(bt.root);
                    }
                    break;
                    
        
                    
                    
                    
        }
    }while(choice<=6);
    return 0;
}