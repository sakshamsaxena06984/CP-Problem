//------------------  General Tree
#include<bits/stdc++.h>
using namespace std;
template<typename T>
//Construction Of The Tree Node
class TreeNode{
public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data)
    {
        this->data=data;
    }
};
//------------Taking_Input_In_Ordered_Way(Level_Wise)
TreeNode<int>* LevelWiseTakeInput()
{
    int rootData;;
    cout<<"Enter The Value Root Data"<<endl;
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*> PendingNode;
    PendingNode.push(root);
    while(PendingNode.size()!=0)
    {
        TreeNode<int> *front=PendingNode.front();
        PendingNode.pop();
        cout<<"Enter The Number Of children : "<<front->data<<endl;
        int n;cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter The Value Of "<<i+1<<"th Child Of "<<front->data<<endl;
            int ChildRootData;
            cin>>ChildRootData;
            TreeNode<int>* ChildRoot=new TreeNode<int>(ChildRootData);
            front->children.push_back(ChildRoot);
            PendingNode.push(ChildRoot);
        }

    }

    return root;


}
//------------Unordered_Way_Of_Taking_Input
TreeNode<int>* TakeInput()
{
    int rootData;;
    cout<<"Enter The Value Root Data"<<endl;
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);
    int n;
    cout<<"Enter The Number Of Child : "<<rootData<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        TreeNode<int>* Child=TakeInput();
        root->children.push_back(Child);
    }

    return root;
}
//----------PringLevelWiseWay
void PrintLevelWise(TreeNode<int>* root)
{
    queue<TreeNode<int>*> PendingNode;
    PendingNode.push(root);
    while(PendingNode.size()!=0)
    {
        TreeNode<int>* front=PendingNode.front();
        PendingNode.pop();
        cout<<front->data<<" : ";
        for(int i=0;i<front->children.size();i++)
        {
            cout<<front->children[i]->data<<" ";
            PendingNode.push(front->children[i]);
        }
        cout<<endl;

    }
}
//----------PrintingUnorderdWay
void PrintTree(TreeNode<int>* root){
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++)
        cout<<root->children[i]->data<<" ";
    cout<<endl;

    for(int i=0;i<root->children.size();i++)
        PrintTree(root->children[i]);

}
int main()
{
    // TreeNode<int>* root=TakeInput();
    // PrintTree(root);

    TreeNode<int>* root =LevelWiseTakeInput();
    PrintLevelWise(root);

}