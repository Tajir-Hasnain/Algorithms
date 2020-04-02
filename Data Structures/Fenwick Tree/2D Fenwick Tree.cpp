
/*
*	Algorithm : Fenwick Tree for 2D matrix
*	Operation : Point update, range sum query ( Returns sum of a submatrix)
*	
*	Precautions:
*		0-based indexing is used
*		Point update, range query is used
*/

template < typename T>
class FenwickTree2D {
    vector < vector < T > > bit;
    int n,m;
 
public:
 
    FenwickTree2D(int n, int m) : n(n) , m(m) {
        bit.assign(n, vector < T > (m, 0));
    }

    /*
     *	Increments the value of a single point
     *
     *	For changing value of a point, update with 
     *		value = value - value in that particular point
     *		(store point values in a second 2D vector)
     **/

    void update(int x, int y, T value = 1) {
        for(int i = x; i < n; i |= (i+1))					// change to i <= n for 1-based indexing
            for(int j = y; j < m; j |= (j+1))				// change to j <= m for 1-based indexing
                bit[i][j] += value;
    }
 
    T query(int x, int y) {
        T ret = 0;
 
        for(int i = x; i >= 0; i = (i & (i+1)) - 1)			//change to i > 0 for 1-based indexing
            for(int j = y; j >= 0; j = (j & (j+1)) - 1)		//change to j > 0 for 1-based indexing
                ret += bit[i][j];
        return ret;
    }
 	
 	/*
 	 *
 	 *	Returns sum in a submatrix
 	 *
 	 */
    T query(int x1, int y1, int x2, int y2) {
 
        return query(x2,y2) - query(x2,y1-1) - query(x1-1,y2) + query(x1-1,y1-1);
    }
};
