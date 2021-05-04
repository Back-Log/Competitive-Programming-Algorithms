/*
Life is onetime offer ,use it well
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>graph[1001];
int vis[1001];

bool cycle = 0;
void bipartiteDFS(int src, int parent, int color)
{
  //vis[i]==0 means the node is not visited
  //vis[node]=1 ->some color
  //vis[node]=2 ->some diffrent color
  vis[src] = color;
  //we node to change the color alternativly
  for (auto child : graph[src])
  {
    if (!vis[child])
    {
      //3-color will change color alternat
      bipartiteDFS(child, src, 3 - color);
    }
    else if (child != parent and color == vis[child])
    {
      //If we found a backedge means a cycle
      //and than we are cheking that color of adjecent vertix is same or not
      cycle = true;

    }
  }

}
int main()
{
  //taking input for graph
  int n, m;
  cin >> n >> m;
  while (m--)
  {
    int from, to;
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);

  }
//calling DFS to check weather we can color all the nodes of the graph or not
  //starting coloring with 1
  bipartiteDFS(1, 0, 1);
  if (cycle)
  {
    cout << "Not Bipartite\n";
  }
  else
  {
    cout << "Bipartite\n";
  }

  return 0;
}