/**
*
* Algorithm Name: Fenwick Tree / Binary Indexed Tree (BIT)
* 
* Time Complextiy : 
*   • update : O(logn)
*   • query  : O(logn)
*
* Space Complexity: Ω(logn)
*
* Operations:
*   • Point update and range query
*   • Range update and point query
*
* Limitations:
*   • Cannot perform range update and range query. Refer to BIT_range_update_range_query.cpp
*   • Works only with reversible functions
*
* References:
*   • Implementation : https://cp-algorithms.com/data_structures/fenwick.html
*   • Research Paper : http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.14.8917&rep=rep1&type=pdf
*
* Precautions before use:
*   • Works only if function ƒ is reversible
*   • It uses zero-based indexing
*
 **/

class FenwickTree {

    vector < int > bit; // binary indexed tree
    int n;              // size of the bit
    
    bool point_update = true;
    bool point_query = true;
    int garbage = INT_MAX;

    /*
     * ƒ is a reversible function
     * Change ƒ to whatever the function is.
     * examples:
     *  • sum : l+r; (given)
     *  • min : min(l,r);
     *  • max : max(l,r);
     */
    int f(int l, int r) {
        return l+r;
    }

    /*
     * Used for point increament operation
     */
    void point_add(int idx, int value) {
        for(; idx < n; idx |= (idx+1))
            bit[idx] += value;
    }
    
    /*
     * Used for range increament operation
     */
    void range_add(int l, int r, int value) {
        point_add(l, value);
        point_add(r+1,-value);
    }

    void point_change(int idx, int value) {
        value = value - query(idx, idx);

        add(idx, value);
    }

public:
    
    //Constructors

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n,0);
    }

    FenwickTree(vector<int>a, bool point_update = true, bool point_query = true) : FenwickTree(a.size()) {
        for(size_t i = 0; i < a.size(); ++i)
            add(i,a[i]);

        this->point_update = point_update;
        this->point_query = point_query;
    }

    //------------End of constructors----------------------


    /*
     * Point query operation
     * Can be used with both: • Point update • Range update
     */

    int query(int r) {
        int ret = 0;
        for(; r >= 0; r = (r & (r+1))-1)
            ret = f(ret , bit[r]);
        return ret;
    }

    /*
     * Range Query operation
     * Can be used only with point update operation
     */
    int query(int l, int r) {

        //First check if range query can be used or not.
        if(point_update)
            return f(query(r) , query(l-1));
        else {
            //Show error message and return garbage for wrong operation.
            printf("[-] Sorry...Cannot use this operation for range update. :(\n");
            printf("[-] Returning garbage");
            return garbage;
        }
    }

    /*
     * Usage: 
     *  • When the value of the array is increamented, not updated
     *  • For point update
     */
    void add(int idx, int value) {
        point_add(idx,value);
    }

    /*
     * Usage:
     *  • When the value of the array is increamented, not updated
     *  • For range update
     *
     * Not to use when: range query is used. Refer to BIT_range_update_range_query.cpp
     */

    void add(int l, int r, int value) {
        //First check if range update can be used or not.
        if(!point_query)
            range_add(l,r,value);
        else {
            // Show error message for wrong operation
            printf("[-] Sorry...Cannot use this operation alongside range query. :(\n");
            printf("[-] Not updated.\n");
            return;
        }
        
    }
    
    /*
     * Usage: When the value of the index is updated, not increamented
     */
    void change(int idx, int value) {
        point_change(idx, value);
    }
};
