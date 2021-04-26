//Finding conected component in undirected graph
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
template<typename T>
class Graph{
 public:
 map<T,list<T>>l;
map<T,bool>visited;
 void addEdge(int u,int v)
 {
  l[u].pb(v);
  l[v].pb(u);
 }

 void DFS(T src)
 {
  visited[src]=true;
  // cout<<src<<" ";
  for(auto i:l[src])
  {
    if(!visited[i])
    {
      DFS(i);
    }
  }
 }
 int count=0;
int total_connected_component()
{
 for(auto i:l)
 {
  auto node=i.first;
  //as many times the node is not visited ,than this will contribute to a diffrent component of a graph
  // beacuse for any given sourse node in 1 dfs call we can treverse all nodes of the graph
  if(!visited[node])
  {
    DFS(node);
    count++;
  }
 }


return count;

}

};
int main()
{
  Graph<int>g;
  g.addEdge(0,1);
  g.addEdge(0,3);
  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(3,4);
  g.addEdge(4,5);
  g.DFS(0);
cout<<g.total_connected_component()<<endl;

  return 0;
}
