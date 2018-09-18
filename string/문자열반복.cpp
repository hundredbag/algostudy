#include <cstdio>
#include <cstring>

int main(){
    int n, x;
    char str[100];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        scanf("%s", str);

        for(int j = 0; j < strlen(str); j++){
            for(int k = 0; k < x; k++){
                printf("%c", str[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
