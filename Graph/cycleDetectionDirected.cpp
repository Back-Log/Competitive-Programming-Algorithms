/*
  Life is onetime offer ,use it well
*/
#include<bits/stdc++.h>
using namespace std;
/*

 Algorithm to detect cycle in deirected graph using DFS
 Complexity= O(V+E)
 So here we need to creat to array one to mark a visited vertex and one to check that if current node was already visited in the current path

*/

const int N = 1e5 + 10;

vector<int>graph[N];
//vector to store the current path
vector<bool>path(N, false);
//visited vector
vector<bool>visited(N, false);


bool cycleDFS(int src)
{
  visited[src] = true;
  path[src] = true;

  for (auto child : graph[src])
  {
    if (!visited[child])
    {
      //calling dfs to find the cycle to next node
      bool cycleFound = cycleDFS(child);
      if(cycleFound==true)
          return true;

    }
    else if (path[child] == true)
    {
      return true;
    }


  }


//when we are leaving the cuurent node ,remove it from cuurent path
  path[src] = false;

  return false;

}
int main()
{

  int node, edge;
  cin >> node >> edge;

  while (edge--)
  {
    int from, to;
    cin >> from >> to;
    //directed
    graph[from].push_back(to);

  }
  bool cycleFound = false;
  for (int i = 0; i < node; i++)
  {
    if (cycleDFS(i))
    {
      cycleFound = true;
      break;
    }
  }
  if (cycleFound)
  {
    cout << "Found a cycle" << endl;

  }
  else
  {

    cout << "Cycle not found" << endl;

  }
  return 0;
}