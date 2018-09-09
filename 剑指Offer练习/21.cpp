#include<bits/stdc++.h>
using namespace std;

void Reorder(int *pData, unsigned int length, bool (*func)(int));
bool isEven(int n);

//����Ҫ������������,����ĳ���
void ReorderOddEven_2(int *pData, unsigned int length) {
	Reorder(pData, length, isEven);//�����ﴫ��Ҫ�����жϵĺ���
	//�������ı�ʱ,ֻҪ��дһ������,Ȼ��������ı䴫��ȥ�ĺ������� 
}

//����Ҫ������������,����ĳ���,�����жϵĺ���ָ��(һ��int����,����ֵ��bool) 
void Reorder(int *pData, unsigned int length, bool (*func)(int)) {
	//����ǿ�У�� 
	if(pData == nullptr || length == 0)
		return;

	int *pBegin = pData;//���ָ��ӵ�һ��Ԫ�ؿ�ʼ
	int *pEnd = pData + length - 1;//�Ҳ�ָ������һ��Ԫ�ؿ�ʼ

	//ֻҪ��ָ����δ����
	while(pBegin < pEnd) {
		//�����ƶ�pBegin,ֱ�������������Ϊfalse 
		while(pBegin < pEnd && !func(*pBegin))
			pBegin ++;

		//�����ƶ�pEnd,ֱ�������������Ϊtrue
		while(pBegin < pEnd && func(*pEnd))
			pEnd --;

		//�ٴμ������û��������
		if(pBegin < pEnd) {
			//����������ָ�������Ԫ�ص�ֵ
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

//��������ж���ż�ĺ��� 
bool isEven(int n) {
	//��1����Ϊ0��Ϊż��,�ú���������ż��ʱ����true
	return (n & 1) == 0;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    int length=sizeof(numbers)/sizeof(int);
    ReorderOddEven_2(numbers,length);
    for(int i=0;i<length;i++)
        cout<<numbers[i]<<"\t";
    return 0;
}
