#include<bits/stdc++.h>
using namespace std;
int fun(int *wt,int *val,int n,int w){
	//base case
	if(n==0 or w==0) return 0;
	if(wt[n-1]<=w)
		return max(val[n-1]+fun(wt,val,n-1,w-wt[n-1]),fun(wt,val,n-1,w));
	else
		return fun(wt,val,n-1,w);
}
int main(){
	int n,w;
	cout<<"Enter the value of weight"<<endl;
	cin>>w;
	cout<<"Enter the size of weight and value array"<<endl;
	cin>>n;
	int wt[n],val[n];
	cout<<"Enter the values in weight array"<<endl;
	for(int i=0;i<n;i++){
		cout<<"Enter the "<<i<<" index value in weight array"<<endl;
		cin>>wt[i];
	}

	cout<<"Enter the values in values array"<<endl;
	for(int i=0;i<n;i++){
		cout<<"Enter the "<<i<<" index value in values array"<<endl;
		cin>>val[i];
	}

	int ans=fun(wt,val,n,w);
	cout<<"Final Answer "<<ans<<endl;
}