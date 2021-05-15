/*
  Life is onetime offer ,use it well
*/
#include<bits/stdc++.h>
using namespace std;
/*
0/1 Knapsack Problem 
Time Complex. -> O(2^n) with recursion 
O(n*w)->n=size and w=capacity recusrion with memoization

*/
const int N=100;
//this is for storing the tempreory states of recursion
vector<vector<int>>dp(N,vector<int>(N,-1));

int times=0;
int Knapsack(int n,int weight[],int price[],int capacity)
{
  //passing n-1 so this
  times++;
  if(capacity==0 or n<0)
  {
    return 0;
  }
  //checking for memo
  //string for [n][capaicty]
  if(dp[n][capacity]!=-1)
  {
    return dp[n][capacity];
  }
  int op1=0,op2=0;
  //if we include the current item
  if(weight[n]<=capacity)
  {
   op1=price[n]+Knapsack(n-1,weight,price,capacity-weight[n]);

  }
  //if we not including current item
  op2=Knapsack(n-1,weight,price,capacity);

//return the max between both the options
return dp[n][capacity]=max(op1,op2);


}

int main()
{
  int weight[]={10,20,30};
  int price[]={60,100,120};
  int capacity=50;
  int n=3;//size of array
  int ans=Knapsack(n-1,weight,price,capacity);
  cout<<ans<<endl;
  cout<<times<<endl;
  return 0;
}