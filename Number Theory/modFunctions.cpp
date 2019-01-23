inline void normal(ll &a) { 
	a %= MOD; 
	(a < 0) && (a += MOD); 
}

inline ll modMul(ll a, ll b) { 
	a %= MOD, b %= MOD; 
	normal(a), normal(b); 
	return (a*b)%MOD; 
}

inline ll modAdd(ll a, ll b) { 
	a %= MOD, b %= MOD; 
	normal(a), normal(b); 
	return (a+b)%MOD; 
}

inline ll modSub(ll a, ll b) { 
	a %= MOD, b %= MOD; 
	normal(a), normal(b); 
	a -= b; 
	normal(a); 
	return a; 
}

inline ll modPow(ll b, ll p) { 
	ll r = 1; 
	while(p) { 
		if(p&1) 
			r = modMul(r, b); 
		b = modMul(b, b); 
		p >>= 1; 
	} 
	return r; 
}

inline ll modInverse(ll a) { 
	return modPow(a, MOD-2); 
}

inline ll modDiv(ll a, ll b) { 
	return modMul(a, modInverse(b)); 
}
