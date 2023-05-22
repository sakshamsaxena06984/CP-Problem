#include<bits/stdc++.h>
using namespace std;
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
    // top-down approach
    int t[n+1][w+1];
    for(int i=0;i<=n;i++)
    	for(int j=0;j<=w;j++)
    		if(i==0 or j==0)
    			t[i][j]=0;

    for(int i=1;i<=n;i++){
    	for(int j=1;j<=w;j++){
    		if(wt[i-1]<j){
    			t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
    		}
    		else{
    			t[i][j]=t[i-1][j];
    		}
    	}
    }

    cout<<"final ans : "<<t[n][w];	

    		

}