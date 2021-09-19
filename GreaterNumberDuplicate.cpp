/*****
Code : No. of numbers - with duplicates
Given a number n, find number of numbers that are greater than n using the same set of digits as n. n might have duplicate digits.
Input Format :
Integer n
Output Format :
Count of greater numbers
Sample Input :
122
Sample Output :
2
*****/

#include<bits/stdc++.h>
using namespace std;
long helper(int* digit,int n,int* fact,int *freq,int Bindex)
{
    //base case
    if(Bindex>=n-1)
        return 0;
    long count=0;//calculate answe
    int StartDigit=digit[Bindex];//fetch the first digit 
    for(int i=StartDigit+1;i<10;i++)
    {
        if(freq[i]>0)
        {
            long currentCount=fact[n-Bindex-1]/fact[freq[i]-1];
            for(int j=0;j<10;j++)
            {
                if(i==j)
                    continue;
                currentCount=currentCount/fact[freq[j]];
            }
            count+=currentCount;
        }
    }
    freq[StartDigit]--;

    count+=helper(digit,n,fact,freq,Bindex+1);
    return count;

}
long CountNumber(long num)
{
    int numDigit=(int)log10(num)+1;//calculate number of digit present
    int *freq=new int[10]();
    int *digit=new int[numDigit];

    //Maintain the input array
    for(int i=0;i<numDigit;i++){
        digit[numDigit-i-1]=(int)(num%10);
        freq[(int)(num%10)]++;
        num=num/10;
    }
    //calculate factorial
    int *fact=new int[numDigit];
    fact[0]=1;
    for(int i=1;i<numDigit;i++)
    {
        fact[i]=fact[i-1]*i;
    }
     
    return helper(digit,numDigit,fact,freq,0);
}
int main()
{
    long num;cin>>num;
    cout<<"Greater Number : "<<CountNumber(num)<<endl;
}