#include <cstdio>
#include <cstring>
#include <cstdlib>

char a[4];
char b[4];

int main(){
    char temp;
    int i_a, i_b;

    scanf("%s%s", a, b);

    temp = a[0];
    a[0] = a[2];
    a[2] = temp;

    temp = b[0];
    b[0] = b[2];
    b[2] = temp;

    i_a = atoi(a);
    i_b = atoi(b);

    printf("%d", i_a>i_b?i_a:i_b);

    return 0;
}
