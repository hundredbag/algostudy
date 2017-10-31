#include <cstdio>

int a[100005];
int d[100005];

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	d[0] = a[0];
	for (int i = 1; i < n; i++) {
		d[i] = max(d[i - 1] + a[i], a[i]);
	}

	int max = 0x80000000;
	for (int i = 0; i < n; i++) {
		if (max < d[i])
			max = d[i];
	}

	printf("%d", max);
	return 0;
}
