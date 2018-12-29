#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

struct stu{
    char name[7];
    long long cj;
}stdnt[50010];

//����ѧ���Ƚϴ�С(a<b����true)
bool Cmp(stu a,stu b){
    if(a.cj!=b.cj)//�Ȱ��ɼ��Ƚ�,С����ǰ��
        return a.cj<b.cj;
    return a.name<b.name;//�ٰ��ֵ�����ǰ���
}

//���ֲ���
//��ѯ����ĳ������s�ĵ�һ��ѧ��
int BFind(int low,int high,long long s){
    int mid=(low+high)/2;
    while(low<high){
        if(stdnt[mid].cj<=s){
            low=mid+1;
            mid=(low+high)/2;
        }else if(stdnt[mid].cj>s){
            //����ʱ,���Ҳ���ܶ���
            high=mid;
            mid=(low+high)/2;
        }
    }
    return low;
}

int T,N,Q;
long long q[50010];

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%s%ld",stdnt[i].name,&stdnt[i].cj);//char*�����ټ�&
        }
        scanf("%d",&Q);
        for(int i=0;i<Q;i++)
            scanf("%ld",q+i);
        sort(stdnt,stdnt+N,Cmp);//����
        for(int i=0;i<Q;i++){
            if(q[i]>=stdnt[N-1].cj)//�����Ļ���
                printf("Impossible\n");
            else
                printf("%s\n",stdnt[BFind(0,N-1,q[i])].name);
        }
    }
    return 0;
}
