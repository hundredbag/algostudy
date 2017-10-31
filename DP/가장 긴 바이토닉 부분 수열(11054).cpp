#include <cstdio>

int a[1005];
int inc[1005];
int dec[1005];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		inc[i] = dec[i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && inc[j] + 1 > inc[i]) {
				inc[i] = inc[j] + 1;
			}
		}
	}

	for (int i = n - 1; i >= 1; i--){
		for(int j = n; j > i; j--){
			if (a[i] > a[j] && dec[j] + 1 > dec[i]){
				dec[i] = dec[j] + 1;
			}
		}
	}

//	for (int i = 1; i <= n; i++) {
//		printf("%d ", inc[i]);
//	}
//	printf("\n");
//
//	for (int i = 1; i <= n; i++) {
//		printf("%d ", dec[i]);
//	}

	int max = 0;
	for (int i = 1; i <= n; i++){
		if (max < inc[i] + dec[i])
			max = inc[i] + dec[i];
	}

	printf("%d", max-1);
	return 0;
}
