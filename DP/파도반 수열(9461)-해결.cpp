#include <cstdio>

long long int d[105];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);

		d[1] = 1;
		d[2] = 1;
		d[3] = 1;
		d[4] = 2;
		d[5] = 2;

		for (int i = 6; i <= n; i++) {
			d[i] = d[i - 1] + d[i - 5];
		}

		printf("%lld\n", d[n]);
	}
	return 0;
}
