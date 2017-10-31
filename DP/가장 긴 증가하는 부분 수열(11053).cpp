#include <cstdio>

int a[1005];
int d[1005];

int main(){
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	d[1] = 1;

	for(int i = 2; i <= n; i++){
		int max = 1;

		for(int j = 1; j <= i; j++){
			if (a[i] > a[j] && d[j] >= max)
				max = d[j] + 1;
		}

		d[i] = max;
	}

	int len = 0;
	for(int i = 1; i <= n; i++){
		if (d[i] > len)
			len = d[i];
	}

	printf("%d", len);

	return 0;
}
