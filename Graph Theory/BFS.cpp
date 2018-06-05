#include <bits/stdc++.h>
using namespace std;
int main() 
{	
//	freopen("input.txt","r",stdin);

	//Variable declaration
	int n,m,x,y,starting_node,ending_node;
	int level[1000];			//For shortest path.
	bool vis[1000];				//For tracking which nodes have been visited already

	vector<int> v[1000];		//for storing the graph.
	queue<int> q;				//for BFS operation

	//Initialization
	memset(level,0,sizeof(level));
	memset(vis,false,sizeof(vis));

	//Number of vertices (n) and number of edges (m).
	cin >> n >> m;
	
	for(int i = 0; i < m; i++)
	{	
		//Edges input
		cin >> x >> y;
		v[x].push_back(y);		//storing in graph.
		v[y].push_back(x);
	}

	//Input starting node of the required path.
	cin >> starting_node;

	//Initialize the queue with the starting node.
	q.push(starting_node);
	level[starting_node] = 0;	//Shortest path from starting node to itself is zero.
	vis[starting_node] = true;

	while(!q.empty())
	{
		int top = q.front();
		q.pop();
		for(int i = 0; i < v[top].size(); i++)		//Iterate through all the nodes that are directly connected with the 'top' node
		{
			int x = v[top][i];
			if(!vis[x]) 	//If this node is yet not visited.Then put it in the queue
			{
				level[x] = level[top] + 1;	//Update its level.
				vis[x] = true;				//Mark this node as visited.
				q.push(x);
			}
		}
	}

	for(int i = 1; i <= n; ++i)
		cout << level[i] << " ";

	return 0;
}