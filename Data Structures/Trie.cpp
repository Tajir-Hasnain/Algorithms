#include <bits/stdc++.h>
using namespace std;


int trie[5*50000][26],finish[5*500000];
int nxt = 1;

void add(string s) {
	int node = 0;
	for(int i = 0; s[i] != '\0'; ++i) {
		if(trie[node][s[i]-'a'] == 0)
			node = trie[node][s[i]-'a'] = nxt++;
		else
			node = trie[node][s[i]-'a'];
	}
	finish[nxt-1] = 1;
}

bool find(string s) {
	int idx = 0;

	for(int i = 0; i < s.size(); ++i) {
		if(trie[idx][s[i]-'a'] == 0)
			return false;
		else
			idx = trie[idx][s[i]-'a'];
	}
	return true;
}

int main() {
	string s;

	int n,m;

	cin >> n >> m;

	while(n--) {
		cin >> s;
		add(s);
	}
	while(m--) {
		cin >> s;

		if(find(s))
			cout << "Found" << endl;
		else
			cout << "Not Found" << endl;
	}
}