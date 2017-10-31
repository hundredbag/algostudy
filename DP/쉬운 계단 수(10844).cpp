#include <cstdio>

long long d[105][10];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i < 10; i++) {
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				d[i][j] = d[i - 1][j + 1];
			else if (j == 9)
				d[i][j] = d[i - 1][j - 1];
			else
				d[i][j] = d[i - 1][j + 1] + d[i - 1][j - 1];

			d[i][j] %= 1000000000;
		}
	}

	long long sum = 0;
	for (int i = 0; i < 10; i++){
		sum += d[n][i];
		sum %= 1000000000;
	}

	printf("%lld", sum);

	return 0;
}
