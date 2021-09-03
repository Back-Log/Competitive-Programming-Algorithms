#include<bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 100;
vector<int>g[N];
vector<bool>vis(N);

void BFS(int src)
{
  queue<int>q;
  q.push(src);
  vis[src] = true;
  while (!q.empty())
  {
    int val = q.front();
    q.pop();
    for (auto i : g[val])
    {
      if (!vis[i])
      {
        q.push(i);
        //adding node conncected to corrent node
        vis[i] = true;
      }
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
//creating templeted class
// template<typename T>
// class Graph{
//   map<T,list<T>>mp;
// public:
//  void addEdge(int u,int v)
//  {
//      mp[u].push_back(v);
//      mp[v].push_back(u);
//  }
//  void BFS(T src)
//  {
//       map<T,bool>visit;
//       queue<T>q;
//       q.push(src);
//       visit[src]=true;
//       while(!q.empty())
//       {
//         T val=q.front();
//         q.pop();
//         cout<<val<<" ";
//         for(auto i:mp[val])
//         {
//          if(!visit[i])
//          {
//            q.push(i);
//            //adding node conncected to corrent node
//            visit[i]=true;
//          }
//         }
//       }

//  }
// };



// int main()
// {
// Graph<int>g;
// g.addEdge(1,2);
// g.addEdge(1,3);

// g.addEdge(3,2);
// g.addEdge(4,3);
// g.addEdge(5,4);
// g.BFS(1);

//  return 0;
// }