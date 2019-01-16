class ArticulationPoint {
private:
	int node,edge,timer;
	vector < bool > vis;
	vector < int > tin,fup;
	set < int > art_point;
	set < pair < int , int > > art_bridge;
	vector < vector < int > > adj;

	void dfs(int u, int p = -1) {
		vis[u] = true;
		tin[u] = fup[u] = timer++;
		int children = 0;

		for(auto v : adj[u]) {
			if(v == p)	continue;
			if(vis[v]) 
				fup[u] = min(fup[u] , tin[v]);
			else {
				dfs(v,u);
				fup[u] = min(fup[u] , fup[v]);
				if(fup[v] > tin[u])  {
					art_point.insert(u);
					art_bridge.insert(make_pair(min(u,v) , max(u,v) ));
				}
				++children;
			}
		}
		if(p == -1 && children > 1)
			art_point.insert(u);
	}

	void find_cutpoints(vector < vector < int > > graph) {
		for(int i = 0; i < node; ++i) {
			if(!vis[i])
				dfs(i);
		}
	}
public:
	ArticulationPoint(vector < vector < int > > graph , int n) {
		node = n;
		adj = graph;
		timer = 0;
		vis.assign(n,false);
		tin.assign(n,-1);
		fup.assign(n,-1);

		find_cutpoints(graph);
	}

	set < int > getPoints() {
		return art_point;
	}

	set < pair < int , int > > getBridges() {
		return art_bridge;
	}
};
