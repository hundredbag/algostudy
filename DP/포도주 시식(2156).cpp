#include <cstdio>

int arr[10005];
int d[10005][3];

int max(int a, int b, int c) {
	int m = 0;
	if (m < a)
		m = a;
	if (m < b)
		m = b;
	if (m < c)
		m = c;

	return m;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	d[1][1] = arr[1];

	for (int i = 2; i <= n; i++) {
		d[i][0] = max(d[i - 1][0], d[i - 1][1], d[i - 1][2]);
		d[i][1] = d[i - 1][0] + arr[i];
		d[i][2] = d[i - 1][1] + arr[i];
	}

	int max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (max < d[i][j])
				max = d[i][j];
		}
	}

	printf("%d", max);

	return 0;
}
