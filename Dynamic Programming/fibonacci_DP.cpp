#include<bits/stdc++.h>
using namespace std;
const int val=1e5+2;
int dp[val];
int fibbo(int n)
{
  if(n<2)
  {
  	return n;
  }
  else if(dp[n]!=0)
  {
  	return dp[n];
  }
 
 	int val=fibbo(n-2)+fibbo(n-1);
    return dp[n]=val;
}
int main()
{
	int n;
	cin>>n;
	cout<<fibbo(n)<<endl;


	return 0;
};