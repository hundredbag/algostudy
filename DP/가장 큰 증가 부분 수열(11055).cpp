#include <cstdio>

int a[1005];
int d[1005];

int main(){
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		d[i] = a[i];
	}


	for(int i = 2; i <= n; i++){
		for(int j = 1; j < i; j++){
			if (a[i] > a[j] && d[j] + a[i] > d[i])
				d[i] = d[j] + a[i];
		}
	}

	int m = 0;
	for(int i = 1; i <= n; i++){
		if (d[i] > m)
			m = d[i];
	}
	printf("%d", m);

	return 0;
}
