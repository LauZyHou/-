#include<bits/stdc++.h>
using namespace std;

int n;
pair<int,int> p[1010];
int num[1010]={0};

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i].first,&p[i].second);
        //ǰһ��
        for(int j=0;j<i;j++){
            if(p[j].first>p[i].first && p[j].second>p[i].second)
                num[i]++;
        }
    }
    //��һ��+���
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[j].first>p[i].first && p[j].second>p[i].second)
                num[i]++;
        }
        printf("%d\n",num[i]);
    }
    return 0;
}
