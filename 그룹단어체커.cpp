#include <cstdio>
#include <cstring>

int t;
int alpha[26];
char str[105];

int main()
{
    int result = 0;
    scanf("%d", &t);

    while(t--){
        char prev_char;
        int len, i;

        scanf("%s", str);
        len = strlen(str);

        // alpha 배열 초기화
        for(i = 0; i < 26; i++){
            alpha[i] = 0;
        }

        for(i = 0; i < len; i++){
            if (i == 0){
                prev_char = str[i];
                alpha[str[i] - 'a'] = 1;
                continue;
            } else {
                if (prev_char == str[i]){
                    continue;
                } else {
                    if (alpha[str[i] - 'a'] == 1){
                        break;
                    } else {
                        prev_char = str[i];
                        alpha[str[i] - 'a'] = 1;
                    }
                }
            }
        }
        if (i == len)
            result++;
    }
    printf("%d", result);

    return 0;
}
