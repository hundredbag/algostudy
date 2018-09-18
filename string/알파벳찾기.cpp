#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int alpha[26];
char str[105];

int main(){
    scanf("%s", str);
    int len = strlen(str);

    for(int i = 0; i < 26; i++){
        alpha[i] = -1;
    }

    for(int i = 0; i < len; i++){
        if (alpha[str[i] - 'a'] == -1){
            alpha[str[i] - 'a'] = i;
        }
    }

    for(int i = 0; i < 26; i++){
        printf("%d ", alpha[i]);
    }

    return 0;
}
