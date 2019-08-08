class Dinic {
	int n,m,source,sink;

	vector < vector < int > > graph,f,c;
	vector < int > level;

	bool bfs() {
		
		//its a normal BFS that starts from the source. (To get shortest path to all nodes from the source)

		level.assign(n+1,-1);

		queue < int > q;
		
		q.push(source);
		
		level[source] = 0;
		
		while(!q.empty()) {
	
			int top = q.front();
				
			q.pop();
		
			for(int i = 0; i < graph[top].size(); ++i) {
		
				int v = graph[top][i];
				
				if(level[v] == -1 && f[top][v] < c[top][v]) {	//the node is not visited and the flow in the node < its capacity
		
					level[v] = level[top] + 1;
		
					q.push(v);
		
				}
		
			}
		
		}
		
		return level[sink] != -1;	//Return wheather there is a path available or not i.e. the sink is visited or not in the bfs
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
public:

	Dinic(int nodes,int edges, vector < vector < int > > g, vector < vector < int > > cost,int sc, int sk) {
		n = nodes , m = edges;

		graph = g , c = cost;
		level.assign(n+1,-1);
		source = sc , sink = sk;
		f.assign(n+1,vector<int>(n+1,0));

	}

	int MaxFlow() {

		int flow = 0;
		
		while(bfs()) {		//While there is a flowable path from source to sink
			
			while(int pushed = dfs(source,inf)) {	//Get the minimum flow that can be pushed in the path
				
				flow += pushed;						//Increase the flow
			}
		}
		
		return flow;
	}
};
