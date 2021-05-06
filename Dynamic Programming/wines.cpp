/**
*   Push yourself, because no one else is going to do it for you.
**/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
int dp[100][100];
int dp1[100][100];
int dpBottomUp(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    dp1[i][i] = arr[i] * n;
  }
  int times = n - 1;
  int year = 4;
  for (int i = 1; i < n; i++)
  {
    int loop = times;
    int row = 0;
    int col = i;
    while (loop--)
    {
      int op1 = arr[row] * year + dp1[row + 1][col];
      int op2 = arr[col] * year + dp1[row][col - 1];
      dp1[row][col] = max(op1, op2);
      col++;
      row++;
    }
    year--;
    times--;
  }

  return dp[0][n - 1];

}
int dpTopDown(int arr[], int l, int r, int y)
{
  if (l > r)
  {
    return 0;
  }
  if (dp[l][r] != 0)
  {
    return dp[l][r];
  }
  int op1 = arr[l] * y + dpTopDown(arr, l + 1, r, y + 1);
  int op2 = arr[r] * y + dpTopDown(arr, l, r - 1, y + 1);
  return dp[l][r] = max(op1, op2);


}
void solve()
{
  int arr[] = {2, 3, 5, 1, 4};
  int n = 5;
  cout << dpTopDown(arr, 0, 4, 1) << endl;
  cout << dpBottomUp(arr, n) << endl;


}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  while (t--)
  {
    solve();
  }


  return 0;
}
