#include<bits/stdc++.h>
using namespace std;
int main()
{
  int coins[]={1,2,5,10,20,50,100,200,500,2000};
  //number of coin you want to make a change
  int n;
  cin>>n;
  int dp[10000]={0};
  int mi=INT_MAX;
  for(int i=1;i<=n;i++)
  {
  	mi=INT_MAX;
  	for(auto c:coins)
  	{
  		if(i-c>=0)
  		{
          mi=min(mi,dp[i-c]);
  		}
  	}
  	dp[i]=mi+1;
  }
 
 cout<<dp[n]<<endl; 

return 0;

}