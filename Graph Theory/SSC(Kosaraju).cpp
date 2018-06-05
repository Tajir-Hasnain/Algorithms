/*
*The nodes are numbered from 0 - ( n-1 )
*Finding the Strongly Connected Components
*Kosaraju's Algorithm
*
*
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair< int, int > pii;
typedef vector < pii > vii;
typedef vector < int > vi;
typedef long long ll;

#define MAX 100000
#define mp make_pair
#define pb push_back
#define F first
#define S second

vi graph[MAX];
pii backEdge[3*MAX];
int n,m;
bool vis[MAX];
stack < int > store;

void dfs1(int u) {
	vis[u] = true;

	for( auto v : graph[u] ) {
		if( !vis[ v ] )
			dfs1(v);
	}
	store.push( u );
}

void dfs2(int u) {
	vis[u] = true;

	for(auto v : graph[u]) {
		if(!vis[v]) {
			cout << v+1 << " ";
			dfs2(v);
		}
	}
}

int main() {

	#ifdef tajir
		freopen("../input.txt" , "r" , stdin);
	#endif

	cin >> n >> m;

	for(int i = 0; i < m; ++i) {
		int x,y;
		cin >> x >> y;
		--x , --y;
		backEdge[i] = mp( y,x );
		graph[x].pb(y);
	}

	for(int i = 0; i < n; ++i) {
		if( !vis[ i ] )
			dfs1(i);
	}

	for(int i = 0; i < n; ++i)	graph[i].clear();

	for(int i = 0; i < m; ++i)
		graph[ backEdge[i].F ].pb( backEdge[i].S );

	int cnt = 0;

	memset(vis, false, sizeof(vis) );

	while( !store.empty() ) {
		int u = store.top();
		store.pop();

		if( vis[u] )	continue;

		cout << "SCC no " << ++cnt << ": " << u+1 << " ";

		dfs2(u);
		cout << endl;
	}

	return 0;
}