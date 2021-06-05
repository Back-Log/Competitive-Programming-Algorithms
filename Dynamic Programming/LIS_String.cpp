/*
  Life is onetime offer ,use it well
*/
#include<bits/stdc++.h>
using namespace std;

/*
 Given two string s1 and s2, we need to find the longest common subsequence in both the strings
 Time complexity - O(n^2)
  Ex- s1- nemgata
     s2=empty

     ans= 3 (e,m,t)

*/
int dp[100][100];

int recurseLIS(string s1, string s2, int n, int m)
{
  if (m == 0 or n == 0)
  {
    return 0;
  }
  if (s1[n - 1] == s2[m - 1])
  {
    return 1 + recurseLIS(s1, s2, n - 1, m - 1);
  }

  int op1 = recurseLIS(s1, s2, n - 1, m);
  int op2 = recurseLIS(s1, s2, n, m - 1);
  return max(op1, op2);

}

int bottomUpLIS(string s1, string s2, int n, int m)
{

  for (int i = 0; i <= n; i++)
  {
    dp[i][0] = 0;
  }

  for (int i = 0; i <= m; i++)
  {
    dp[0][i] = 0;
  }
  for (int i = 1; i <= n; i++)
  {

    for (int j = 1; j <= m; j++)
    {
      int op1;
      if (s1[i - 1] == s2[j - 1])
      {
        op1 = 1 + dp[i - 1][j - 1];
      }
      else
      {
        op1 = max(dp[i - 1][j], dp[i][j - 1]);
      }
      dp[i][j] = op1;
    }


  }



  return dp[n][m];
}
int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.size();
  int m = s2.size();
  cout << recurseLIS(s1, s2, n, m) << endl;
  cout << bottomUpLIS(s1, s2, n, m) << endl;

  return 0;
}