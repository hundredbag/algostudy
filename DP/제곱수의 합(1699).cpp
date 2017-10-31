#include <cstdio>
#include <cstring>

int d[100005];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++){
		d[i] = 0x7fffffff;
	}

	d[0] = 0;
	d[1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (d[i] > 1 + d[i - j * j])
				d[i] = 1 + d[i - j * j];
		}
	}

	printf("%d", d[n]);
	return 0;
}
