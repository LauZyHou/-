#include<bits/stdc++.h>
using namespace std;

void Permutation(char* pStr, char* pBegin);

//���ַ���������,������� 
void Permutation(char* pStr) {
	if(pStr == nullptr)//��������һ���ǿ�У�� 
		return;
	Permutation(pStr, pStr);
}

//�ݹ麯��,�������ַ���,�����Ӵ��ײ�ָ��(ָ����ַ����ϵĵ�ǰ�ַ�) 
void Permutation(char* pStr, char* pBegin) {
	if(*pBegin == '\0') {//���ָ����'\0',˵������ַ����Ѿ����������һ�� 
		printf("%s\n", pStr);//��ʱ�����ַ�����һ���µ�����,������� 
	} else {//����(û�ߵ���β)
		//�ӵ�ǰλ����������λ�� 
		for(char* pCh = pBegin; *pCh != '\0'; ++ pCh) {
			//����ÿ��λ����,�뵱ǰλ�õ��ַ������� 
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
			//Ȼ��ݹ�ص��ñ�����,����һλ�ÿ�ʼ���Ӵ��������˲���
			//�Ի�ȡǰ�沿�ֲ���,�������Ӵ���ʱ���ȫ���� 
			Permutation(pStr, pBegin + 1);
			//���´�ѭ��ǰ��"��ǰλ���ַ�"�����ص���ǰλ��,��ԭ�ֳ� 
			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}

int main() {
	char str[]="abcd";
	Permutation(str);
	return 0;
}
