/*Life is onetime offer ,use it well*/

#include<bits/stdc++.h>
using namespace std;
map<int, list<int>>l;
map<int, bool>vis;
vector<int>ans;
void DFS(int src)
{
  vis[src] = true;
  for (auto i : l[src])
  {
    if (!vis[i])
    {
      DFS(i);
    }
  }
  ans.push_back(src);

}

int main()
{
  int node, edge;
  cin >> node >> edge;
  while (edge--)
  {
    int from, to;
    cin >> from >> to;
    //edges are directed
    l[from].push_back(to);
  }
  ans.clear();
  for (int i = 1; i <= node; i++)
  {
    if (!vis[i])
    {
      DFS(i);
    }
  }

  reverse(ans.begin(), ans.end());
  for (auto i : ans) cout << i << " ";
  cout << endl;
  return 0;
}