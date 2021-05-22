
/*
  Life is onetime offer ,use it well
*/
#include<bits/stdc++.h>
using namespace std;

/*
 Shortest cycle in undirected and unweighted graph using BFS

Time complexity :- O(n^2)

We need to call BFS for every vertix because algorithm will give correct answer only when current node will bw in cycle.
*/
const int N = 1e5 + 10;
vector<int>graph[N];
void BFS(int src, int n, int &ans)
{
  //will store the distence of every node
  vector<int>dist(n + 1, INT_MAX);
  //need to keep track of parent to detect a backedge
  vector<int>parent(n + 1, -1);
  queue<int>q;
  q.push(src);
  dist[src] = 0;
  while (!q.empty())
  {
    int curr = q.front();
    q.pop();

    for (auto child : graph[curr])
    {
      //if the value of current node in distence array is INT_MAX means not visited
      if (dist[child] == INT_MAX)
      {
        dist[child] = 1 + dist[curr];
        q.push(child);
        parent[child] = curr;
      }
      //now if already visited we need to check back edge
      //we can also use the condition dist[child]>=dist[curr] to avoid creating parent array
      else if (parent[child] != curr and parent[curr] != child)
      {
        ans = min(ans, dist[curr] + dist[child] + 1);

      }



    }


  }


}
int main()
{
  int node, edge;
  cin >> node >> edge;
  while (edge--)
  {
    int from, to;
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  int shortCycle = INT_MAX;
// Calling BFS for every node
  for (int i = 1; i <= node; i++)
  {

    BFS(i, node, shortCycle);
    //we will update the ans when get the better ans

  }

  if (shortCycle == INT_MAX)
  {
    cout << "There is no cycle found" << endl;
  }
  else
  {
    cout << shortCycle << endl;

  }

  return 0;
}