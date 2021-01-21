#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back
template<typename T>
class Graph
{
  map<T,list<T>>l;
  public:
  	//cunstructor
  	Graph()
  	{

  	}
   void addEdge(T u,T v)
   {
    l[u].push_back(v);
    l[v].push_back(u);
   }
   void print()
   {
   	for(auto i:l)
   	{
   		cout<<i.first<<"->";
   		for(auto j:i.second)
   		{
   			cout<<j<<" ";
   		}
   		cout<<endl;
   	}
   }
  void BFS(T source)
   {
      queue<T>q;
      q.push(source);
      map<T,bool>visited;
      while(!q.empty())
      {
       T node=q.front();
       cout<<node<<" ";
       q.pop();
       visited[node]=true;
       for(auto i:l[node])
       {
       	 if(!visited[i])
       	 {
       	 	q.push(i);
       	 	visited[i]=true;
       	 }
       }
      
      }

    cout<<endl;

   }

};
/*
a->b
a->e
a->f
e->b
e->g
b>h
b>f
g>f
g->h
h>f





*/
int main()
{ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Graph<string> g;
  g.addEdge("a","b");
  g.addEdge("a","e");
  g.addEdge("a","f");
  g.addEdge("e","b");
  g.addEdge("e","g");
  g.addEdge("b","h");
  g.addEdge("g","f");
  g.addEdge("b","f");
  g.addEdge("g","h");
  g.addEdge("h","f");
  // g.print();
  g.BFS("h");

  return 0;
}
