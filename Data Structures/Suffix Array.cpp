#include <bits/stdc++.h>
using namespace std;

#define all(c)	c.begin(),c.end()
#define mp 		make_pair
typedef vector < int > vi;
typedef pair < int , int > pii;

vi p,c,cnt;
const int alp = 26;

void scs(string s) {
	int n = s.size();
	p.resize(n);
	c.resize(n);
	cnt.resize(max(n,alp),0);

	for(int i = 0; i < n; ++i)
		cnt[s[i]-'a']++;
	for(int i = 1; i < alp; ++i)
		cnt[i] += cnt[i-1];

	for(int i = 0; i < n; ++i)		
		p[--cnt[s[i]-'a']] = i;
	c[p[0]] = 0;
	int cls = 0;

	for(int i = 1; i < n; ++i) {
		if(s[p[i]] != s[p[i-1]]) 
			cls++;
		c[p[i]] = cls;
	}
	vi pn(n);

	for(int k = 0; (1<<k) < n; ++k) {
		for(int i = 0; i < n; ++i) {
			pn[i] = p[i] - (1<<k);
			pn[i] += ((pn[i] < 0) ? n : 0);
		}
		fill(all(cnt) , 0);

		for(int i = 0; i < n; ++i)
			cnt[c[pn[i]]]++;
		for(int i = 1; i <= cls; ++i)
			cnt[i] += cnt[i-1];

		for(int i = n-1; i >= 0; --i) 
			p[--cnt[c[pn[i]]]] = pn[i];

		c[p[0]] = 0;
		cls = 0;
		for(int i = 0; i < n; ++i) {
			pii a = mp(c[p[i]] , c[(p[i] + (1<<k))%n]);
			pii b = mp(c[p[i-1]] , c[(p[i-1] + (1<<k))%n]);

			if(a != b)
				cls++;
			c[p[i]] = cls;
		}
	}
}

int main() {

	string s;

	cin >> s;
	
	scs(s);

	for(auto n : p)
		cout << n << " ";
	cout << endl;

	return 0;
}