#include <cstdio>

int dp[1000005];

int min(int a, int b, int c){
    int result = a;
    
    if (result > b)
        result = b;
    if (result > c)
        result = c;
    return result;
}

int min(int a, int b){
    return a>b?b:a;
}

int main(){

    int n;
    scanf("%d", &n);
    
    dp[1] = 0;
    dp[2] = dp[3] = 1;
    
    for (int i = 4; i <= n; i++){
        if (i % 3 == 0 && i % 2 == 0){
            dp[i] = min(dp[i/3], dp[i/2], dp[i-1]) + 1;
        } else if (i % 3 == 0) {
            dp[i] = min(dp[i/3], dp[i-1]) + 1;
        } else if (i % 2 == 0){
            dp[i] = min(dp[i/2], dp[i-1]) + 1;
        } else {
            dp[i] = dp[i-1] + 1;
        }
    }
    
    printf("%d\n", dp[n]);
    return 0;
}
