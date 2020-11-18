#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int dp[1000]{0};
  //(n-1),(n/2),(n/3)
  dp[1]=0;
  dp[0]=INT_MAX;
 for(int i=2;i<=n;i++)
  {
  	int two=0,one=0,three=0;
     one=i-1;
     if(i%2==0)
     {
     two=i/2;
     }
     if(i%3==0)
     {
     three=i/3;
     }
     dp[i]=min(dp[one],min(dp[two],dp[three]))+1;

  }
  cout<<dp[n]<<endl;

	return 0;
}