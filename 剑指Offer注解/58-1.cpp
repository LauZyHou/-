#include<bits/stdc++.h>
using namespace std;

//��ת��pBegin��pEnd���ַ���
void Reverse(char *pBegin, char *pEnd) {
	if(pBegin == nullptr || pEnd == nullptr)//����Ϸ��Լ��
		return;

	while(pBegin < pEnd) {
		//�����Գ�λ�õ��ַ�
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		//�ԳƵ����м��ƶ�
		pBegin ++, pEnd --;
	}
}

//��ת�ַ���,�����׵�ַ(��ʵ�׵�ַû��,һֱ�ڲ���ָ��ָ�������) 
char* ReverseSentence(char *pData) {
	if(pData == nullptr) 
		return nullptr;

	char *pBegin = pData;//��ʼ֮�� 

	char *pEnd = pData;//Ѱ�����һ���ַ�(������ǰһ���ַ�) 
	while(*pEnd != '\0')
		pEnd ++;
	pEnd--;

	//��ת��������
	Reverse(pBegin, pEnd);

	//��ת�����е�ÿ������
	pBegin = pEnd = pData;//����ָ�붼��ͷ��ʼ 
	while(*pBegin != '\0') {//pBegin�ߵ���β�ͱ�ʾ���е��ʶ���ת���� 
		if(*pBegin == ' ') {//pBeginҲ�ߵ��˿ո� 
			//��ʱend�϶�Ҳ������ո�,һ������� 
			pBegin ++;
			pEnd ++;
		} else if(*pEnd == ' ' || *pEnd == '\0') {//pBegin���ڿո�,��end�ڿո���߽����� 
			Reverse(pBegin, --pEnd);//��ת����ַ��� 
			pBegin = ++pEnd;//pBegin��pEnd����������ո��� 
		} else//pBegin���ڿո���˵������һ������,pEnd���ڿհ���˵�����ʻ�û������ 
			pEnd ++;//pEnd���������,ֱ�������հ�(�ո�������)
	}

	return pData;
}

int main() {
	char input[] = "I am a student.";
	printf("%s\n",ReverseSentence(input));//student. a am I
	return 0;
}
