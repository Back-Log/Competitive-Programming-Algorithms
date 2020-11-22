#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back
// template<typename T>
void addEdge(vector<int>G[],int u,int v)
{
 // let's assume that graph is bi-Directional
	G[u].pb(v);
	G[v].pb(u);
}
void PrintGraph(vector<int>G[],int n)
{
  for(int i=0;i<n;i++)
  {
  	cout<<i<<"->";
  	for(auto j:G[i])
  	{
  		cout<<j<<" ";
  	}
  	cout<<endl;
  }

}
int main()
{ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // Let's first take the input of number of verteses in graph
  int v;
  cin>>v;
  // vis number of vertex
  //now lwts creat a array of vectors
  vector<int>G[v];
  // Now creating a function to add the edges
  addEdge(G,0,1);
  addEdge(G,0,2);
  addEdge(G,2,1);
  addEdge(G,1,4);
  addEdge(G,3,2);
  addEdge(G,4,3);
  addEdge(G,0,4);
  PrintGraph(G,v);


  return 0;
}