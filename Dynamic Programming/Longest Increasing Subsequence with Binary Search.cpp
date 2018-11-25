// with Binary Search.
//Complexity O(nlogn)
//Memory complexity is linear

int lis(int a[] , int n) {
	vi dp(n+1,inf);
	dp[0] = -inf;
	for(int i = 0; i < n; ++i) {
		int j = (int)(upper_bound(all(dp) , a[i]) - dp.begin());
		if(dp[j-1] < a[i] && a[i] < dp[j])
			dp[j] = a[i];
	}
	int ans = 0;
	for(int i = 0; i <= n; ++i) {
		if(dp[i] < inf)
			ans = i;
	}
	return ans;
}
