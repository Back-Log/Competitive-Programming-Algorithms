/*Life is onetime offer ,use it well*/
#include<bits/stdc++.h>
using namespace std;
vector<int>graph[1001];
vector<bool>vis(1001);
//need of parent array to store the info. about cureent node parent
vector<int>parent(1001);
// Here we are going to find the cycle using BFS treversal
bool isCycle(int src)
{
  vis[src] = true;
  queue<int>q;
  q.push(src);
  while (!q.empty())
  {
    int node = q.front();
    q.pop();

    for (auto i : graph[node])
    {
      if (vis[i] == true and parent[node] != i)
      {
        return true;
      }
      else if (!vis[i])
      {
        vis[i] = true;
        q.push(i);
        parent[i] = node;

      }
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
  cout << isCycle(start) << endl;
  return 0;
}