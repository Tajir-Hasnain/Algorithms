class EulerTotient {

	vector < long long > phi;
	int N;

	void generatePhi() {
	    phi[1] = 0;
	    for (int i = 2; i <= N; i++) {
	        if(!phi[i]) {
	            phi[i] = i-1;
	            for(int j = (i << 1); j <= N; j += i) {
	                if(!phi[j]) phi[j] = j;
	                phi[j] = phi[j] * (i-1) / i;
	            }
	        }
	    }
	}

public:
	EulerTotient(long long n) {
		N = n;
		phi.assign(N+7,0);
		generatePhi();
	}

	long long sumOfCoPrimesOfAnInteger(long long n) {
		ll fx = phi[n] * n;
		fx /= 2;

		return fx;
	}

};
