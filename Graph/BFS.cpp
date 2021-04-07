#include<bits/stdc++.h>
using namespace std;
//creating templeted class
template<typename T>
class Graph{
  map<T,list<T>>mp;
public:
	void addEdge(int u,int v)
	{
     mp[u].push_back(v);
     mp[v].push_back(u);
	}
	void BFS(T src)
	{
      map<T,bool>visit;
      queue<T>q;
      q.push(src);
      visit[src]=true;
      while(!q.empty())
      {
        T val=q.front();
        q.pop();
        cout<<val<<" ";
        for(auto i:mp[val])
        {
        	if(!visit[i])
        	{
        		q.push(i);
        		//adding node conncected to corrent node
        		visit[i]=true;
        	}
        }
      }

	}
};



int main()
{
Graph<int>g;
g.addEdge(1,2);
g.addEdge(1,3);

g.addEdge(3,2);
g.addEdge(4,3);
g.addEdge(5,4);
g.BFS(1);

	return 0;
}