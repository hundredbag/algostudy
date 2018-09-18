#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int alpha[26];
char str[1000005];

int main(){
    scanf("%s", str);

    // for 문에서 strlen을 계속 호출하면 시간 초과 발생함.
    int len = strlen(str);

    for(int i = 0; i < len; i++){
        if (str[i] >= 97){
            alpha[str[i] - 97]++;
        } else {
            alpha[str[i] - 65]++;
        }
    }

    int max = 0;
    int index = -1;

    for(int i = 0; i < 26; i++){
        if (alpha[i] > max){
            max = alpha[i];
            index = i;
        }
    }

    int dup = 0;
    for(int i = 0; i < 26; i++){
        if ( index != i && alpha[i] == max){
            dup = 1;
        }
    }

    if (dup == 1){
        printf("?");
    } else {
        printf("%c", index + 65);
    }

    return 0;
}
