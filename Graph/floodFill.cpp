#include<bits/stdc++.h>
using namespace std;
const int f = 2;
//dx and dy is used to genrate the possible left,right ,up and down co-ordinate
int dx[] = { -1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
/*

Flood fill Algorithm
Here the input matrix is only contain 0s and 1s, and we need to determine if there exist a path from (1,1) to (n,m)
you can't move if current cell contains 0

*/

void floodFill(int i, int j, int n, int m, vector<vector<int>>&mat)
{
  //checking boundery condition
  if (i < 0 or j < 0)
  {
    return;
  }
  if (i > n or j > m)
  {
    return;
  }

  if (mat[i][j] != 1)
  {
    return;
  }
  mat[i][j] = f;
  for (int k = 0; k < 4; k++)
  {
    floodFill(i + dx[k], j + dy[k], n, m, mat);
  }
}
int main()
{
  int n, m;
//given 1 based indexing
  cin >> n >> m;
  vector<vector<int>>mat(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> mat[i][j];
    }
  }
  floodFill(0, 0, n - 1, m - 1, mat);
  //so if we able to fill last cel with 2 than we found a path
  if (mat[n - 1][m - 1] == 2)
  {
    cout << "Yes";
  }
  else
  {
    cout << "No";
  }
  return 0;

}