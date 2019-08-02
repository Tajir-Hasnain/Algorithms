#define MAX 112345
#define lc (node<<1)
#define rc (lc+1)

ll st[4*MAX+10], lazy[4*MAX+10];

void update_node(ll node, ll val,ll left,ll right) {
    //Change here
    st[node] += (val*(right-left+1));
    lazy[node] += val;
}

void push(ll node, ll left, ll right) {
    if(lazy[node] != 0) {
        ll tm = (left+right)>>1;
        update_node(lc, lazy[node],left,tm);
        update_node(rc, lazy[node], tm+1, right);
        lazy[node] = 0;
    }
}

void build(ll node,ll left, ll right) {
    if(left==right) {
        st[node] = 0;
        return;
    }
    ll tm = (left+right)>>1;
    build(lc, left,tm);
    build(rc, tm+1, right);
    
    //Change here
}

void update(ll node, ll left, ll right, ll l, ll r, ll val) {
    if(l<= left && r >= right) {
        update_node(node,val,left,right);
        return;
    }
    push(node,left,right);

    ll tm = (left+right)>>1;

    if(r<=tm)    update(lc, left, tm, l , r,val);
    else if(l> tm)    update(rc, tm+1, right, l, r,val);
    else {
        update(lc,left,tm,l,r,val);
        update(rc,tm+1,right,l,r,val);
    }
    st[node] = st[lc] + st[rc];     //Change here
}

ll query(ll node, ll left, ll right, ll l, ll r) {
    if(l <= left && r >= right)
        return st[node];
    push(node,left,right);

    ll tm = (left+right)>>1;

    if(r<= tm)    return query(lc, left, tm, l, r);
    else if(l > tm)    return query(rc, tm+1, right, l, r);
    else
        return ( query(lc, left, tm, l , r) + query(rc, tm+1, right, l, r) );       //Change here
}
