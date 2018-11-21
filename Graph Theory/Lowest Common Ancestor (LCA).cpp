// Preprocessing Time : O(nlogn)
//Query Time : O(logn)

#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
#define MAX_ANC 30
#define pb push_back
typedef vector <int> vi;

vi graph[MAX];
int nodes , edges;

int size[MAX] , depth[MAX] , tin[MAX] , tout[MAX] , anc[MAX][MAX_ANC],timer;
bool vis[MAX];

void dfs(int u , int par = 1 , int d = 0) {
	vis[u] = true;
	depth[u] = d;
	tin[u] = timer++;
	size[u] = 1;
	anc[u][0] = par;

	for(int i = 1; i < MAX_ANC; ++i)
		anc[u][i] = anc[ anc[u][i-1] ][i-1];

	for(int i = 0; i < graph[u].size(); ++i) {
		int v = graph[u][i];
		if(!vis[v]) {
			dfs(v, u , d+1 );
			size[u] += size[v];
		}
	}

	tout[u] = timer++;

}

bool ancestor(int a, int b) {
	return ( (tin[a] <= tin[b] ) && (tout[b] <= tout[a] ) );
}

int go_up(int a, int b) {
	for(int i = MAX_ANC-1 ; i >= 0; --i) {
		if(!ancestor(anc[a][i],b))
			a = anc[a][i];
	}
	return a;
}

int lca(int a, int b) {
	if(ancestor(a,b))
		return a;
	else if(ancestor(b,a))
		return b;
	else
		return anc[go_up(a,b)][0];
}

int main() {
	int x,y;
	cin >> nodes >> edges;
	for(int i = 1; i <= edges; ++i) {
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}

	dfs(1);

	cin >> x >> y;
	cout << lca(x,y) << endl;
}
