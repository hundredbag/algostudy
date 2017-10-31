#include <cstdio>

int a[305];
int d[305];

int max(int a, int b){
	return a>b?a:b;
}
int main(){
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++ ){
		scanf("%d", &a[i]);
	}

	d[1] = a[1];
	d[2] = a[1] + a[2];

	for(int i = 3; i <= n; i++){
		d[i] = max(d[i-2] + a[i], d[i-3] + a[i] + a[i-1]);
	}

	printf("%d", d[n]);

	return 0;
}
