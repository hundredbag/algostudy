#include <cstdio>
#include <cstring>

int d[15];

int main(){
	int t;
	scanf("%d", &t);

	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= 10; i++){
		d[i] = d[i-1] + d[i-2] + d[i-3];
	}

	while(t--){
		int n;
		scanf("%d", &n);

		printf("%d\n", d[n]);
	}

	return 0;
}
