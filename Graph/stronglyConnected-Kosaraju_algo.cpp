/*
  Life is onetime offer ,use it well
*/
#include<bits/stdc++.h>
using namespace std;

/*

 We are going to implement Kosaraju's Algorithm to find the strongly connected component
 Time complexity- O(V+E)
 steps:
 1- Creat a ordering stack
 2- Reverse a graph
 3- call a DFS on stack's top and pop it and again till all visited


*/



const int N = 1e5 + 10;

vector<int>graph[N];
vector<int>reverseGraph[N];
vector<bool>visited(N, false);
vector<int>order;
void DFS(int curr)
{
	visited[curr] = true;
	for (auto child : graph[curr])
	{
		if (!visited[child])
		{
			DFS(child);
		}

	}
	//when we are comming back from any node ,we need to push the node

	order.push_back(curr);

}
void reverseDFS(int curr)
{
	visited[curr] = true;
	//Here we can also store the nodes of the graph for any perticular connected component
	for (auto child : reverseGraph[curr])
	{
		if (!visited[child])
		{
			reverseDFS(child);
		}

	}


}
int main()
{
	int node, edge;
	cin >> node >> edge;
	while (edge--)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		reverseGraph[to].push_back(from);
	}
	//now we will call the DFS to store the ordering
	for (int i = 1; i <= node; i++)
	{
		if (!visited[i])
		{
			DFS(i);
		}

	}
	//We need to reset the visited
	fill(visited.begin(), visited.end(), false);
	// Now need to call the DFS from order vector
	//we can use diffrent color for diffrent connected component
	//we can also use array of vector to store the all the node of single connected component

	int totalSSC = 0;
	// Here we have to use reverse graph
	for (int i = node - 1; i >= 0; i--)
	{
		if (!visited[order[i]])
		{
			reverseDFS(order[i]);

			totalSSC++;
		}

	}
	cout << totalSSC << endl;
	return 0;
}