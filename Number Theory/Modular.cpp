class Modular {
	long long MOD = 1000000007;

	void normal(long long &a) {
		a %= MOD;

		if( a < 0)
			a += MOD;
	}

public:

	Modular() {};
	Modular(long long m) : MOD(m) {};

	long long modMul(long long a, long long b) { 
		a %= MOD, b %= MOD; 
		normal(a), normal(b); 
		return (a*b)%MOD; 
	}

	long long modAdd(long long a, long long b) { 
		a %= MOD, b %= MOD; 
		normal(a), normal(b); 
		return (a+b)%MOD; 
	}

	long long modSub(long long a, long long b) { 
		a %= MOD, b %= MOD; 
		normal(a), normal(b); 
		a -= b; 
		normal(a); 
		return a; 
	}

	long long modPow(long long b, long long p) { 
		long long r = 1; 
		while(p) { 
			if(p&1) 
				r = modMul(r, b); 
			b = modMul(b, b); 
			p >>= 1; 
		} 
		return r; 
	}

	long long modInverse(long long a) { 
		return modPow(a, MOD-2); 
	}

	long long modDiv(long long a, long long b) { 
		return modMul(a, modInverse(b)); 
	}

	void setMOD(long long x) {
		MOD = x;
	}


	//Binary Exponentials
	//when m is not a prime number
	long long binPow(long long a, long long b, long long m) {
	    a %= m;
	    long long res = 1;
	    while (b > 0) {
	        if (b & 1)
	            res = res * a % m;
	        a = a * a % m;
	        b >>= 1;
	    }
	    return res;
	}

	long long binMul(long long a, long long b,long long m) {
		long double x;
		long long c;
		long long r;
		if (a >= m) a %= m;
		if (b >= m) b %= m;
		x = a;
		c = x * b / m;
		r = (long long)(a * b - c * m) % (long long)m;
		return r < 0 ? r + m : r;
	}

};
