#include <cstdio>

int a[1005];
int dp[1005];

int main() {
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++){
		dp[i] = 1;

		for (int j = 0; j < i; j++){
			if (a[j] > a[i] && dp[j] + 1 > dp[i]){
				dp[i] = dp[j] + 1;
			}
		}
	}

	int max = 0;
	for(int i = 0; i < n; i++){
		if (dp[i] > max){
			max = dp[i];
		}
	}

	printf("%d", max);

	return 0;
}
