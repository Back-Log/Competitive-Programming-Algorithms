/*
  Life is onetime offer ,use it well
*/
#include<bits/stdc++.h>
using namespace std;
/*
  Longest common subsequence
  ex- 4 3 5 2 6 ->heare ans=3 (4,5,6)

 Time complexity ->O(n^2)

*/

int dp[100];

int LIS(vector<int>&arr, int n)
{
  //Every element is indivusual a subseqence so fil 1 at every index
  for (int i = 0; i < n; i++)
  {
    dp[i] = 1;
  }

//now let's fill the dp
  int best = -1;
  for (int i = 1; i < n; i++)
  {
    for (int j = i - 1; j >= 0; j--)
    {
      if (arr[i] >= arr[j])
      {
        dp[i] = max(dp[i], dp[j] + 1);
      }

    }
    best = max(best, dp[i]);
  }


  return best;

}

int main()
{

  int n;
  cin >> n;
  vector<int>seq(n);
  for (int i = 0; i < n; i++)
  {
    cin >> seq[i];
  }

  cout << LIS(seq, n) << endl;
  return 0;
}