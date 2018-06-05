#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m; // n = string size , m = pattern size
int pi[1000000]; //size = string length
string s,p;

void prefixFunction() {
	int j = 0 , i = 1;
	while(i < m) {						
		if(p[i] == p[j]) {
			pi[i] = ++j;
			++i;
		}
		else {
			if(j == 0) {
				pi[i] = 0;
				++i;
			}
			else
				j = pi[j-1];
		}
	}
}

bool kmp() {	//bool for checking if a substring exists or not, if number of subtring is asked,then return type will be ll
	
	prefixFunction();
	
	int i = 0 , j = 0;
//	int cnt = 0;
	while(i < n) {
		if(s[i] == p[j]) {
			++i;
			++j;
		}
		if(j == m) {		// m = pattern size
/*			
			cnt++;
			j = pi[j-1];		//for counting number of appearence of substring p in s;
*/
			return 1;		//for checking if a substring exists or not;comment this line for counting number of appearences.
		}
		if(s[i] != p[j]) {
			if(j == 0)
				++i;
			else
				j = pi[j-1];
		}
	}
	return false;
//	return cnt;		//for counting number of appearence of substring p in s;
}

int main() {
	cin >> s >> p;
	n = s.size();
	m = p.size();

	cout << kmp() << endl;

	return 0;
}