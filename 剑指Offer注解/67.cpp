#include<bits/stdc++.h>
using namespace std;

enum Status {kValid = 0, kInvalid};//ö��ֵ��ʾ״̬:δ����,���� 
int g_nStatus = kValid;//ȫ�ֱ�����¼�Ƿ����,Ĭ����δ���� 

//minusָʾ�Ƿ�Ϊ��,digit��δ�����Ĵ����ִ�
//ת����long long���͵�����,��������һ���̶��ϼ���Ƿ�int���
//���ֱ����int,��ȫ���ܼ��int�Լ������... 
long long StrToIntCore(const char* digit, bool minus) {
	long long num = 0;//��������ת��������� 

	while(*digit != '\0') {//û���������� 
		if(*digit >= '0' && *digit <= '9') {//��0~9����Ϸ���Χ�� 
			int flag = minus ? -1 : 1;//�Ǹ��ĺ����Ҫ����-1 
			//��λ*10+��λ 
			num = num * 10 + flag * (*digit - '0');//����ֱ����ÿһλ�ϳ���flag 
			
			//�������,���߸������
			//һ���ô��Ǽ�ʱ�ж�,����ʧ��
			//��һ�ô���,����long longֻ����һ���̶��ϼ���Ƿ�int���
			//(�����long long�Լ�����˾Ϳ��ܼ�ⲻ��int�����)
			//���Ｐʱ�ж�һ�����Լ��int���
			//��Ϊlong long��int�ķ�Χ���˲�ֹһλ�� 
			if((!minus && num > 0x7FFFFFFF)
			        || (minus && num < (signed int)0x80000000)) {
				num = 0;//û��ת��,�͸���0 
				break;//����ѭ�� 
			}

			digit++;//��һλת������,������һλ 
		} else {//������ַ����ںϷ���Χ 
			num = 0;//û��ת��,�͸���0 
			break;//����ѭ�� 
		}
	}

	if(*digit == '\0')//��������ѭ���ı�ʶ 
		g_nStatus = kValid;//��¼���Գɹ�ת�� 

	return num;
}

//�ַ���ת���� 
int StrToInt(const char* str) {//����constָ���ֹ�޸��ַ�����ֵ 
	g_nStatus = kInvalid;//������Ϊ����״̬ 
	long long num = 0;//ת���������� 

	if(str != nullptr && *str != '\0') {//���ǿ�ָ��Ҳ���ǿմ� 
		bool minus = false;//ָʾ�Ƿ��Ǹ���,Ĭ�ϲ��� 
		//�����������д��Parser 
		if(*str == '+')//�����+�ſ�ͷ 
			str ++;//�����Ӻ�
		else if(*str == '-') {//-�ſ�ͷ 
			str ++;//�������� 
			minus = true;//��¼�Ǹ��� 
		}
		
		//����,������¼���,ָ��Ӧ��ָ�����ֲ������λ 
		
		if(*str != '\0')//���һ�²��Ǵ������� 
			num = StrToIntCore(str, minus);//�Ӹ�λ�ÿ�ʼ���ô����ֵ�ת�� 
	}

	return (int)num;//long longת��int,�������Ѿ���Core������ 
}

int main() {
	cout<<StrToInt("-2147483648")<<endl;//��Ч����С������,0x80000000
	return 0;
}
