#include <cstdio>

long long d[1005][10];

int main(){
	int n;
	scanf("%d", &n);

	for(int i = 0; i < 10; i++){
		d[1][i] = 1;
	}

	for(int i = 2; i <= n; i++){
		for(int j = 0; j < 10; j++){
			for(int k = 0; k <= j; k++){
				d[i][j] += d[i-1][k];
				d[i][j] %= 10007;
			}
		}
	}

	long long sum = 0;
	for(int i = 0; i < 10; i++){
		sum += d[n][i];
		sum %= 10007;
	}

	printf("%lld", sum);

	return 0;
}
