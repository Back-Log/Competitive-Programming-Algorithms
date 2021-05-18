/*
  Life is onetime offer ,use it well
*/
#include<bits/stdc++.h>
using namespace std;
/*

Rod cuting Problem
1- Recursion +DP -> O(n^2) with function overhead
2- Buttom up DP -> O(n^2)

*/
int dp[1000];
int maxProfit(int profit[], int total)
{
//fill the intial dp
  dp[0] = 0;
  for (int len = 1; len <= total; len++)
  {
    int best = INT_MIN;
    //now we itrate till 1 starting from current length, and check which cut is based
    for (int i = len; i >= 1; i--)
    {
      best = max(best, profit[i] + dp[len - i]);

    }
    dp[len] = best;


  }

  return dp[total];


}

int main()
{
  //1 -based index
  int profit[] = {0, 1, 5, 8, 9, 10, 17, 17, 20};
  //size of array typiclly
  int totallength = 8;
  int ans = maxProfit(profit, totallength);

  cout << ans << endl;
  return 0;
}