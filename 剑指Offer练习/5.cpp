#include<bits/stdc++.h>
using namespace std;

// ����:
//        str:         ԭ�ַ����� 
//        length:      �ַ������������
// ����ֵ:
//        û�з���ֵ,��ԭ�ַ�������ֱ�Ӳ��� 
void ReplaceBlank(char str[], int length)
{
	//����Ϸ���У�� 
    if(str == nullptr && length <= 0)
        return;

    int originalLength = 0;//�ַ���str��ʵ�ʳ���
    int numberOfBlank = 0;//�ַ����пո����Ŀ 
    int i = 0;//�α� 
    //���������ַ��� 
    while(str[i] != '\0')
    {
        ++ originalLength;//��¼ʵ�ʳ��� 

		//��¼�ո���Ŀ 
        if(str[i] == ' ')
            ++ numberOfBlank;

        ++ i;//�α��ƶ�,��ʵ���Խ�i�Ż���,ֱ����originalLength
    }

	//�ѿո��滻��'%20'֮��ĳ���Ϊ��ǰ����+�ո���Ŀ*2 
    int newLength = originalLength + numberOfBlank * 2;
    //����滻�󳤶ȳ������ַ�����������,�޷�����滻 
    if(newLength > length)
        return;

	//ԭ���α�:��ʼ��Ӧ��ԭ������-1,��Ҫ���ǵ�'\0'���Բ���1 
    int indexOfOriginal = originalLength;
    //�´��α�:��ʼ��Ӧ�ڼ�������´�����-1,��Ҫ���ǵ�'\0'���Բ���1 
    int indexOfNew = newLength;
    //���´��α�>ԭ���α�>=0ʱ,�����滻������δ���� 
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
    	//��ԭ���α��ƶ����ո�ʱ 
        if(str[indexOfOriginal] == ' ')
        {
        	//���´��α�λ����ǰ���Ŵ���%20 
            str[indexOfNew --] = '0';
            str[indexOfNew --] = '2';
            str[indexOfNew --] = '%';
        }
        //����ǿո�����������ַ� 
        else
        {
        	//ֱ���滻���´��Ķ�Ӧλ�� 
            str[indexOfNew --] = str[indexOfOriginal];
        }

        -- indexOfOriginal;//����ͳһά��ԭ���α�,����ʡ�Զ��ŵ�ǰ��Ĳ�����ȥ 
    }
}

int main(){
	const int length = 100;
	//����ǰ��ո�/�м�ո�/�����ո�/ĩβ�ո� 
	char str[length] = " L Z   H ";
	ReplaceBlank(str,length);
	int i=0;
	while('\0'!=str[i]){
		cout<<str[i];
		i++;
	}
	return 0;
}
