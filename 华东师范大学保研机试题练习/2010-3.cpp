#include<bits/stdc++.h>
using namespace std;

//����һ���ַ����ֱ�ͳ������ Ӣ����ĸ���ո����ֺ������ַ��ĸ���
char str[65535];
//size_t len;
int c, n, o;

int main() {
    while(gets(str)) {
//        len=strlen(str);
        for(int i = 0; str[i] != '\0'; i++) {
            if(str[i] >= 'a' && str[i] <= 'z' || str[i] <= 'Z' && str[i] >= 'A')
                c++;
            else if(str[i] <= '9' && str[i] >= '0')
                n++;
            else
                o++;
        }
        printf("%d %d %d\n", c, n, o);
    }
    return 0;
}
