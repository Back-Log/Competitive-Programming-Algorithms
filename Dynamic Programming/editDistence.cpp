/*
  Life is onetime offer ,use it well
*/
#include<bits/stdc++.h>
using namespace std;

/*

Edit Distance problem ,Given str1 and str2 ,minimum number of opration to covert str1 to str2
-> we can perform three opration Replace,insert,delete
->Recusrion solution O(3^n) exponential
->DP O(n^2)

*/
int n, m;
  int dp[100][100];
int recursiveDP(string in, string out, int i, int j)
{

  //this needs to fix gives wrong ans on hello ->hell
  if (i == n)
  {
    return 0;
  }
  if (j == m)
  {
    return 0;
  }
  if (dp[i][j] != 0)
  {
    return dp[i][j];
  }
  if (in[i] == out[j])
  {
    return dp[i][j] = recursiveDP(in, out, i + 1, j + 1);
  }
  //if ythe current charchter is not equal than we have 3 options
  int repalce =  recursiveDP(in, out, i + 1, j + 1);
  int del = recursiveDP(in, out, i + 1, j);
  int insrt = recursiveDP(in, out, i, j + 1);

  return dp[i][j] = 1 + min(repalce, min(del, insrt));

}
int bottomUpDP(string in, string out)
{
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 0;
  //now let's fill the first row
  for (int i = 1; i <= m; i++)
  {
    dp[0][i] = 1 + dp[0][i - 1];
  }
//first colmn
  for (int i = 1; i <= n; i++)
  {
    dp[i][0] = 1 + dp[i - 1][0];
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      //now we have three case consider all
      int op1=dp[i-1][j-1];
      int op2=dp[i-1][j];
      int op3=dp[i][j-1];
      //if current charcter is same we don't need to do any thing
      dp[i][j]=min({op1,op2,op3})+(in[i-1]!=out[j-1]);
    }
    
  }

  return dp[n][m];

}
int main()
{
  string input, output;
  cin >> input >> output;
  n = input.size();
  m = output.size();
  cout << recursiveDP(input, output, 0, 0) << endl;
  cout << bottomUpDP(input, output) << endl;

  return 0;
}