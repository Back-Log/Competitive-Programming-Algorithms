/*Life is onetime offer ,use it well*/
#include<bits/stdc++.h>
using namespace std;
vector<int>graph[1001];
vector<bool>vis(1001);

//So we are going to check the cycle using DFS
bool isCycle(int src, int parant)
{
  vis[src] = true;
  for (auto child : graph[src])
  {
    if (!vis[child])
    {
      // So here we call recurcivly for next conected node and check cycle is found or not
      bool nextFind = isCycle(child, src);

      return nextFind;
    }
    else if (vis[child] == true and child != parant)
    {
      //this means that cycle is present
      return true;
    }


  }

  return false;

}


int main()
{
  // taking input of the graph
  int node, edge;
  cin >> node >> edge;
  while (edge--)
  {
    int from, to;
    cin >> from >> to;
    graph[to].push_back(from);
    graph[from].push_back(to);
  }

  cout << boolalpha;
  int start = 1;
  cout << isCycle(start, -1) << endl;
  return 0;
}