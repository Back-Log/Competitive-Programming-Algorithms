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
int maxProfit(int profit[], int len)
{
  //Base case
  if (len == 0) return 0;
  //if value is already computed
  if (dp[len] != 0)
  {
    return dp[len];
  }
  //Let's compute what is the maximum profit that can made by cutting size of i
  //calculate best after each itration
  int best = INT_MIN;
  for (int i = 1; i <= len; i++)
  {
    int can = profit[i] + maxProfit(profit, len - i);
    best = max(can, best);

  }
//Let's memoize the solution
  return dp[len] = best;


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