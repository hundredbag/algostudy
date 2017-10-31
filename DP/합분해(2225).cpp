#include <cstdio>

long long d[205][205];
long long mod = 1000000000;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	d[0][0] = 1LL;

	for(int i = 1; i <= k; i++){
		for (int j = 0; j <= n; j++){
			for(int l = 0; l <= j; l++){
				d[i][j] += d[i-1][j-l];
				d[i][j] %= mod;
			}
		}
	}

	printf("%lld", d[k][n]);

	return 0;
}
