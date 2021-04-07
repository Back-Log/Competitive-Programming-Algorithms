#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
 map<T,list<int>>mp;

 public:
 	void addEdge(int v,int u)
 	{
 		mp[u].push_back(v);
 		mp[v].push_back(u);
 	}
   void SSSP_BFS(T src)
   {
     map<T,int>dist;
     queue<T>q;
     for(auto i:mp)
     {
       auto val=i.first;
       dist[val]=INT_MAX;

     }
   dist[src]=0;
   q.push(src);
   while(!q.empty())
   {
    T val=q.front();
    q.pop();
    for(auto i:mp[val])
    {
    	if(dist[i]==INT_MAX)
    	{
          q.push(i);
          dist[i]=dist[val]+1;
    	}
    }


   }
   for(auto i:mp)
   {
   	T val=i.first;
   	cout<<"Dist. from "<<src<<" To "<<val<<" Is "<<dist[val]<<endl;
   }

   }


};


int main()
{

Graph<int>g;
g.addEdge(0,1);
g.addEdge(0,3);
g.addEdge(1,2);
g.addEdge(3,4);
g.addEdge(4,5);
g.addEdge(2,3);
g.SSSP_BFS(0);

return 0;

}