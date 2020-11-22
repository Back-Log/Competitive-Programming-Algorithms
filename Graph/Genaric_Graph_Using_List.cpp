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
int main()
{ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Graph<string> g;
  g.addEdge("A","B");
  g.addEdge("A","C");
  g.addEdge("B","D");
  g.addEdge("A","K");
  g.addEdge("B","C");
  g.addEdge("I","B");
  g.addEdge("K","B");
  g.print();
  g.BFS("A");

  return 0;
}