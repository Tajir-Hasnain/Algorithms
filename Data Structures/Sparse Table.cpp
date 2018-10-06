#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int f(int x, int y) {
	return min(x,y);
}

int main() {

	int sparse[MAXN][(int)log2(MAXN)]; 		// sparse[n][log2(n)]
	int a[MAXN] , n ,hi , lo , ans;

	//Input is not taken




	//-------------------------Algorithm starts------------------

	//---Preprocess starts------

	int log[MAXN+1];

	log[1] = 0;
	
	for (int i = 2; i <= MAXN; i++) 
    		log[i] = log[i/2] + 1;

	for(int i = 0; i < n; ++i)
		sparse[i][0] = a[i];


	for(int j = 1; (1 << j) <= n; ++j) {
		
		//i + (1<<j)  ==> as the highest range can't exceed the last index;

		// min(0,5) in 0,1,2,3,4 is  min( min(0,3) , min(4,5) );

		for(int i = 0; i+(1 << j) <= n; ++i) {

			//operation here with the previously calculated 2 nodes
			
			sparse[i][j] = f(sparse[ i ][ j - 1 ] , sparse[ i + (1 << (j - 1) ) ][ j - 1 ] );	
		}
	}

	//----Preprocess ends---

	//---Query starts

	//Range Minimum Query

			//hi and lo variables are the highest and lowest range of the query

	//this name of the k variable may need to be changed

	int k = log[hi - lo + 1];

	ans = min(sparse[ lo ][ k ] , sparse[ hi - (1 << k) + 1 ][ k ] );


	//Range Sum Query
		//The preprocess function will be f(x,y) = x+y instead of f(x,y) = min(x,y)

	//----------To answer the sum query for the range [L,R], we iterate over all powers of two, starting from the biggest one. 
	//------------As soon as a power of two 2j is smaller or equal to the length of the range (=R−L+1), 
	//--------------we process the first the first part of range [L,L+2j−1],
	//----------------and continue with the remaining range [L+2j,R].

	long long sum = 0;
	for (int j = log[n]+1 ; j >= 0; j--) {
	    if ((1 << j) <= (hi - lo + 1) ) {
	        sum += sparse[lo][j];
	        lo += (1 << j);
	    }
	}

	//----Query ends

	return 0;
}
