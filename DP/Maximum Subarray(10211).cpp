#include <cstdio>

int a[1005];
int d[1005];

int max(int a, int b){
	return a>b?a:b;
}

int main(){
	int t;
	scanf("%d", &t);

	while(t--){
		int n;
		scanf("%d", &n);

		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}

		d[0] = a[0];

		for(int i = 1; i < n; i++){
			d[i] = max(d[i-1], 0) + a[i];
		}
		int m = 0x80000000;
		for(int i = 1; i < n; i++){
			if(m < d[i])
				m = d[i];
		}

		printf("%d\n", m);
	}

	return 0;
}
