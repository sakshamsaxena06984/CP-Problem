#include<bits/stdc++.h>
using namespace std;
static int mt[101][101];
int fun(int *wt,int *val,int w,int n){
	if(n==0||w==0) return 0;
	if(mt[n-1][w-1]!=-1) return mt[n-1][w-1];
	if(wt[n-1]<=w)
	return mt[n-1][w-1]=max(val[n-1]+fun(wt,val,w-wt[n-1],n-1),fun(wt,val,w,n-1));
	else return mt[n-1][w-1]=fun(wt,val,w,n-1);
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

	//filling -1 value in matric mt
	memset(mt,-1,sizeof(mt));
	int ans=fun(wt,val,w,n);
	cout<<"final answer : "<<ans<<endl;

}