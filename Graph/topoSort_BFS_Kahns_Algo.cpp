/*
Life is onetime offer ,use it well
*/
#include<bits/stdc++.h>
using namespace std;
/* Finding topological order for given graph using BFS

   AKA :- Kahn's Algorithm

   Time Complexity-> O(V+E)

*/

vector<int>graph[1001];
// vector for storing the in-degree of every vertex
vector<int>inDegree;
//to store the answer
vector<int>ans;
void topoSort()
{
  queue<int>q;
  for (int i = 0; i < inDegree.size(); i++)
  {
    if (inDegree[i] == 0)
    {
      q.push(i);
    }
  }
  while (!q.empty())
  {
    auto val = q.front();
    debug(val);
    ans.push_back(val);
    q.pop();
    for (auto i : graph[val])
    {
      inDegree[i]--;
      if (inDegree[i] == 0)
      {
        q.push(i);
      }
    }

  }


}
int main()
{
  int node, edge;
  cin >> node >> edge;
  inDegree.clear();
  inDegree.resize(node);
  for (int i = 0; i < edge; i++)
  {
    int from, to;
    cin >> from >> to;
    graph[from].push_back(to);
    //need to update the indegree of node (to)
    inDegree[to]++;
  }
  topoSort();
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}