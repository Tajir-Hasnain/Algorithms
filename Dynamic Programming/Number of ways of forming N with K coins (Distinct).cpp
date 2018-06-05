/*
* If there are k coins, How many distinct ways are there to form n with this coins
* 11 = 1*11 , 5+5+1 , 10+1 , 5+1*6
* 5+1 and 1+5 are considered same here.That's why 'distinct' is used
* Memory Complexity : O(n);
* Time Complexity : O(n*k);
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_VALUE 8000
int main() {
	
	int coin[] = {1 , 5, 10, 25, 50} , k = 5; 	//as here is 5 coin
	int dp[MAX_VALUE];
	int n;

	memset(dp , 0 , sizeof(dp));

	dp[0] = 1;

	for(int j = 0; j < k; ++j) {
		for(int i = coin[j] , root = 0; i < MAX_VALUE; ++i , root++) 
			dp[i] += dp[root];
	}
	cin >> n;
	cout << dp[n] << endl;

	return 0;
}