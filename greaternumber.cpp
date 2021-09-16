#include<bits/stdc++.h>
using namespace std;
int number(int *num,int *fact,int *freq,int n){
    //base case
    if(n==0||n==1)
        return 0;
    int ans=0;

    for(int i=num[0]+1;i<10;i++)
    {
        if(freq[i]>0)
        {
            ans+=fact[n-1];
        }
    }
    freq[num[0]]--;
    ans+=number(num+1,fact,freq,n-1);//recursive call
    return ans;
}
int main()
{
    int n;cin>>n;//size of array
    int num[n];
    int* fact=new int[n];
    fact[0]=1;//maintina the factorial
    int freq[10]={0};//maintain the frequency
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        fact[i+1]=(i+1)*fact[i];
        freq[num[i]]++;
    }

    cout<<number(num,fact,freq,n)<<endl;
}