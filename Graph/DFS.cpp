#include<bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 100;
vector<int>g[N];
vector<bool>vis(N);
void DFS(int src)
{
  vis[src] = true;
  for (auto i : g[src])
  {
    if (!vis[i])
    {
      DFS(i);
    }
  }
}
int main()
{

  for (int i = 0; i < N; i++)
  {
    g[i].clear();
  }
  vis.clear();
  vis.resize(N);


  return 0;
}
/*
template<typename T>
class Graph{
 public:
 map<T,list<int>>l;
map<T,bool>visited;
 void addEdge(int u,int v)
 {
  l[u].pb(v);
  l[v].pb(u);
 }
 map<T,bool>visited;
 void DFS(T src)
 {
  visited[src]=true;
  cout<<src<<" ";
  for(auto i:l[src])
  {
    if(!visited[i])
    {
      DFS(i);
    }
  }
 }


};
int main()
{
  graph<int>g;
  g.addEdge(0,1);
  g.addEdge(0,3);
  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(3,4);
  g.addEdge(4,5);
  g.DFS(0);


  return 0;
}
*/
