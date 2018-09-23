#include <bits/stdc++.h>
using namespace std;

int main() {

	int sparse[100000][(int)log2(100000)]; 		// sparse[n][log2(n)]
	int a[100000] , n ,hi , lo , ans;

	//Input is not taken




	//-------------------------Algorithm starts------------------

	//---Preprocess starts------

	for(int i = 0; i < n; ++i)
		sparse[i][0] = a[i];


	for(int j = 1; pow(2,j) <= n; ++j) {
		
		//i + pow(2,j) -1  ==> as the highest range can't exceed the last index;

		// min(0,5) in 0,1,2,3,4 is  min( min(0,3) , min(4,5) );

		for(int i = 0; i+pow(2,j)-1 < n; ++i) {

			//operation here with the previously calculated 2 nodes
			
			sparse[i][j] = min(sparse[ i ][ j - 1 ] , sparse[ i + (int)pow(2,j) - 1 ][ j - 1 ] );	
		}
	} 

	//----Preprocess ends---

	//---Query starts

			//hi and lo variables are the highest and lowest range of the query

	//this l and k variables may need to be changed

	int l = hi - lo + 1;	
	int k = log2(l);

	ans = min(sparse[ lo ][ k ] , sparse[ lo + l - (int)pow(2,k) ][ k ] );

	//----Query ends

	return 0;
}
