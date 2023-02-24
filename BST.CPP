#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BinaryTreeNode{
	public:
		T data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;
		BinaryTreeNode(T data){
			this->data=data;
			left=NULL;
			right=NULL;
		}
		~BinaryTreeNode(){
			delete left;
			delete right;
		}

};
class BST{
public:
	BinaryTreeNode<int>* root;
	BST(){
		root=NULL;
	}
	~BST(){
		delete root;
	}
	//searching of data in BST
private:
	bool hasdata(int data,BinaryTreeNode<int>* root){
		if(root==NULL) return false;
		if(root->data==data) return true;
		if(root->data>data) return hasdata(data,root->left);
		else return hasdata(data,root->right);
	}
public:
	void hasdata(int data){
		bool ans=hasdata(data,this->root);
		if(ans==true){
			cout<<data<<" = "<<ans<<endl;
		}else{
			cout<<data<<" = "<<ans<<endl;
		}
	}

	//insert data node in BST
private:
	BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int>* root){
		if(root==NULL){
			BinaryTreeNode<int>* node=new BinaryTreeNode<int>(data);
			return node;
		}
		if(data>root->data){
			root->right=insert(data,root->right);
		}else{
			root->left=insert(data,root->left);
		}
		return root;
	}
public:
	void insert(int data){
		this->root=insert(data,this->root);
		cout<<data<<" node inserted "<<endl;
	}

	//deleting data node
private:
	BinaryTreeNode<int>* deleteNode(int data,BinaryTreeNode<int>* root){
		if(root==NULL){
			return NULL;
		}
		//left side
		if(data<root->data){
			root->left=deleteNode(data,root->left);
			return root;
		}
		//right side
		if(data>root->data){
			root->right=deleteNode(data,root->right);
			return root;
		}
		else{
			// main deleting part
			if(root->left==NULL and root->right==NULL){
				delete root;
				return NULL;
			}
			else if(root->left==NULL and root->right!=NULL){
				BinaryTreeNode<int> *temp=root->right;
				delete root;
				return temp;
			}
			else if(root->right==NULL and root->left!=NULL){
				BinaryTreeNode<int> *temp=root->left;
				delete root;
				return temp;
			}else{
				BinaryTreeNode<int> *minValueRight=root->right;
				while(minValueRight->left!=NULL)
					minValueRight=minValueRight->left;
				int minValue=minValueRight->data;
				root->data=minValue;
				root->right=deleteNode(minValue,root->right);
				return root;
			}
		}

	}
public:
	void deleteNode(int data){
		this->root=deleteNode(data,this->root);
		cout<<data<<" node has deleted"<<endl;
	}
private:
	void printTree(BinaryTreeNode<int>* root){
		if(root==NULL) return;
	queue<BinaryTreeNode<int>*> pendingNode;
	pendingNode.push(root);
	while(pendingNode.size()!=0){
		BinaryTreeNode<int>* a=pendingNode.front();
		pendingNode.pop();
		cout<<a->data<<"-> ";
		if(a->left!=NULL){
			cout<<"L: "<<a->left->data<<" ";
			pendingNode.push(a->left);
		}
		if(a->right!=NULL){
			cout<<"R: "<<a->right->data<<" ";
			pendingNode.push(a->right);
		}
		cout<<endl;

	}
	}
public:
	void printTree(){
		printTree(this->root);
	}
};
int main(){
	cout<<"Welcome In BST Creation Program"<<endl;
	BST *obj=new BST();
	obj->insert(3);
	obj->insert(2);
	obj->insert(6);
	obj->hasdata(6);
	obj->hasdata(7);
	obj->printTree();
	obj->deleteNode(3);
	obj->printTree();
}