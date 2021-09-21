#include<bits/stdc++.h>
using namespace std;
template<typename T>
class TreeNode{
public:
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
//**************************************-------LevelWisePrinting
void LeveWisePrinting(TreeNode<int>* root)
{
    if(root==NULL)
        return;
    queue<TreeNode<int>*> pq;
    pq.push(root);
    while(pq.size()!=0)
    {
        TreeNode<int>* front=pq.front();
        pq.pop();
        cout<<front->data<<" : ";
        if(front->left!=NULL)
        {
            cout<<" L-> "<<front->left->data;
            pq.push(front->left);
        }
        if(front->right!=NULL)
        {
            cout<<" R-> "<<front->right->data;
            pq.push(front->right);
        }
        cout<<endl;
    }
    cout<<endl;

}
//**************************************-------Printing Part
void PrintingTree(TreeNode<int>* root){
    if(root==NULL)
        return;
    cout<<root->data<<" : ";
    if(root->left!=NULL)
        cout<<" L -> "<<root->left->data;
    if (root->right!=NULL)
        cout<<" R -> "<<root->right->data;
    cout<<endl;
    PrintingTree(root->left);
    PrintingTree(root->right);
}
//**************************************-------Print The Tree In Pre-Order
void Preorder(TreeNode<int>* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
//**************************************-------Print The Tree In Pre-Order(Non-Recursive)
void PreorderNonRecursive(TreeNode<int>* root)
{
    stack<TreeNode<int>*> st;
    st.push(root);
    while(st.size()!=0)
    {
        TreeNode<int>* curr=st.top();
        cout<<curr->data<<" ";
        st.pop();
        if(curr->right!=NULL)
            st.push(curr->right);
        if(curr->left!=NULL)
            st.push(curr->left);
    }
    cout<<endl;

}
//**************************************-------Print The Tree In Post-Order
void Postorder(TreeNode<int>* root)
{
    if(root==NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
//**************************************-------Print The Tree In Post-Order(Non-Recursive)
void PostorderNonRecursive(TreeNode<int>* root)
{
    stack<TreeNode<int>*> st;
    st.push(root);
    stack<TreeNode<int>*> out;
    while(st.size()!=0)
    {
        TreeNode<int>* curr=st.top();
        st.pop();
        out.push(curr);
        if(curr->left!=NULL)
            st.push(curr->left);
        if(curr->right!=NULL)
            st.push(curr->right);
    }
    while(out.size()!=0)
    {
        TreeNode<int>* ans=out.top();
        cout<<ans->data<<" ";
        out.pop();
    }
    cout<<endl;
}
//**************************************-------Print The Tree In In-Order
void Inorder(TreeNode<int>* root)
{
    if(root==NULL)
        return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
//**************************************-------Print The Tree In In-Order(Non-Recursive)
void InorderNonRecursive(TreeNode<int>* root)
{
    TreeNode<int>* curr=root;
    stack<TreeNode<int>*> st;
    while(st.size()!=0 || curr!=NULL){
        if(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        else
        {
            curr=st.top();
            st.pop();
            cout<<curr->data<<" ";
            curr=curr->right;
        }
    }
    cout<<endl;
}
//**************************************-------Takeing Input Level-Wise
TreeNode<int>* TakeInputLevelWise()
{
    int rootdata;
    cout<<"Enter The Root Data "<<endl;
    cin>>rootdata;
    TreeNode<int>* newnode=new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> pq;
    pq.push(newnode);
    while(pq.size()!=0)
    {
        TreeNode<int>* front=pq.front();
        pq.pop();
        cout<<"Enter The Value For The LeftChild "<<front->data<<endl;
        int leftrootdata;
        cin>>leftrootdata;
        if(leftrootdata!=-1)
        {
            TreeNode<int>* leftroot=new TreeNode<int>(leftrootdata);
            pq.push(leftroot);
            front->left=leftroot;
        }


        cout<<"Enter The Value For The RightChild "<<front->data<<endl;
        int rightrootdata;
        cin>>rightrootdata;
        if(rightrootdata!=-1)
        {
            TreeNode<int>* rightroot=new TreeNode<int>(rightrootdata);
            pq.push(rightroot);
            front->right=rightroot;
        }
    }
    return newnode;
}
//**************************************-------Taking Input
TreeNode<int>* TakeInput()
{
    cout<<"Enter The Value Of The Root_Data"<<endl;
    int rootdata;cin>>rootdata;
    if(rootdata==-1)
        return NULL;
    TreeNode<int>* root=new TreeNode<int>(rootdata);
    TreeNode<int>* rootleft=TakeInput();
    TreeNode<int>* rootright=TakeInput();
    root->left=rootleft;
    root->right=rootright;
    return root;
}
int main()
{
    // TreeNode<int>* root=TakeInput();
    TreeNode<int>* root=TakeInputLevelWise();
    // PrintingTree(root);
    LeveWisePrinting(root);
    Preorder(root);
    cout<<endl;
    Postorder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    cout<<endl;
    InorderNonRecursive(root);
    PostorderNonRecursive(root);
    PreorderNonRecursive(root);

}
//1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1 -1