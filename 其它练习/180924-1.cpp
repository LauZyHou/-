#include<bits/stdc++.h>
using namespace std;

//��ʦ������ϰ

int main(){
/*
    int a[]={2,4,5,1,5,2,6,2,1,4,1,6,2};
    sort(a,a+sizeof(a)/sizeof(int));
    int *ed=unique(a,a+sizeof(a)/sizeof(int));//unique���ظ����Ƶ�����,�����µĽ���λ�õ�ַ
    for(int* i=a;i<ed;i++){
        cout<<*i<<" ";
    }
*/
    __int64 a,b;
    while(scanf("%llX%llX",&a,&b)!=EOF){
        printf("%llx\n",a+b);//x��Сд16����,X�Ǵ�д
    }
    return 0;
}
