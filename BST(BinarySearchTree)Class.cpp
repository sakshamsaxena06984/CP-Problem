#include<bits/stdc++.h>
using namespace std;
// BinaryTreeNode Node Construction
class BinaryTreeNode{
public:
   BinaryTreeNode* left;
   BinaryTreeNode* right;
   int data;
   BinaryTreeNode(int data)
   {
      this->data=data;
      left=NULL;
      right=NULL;
   }
};
// BST(BinaryTreeNode) class construction
class BST{
public:
   BinaryTreeNode* root;
   BST(){
      root=NULL;
   }
   ~BST(){
      delete root;
   }
//****************If data is/is not present
private:
   bool HasData(int data,BinaryTreeNode* root)
   {
      if(root==NULL)
         return false;
      if(root->data==data)
         return true;
      if(root->data>data)
      {
         return HasData(data,root->left);
      }
      else
      {
         return  HasData(data,root->right);
      }
   }
public:
   bool HasData(int data){
      return HasData(data,this->root);
   }
//*************Insert the data into BST(BinarySearchTree)
private:
   BinaryTreeNode* Insert(int data,BinaryTreeNode* root){
      if(root==NULL)
      {
         BinaryTreeNode* newnode=new BinaryTreeNode(data);
         return newnode;
      }
      if(data<root->data)
      {
         root->left=Insert(data,root->left);
      }
      else if(data>root->data)
      {
         root->right=Insert(data,root->right);
      }
      return root;
   }
 
public:
   void Insert(int data){
      this->root=Insert(data,this->root);
   }
//************Delete the data from BST(BinarySearchTree)   
private:
   BinaryTreeNode* Delete(int data,BinaryTreeNode* root)
   {
      if(root==NULL)
         return NULL;
      if(data<root->data)
      {
         root->left=Delete(data,root->left);
         return root;
      }
      if(data>root->data)
      {
         root->right=Delete(data,root->right);
         return root;
      }
      if(root->left==NULL and root->right==NULL)
      {
         delete root;
         return NULL;
      }
      else if(root->left==NULL)
      {
         BinaryTreeNode* temp=root->right;
         delete root;
         return temp;
      }
      else if(root->right==NULL)
      {
         BinaryTreeNode* temp=root->left;
         delete root;
         return temp;
      }
      else
      {
         BinaryTreeNode* minNode=root->right;
         //find the smallest node from the right side of the tree
         while(minNode->left!=NULL)
         {
            minNode=minNode->left;
         }
         int Value=minNode->data;
         root->data=Value;
         root->right=Delete(Value,root->right);
         return root;
      }

   }

public:
   void Delete(int data)
   {
      this->root=Delete(data,this->root);
   }

//****************** PrintingWayOfBst
private:
   void Printing(BinaryTreeNode* root)
   {
      if(root==NULL)
         return;
      cout<<root->data;
      if(root->left!=NULL)
      {
         cout<<" L: "<<root->left->data;
      }
      if(root->right!=NULL)
      {
         cout<<" R: "<<root->right->data;
      }
      cout<<endl;
      Printing(root->left);
      Printing(root->right);
   }
public:
   Printing(){
      Printing(this->root);
   }
};
int main()
{
   BST obj;//creating the object of BST
   obj.Insert(5);//insert 5 into BST
   obj.Insert(3);//insert 3 into BST
   obj.Insert(2);//insert 2 into BST
   obj.Insert(1);//insert 1 into BST
   obj.Insert(10);//insert 5 into BST
   obj.Insert(6);//insert 6 into BST
   obj.Insert(7);//insert 7 into BST
   obj.Insert(12);//insert 12 into BST
   obj.Printing();//printing BST
   cout<<"3 is/is not present in BST "<<obj.HasData(3)<<endl;//check 3 is/is not present into BST
   obj.Delete(5);//delete 5 from the bst
   obj.Printing();//printing BST 
   return 0;
}