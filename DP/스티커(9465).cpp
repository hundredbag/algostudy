#include <cstdio>

int arr[2][105];
int dp[2][105];

int max(int a, int b, int c) {
	int m = 0;
	if (a > m)
		m = a;
	if (b > m)
		m = b;
	if (c > m)
		m = c;

	return m;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = 0;
				dp[i][j] = 0;
			}
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < 2; j++) {
				dp[j][i] = max(dp[(j + 1) % 2][i - 1], dp[j][i - 2],
						dp[(j + 1) % 2][i - 2]) + arr[j][i];
			}
		}

		int m = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				if (m < dp[i][j])
					m = dp[i][j];
			}
		}

		printf("%d\n", m);
	}

	return 0;
}
