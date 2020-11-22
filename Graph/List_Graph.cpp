#include<iostream>
#include<array>
#include<list>
#include<vector>
using namespace std;
class Graph{
// Public member for size of graph
 int V;
 // creating array of list (pointer)
 list<int>*l;
public:
  Graph(int v)
  {
  	V=v;
  	l=new list<int>[V];
  }
  void addEdge(int u,int v)
  {
  	// We are assuming that graph is Bi-directional
  	l[u].push_back(v);
  	l[v].push_back(u);
  }
  void PrintGraph()
  {
  	for(int i=0;i<V;i++)
  	{
  		cout<<i<<"->";
  		for(auto j:l[i])
  		{
  			cout<<j<<" ";
  		}
  		cout<<endl;
  	}
  }

};
int main()
{
  Graph g(5);
  g.addEdge(1,2);
  g.addEdge(1,3);
  g.addEdge(1,0);
  g.addEdge(0,2);
  g.addEdge(4,1);
  g.addEdge(2,3);
  g.addEdge(3,4);
 g.PrintGraph();



	return 0;
}