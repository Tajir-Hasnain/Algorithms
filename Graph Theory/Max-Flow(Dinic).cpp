#include<bits/stdc++.h> 
using namespace std;

//typedefs

typedef vector<int> vi;

//defines

#define pb emplace_back
#define F first
#define S second
#define mp make_pair
#define all(c)		c.begin(),c.end()
#define RESET(a,b)	memset(a,b,sizeof(a))
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int inf = 2000000000;


int n,m,source,sink;

vi graph[1000];
int f[101][101] , c[101][101];
int level[1000];

bool bfs() {
	
	//its a normal BFS that starts from the source. (To get shortest path to all nodes from the source)

	RESET(level, -1);
	
	queue < int > q;
	
	q.push(source);
	
	level[source] = 0;
	
	while(!q.empty()) {
	
		int top = q.front();
	
		q.pop();
	
		for(int i = 0; i < graph[top].size(); ++i) {
	
			int v = graph[top][i];
	
			if(level[v] == -1 && f[top][v] < c[top][v]) {	//the node is not visited 
															//and the flow in the node < its capacity
	
				level[v] = level[top] + 1;
	
				q.push(v);
	
			}
	
		}
	
	}
	
	return level[sink] != -1;	//Return wheather there is a path available or not 
								//i.e. the sink is visited or not in the bfs
}

int dfs(int u , int flow) {
	
	if(flow == 0)	return flow;	//blocked path
	
	if(u == sink)	return flow;	//the dfs reached the sink

	for(int i = 0; i < graph[u].size(); ++i) {
	
		int v = graph[u][i];
	
		if(level[v] != level[u] + 1)	continue;		//if the edge is not in the shortest path from u to v
														//this level is from the bfs above
	
		int pushed = dfs(v , min( flow , c[u][v] - f[u][v] ) );		//Let's see if we get any flow from this path / not
		
		if( pushed ) {												// If the flow from this node to sink is not 0
	
			f[u][v] += pushed;										//Increament its flow 
	
			f[v][u] -= pushed;
	
			return pushed;
	
		}
	
	}
	
	return 0;
}

int dinic() {

	int flow = 0;
	
	while(bfs()) {		//While there is a flowable path from source to sink
	
		while(int pushed = dfs(source,inf)) 	//Get the minimum flow that can be pushed in the path
	
			flow += pushed;						//Increase the flow
	
	}
	
	return flow;
}

int main()
{
	optimize();

	int u,v,w,kase = 0;

	cin >> n;					//Total Nodes

	cin >> source >> sink;		//source,sink

	cin >> m;					//number of edges

	for(int i = 0; i < m; ++i) {

		cin >> u >> v >> w;		//edge from node u to v with capacity w

		graph[u].pb(v);

		graph[v].pb(u);			//If bidirectional

		c[u][v] += w;	//If there is multiple edges between two nodes

		c[v][u] += w;			//If bidirectional

	}

	cout << dinic() << endl;
	
	return 0;
}






//?
