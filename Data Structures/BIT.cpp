#include <bits/stdc++.h>
using namespace std;

int a[112345], bit[112345]; //linear

void update(int idx, int val) {
	while(idx <= n) {
		bit[idx] += val;
		idx += (idx & -idx);
	}
}

int query(int idx) {
	int sum = 0;
	while(idx > 0) {
		sum += bit[idx];
		idx -= (idx & -idx); 
	}	
}

void build(void) {
	for(int i = 0; i < n; ++i)
		update(i+1, a[i]);
}

int main() {
	return 0;
}