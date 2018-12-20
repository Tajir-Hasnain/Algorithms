class ArticulationPoint {
private:
	int node,edge,timer;
	vector < bool > vis;
	vector < int > tin,fup,art_point;
	vector < vector < int > > adj;

	void dfs(int u, int p = -1) {
		vis[u] = true;
		tin[u] = fup[u] = timer++;
		int children = 0;

		for(auto v : graph[u]) {
			if(v == p)	continue;
			if(vis[v]) 
				fup[u] = min(fup[u] , tin[v]);
			else {
				dfs(v,u);
				fup[u] = min(fup[u] , fup[v]);
				if(fup[v]>= tin[u] && p != -1) 
					art_point.pb(u);
				++children;
			}
		}
		if(p == -1 && children > 1)
			art_point.pb(u);
	}

	void find_cutpoints(vector < vector < int > > graph) {
		for(int i = 0; i < n; ++i) {
			if(!vis[i])
				dfs(i);
		}
	}
public:
	ArticulationPoint(vector < vector < int > > graph , int n, int m) {
		node = n;
		edge = m;
		adj = graph;
		timer = 0;
		vis.assign(n,false);
		tin.assign(n,-1);
		fup.assign(n,-1);

		find_cutpoints();
	}

	vector < int > getPoints() {
		return art_point;
	}
};
