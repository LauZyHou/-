#include<bits/stdc++.h>
using namespace std;

int GetTranslationCount(const string& number);

//��������,���ط��뷽�������� 
int GetTranslationCount(int number) {
	if(number < 0)//����Ϸ��Լ�� 
		return 0;
	//to_string��intת��string���� 
	string numberInString = to_string(number);
	return GetTranslationCount(numberInString);
}

//����string��ʾ������,���ط��뷽��������
//ʹ�ó�������Ϊ�ڲ����ı��ַ���,���ܱ���һ�ο������� 
int GetTranslationCount(const string& number) {
	int length = number.length();//�ַ����ĳ���,���ж��ٸ����� 
	int* counts = new int[length];//���������ڼ�¼f(i) 
	int count = 0;//��ʼ������"��ͬ�������Ŀ"Ϊ0 
	
	//�Ӻ���ǰɨ�������ַ��� 
	for(int i = length - 1; i >= 0; --i) {
		count = 0;//ÿ�ζ��Ƚ�count���,��Ϊÿ����"�ӵ�ǰλ�ó���"�Ĳ�ͬ������ 
		if(i < length - 1)//ֻҪi����n-1���������һ��
			//f(i)��ʼ��Ϊf(i+1),����ֻҪ����ƴ����λ�������� 
			count = counts[i + 1]; 
		else//�����n-1,�������һ�� 
			count = 1;//����һ����,��ֻ��һ��"����"��ʽ 
		
		//ֻҪ�������һ����,Ҫ����ƴ����λ�������� 
		//ʵ���Ͽ��Խ�������߼�һ��,���if�Ϳ��Բ���ȥ�� 
		if(i < length - 1) {
			int digit1 = number[i] - '0';//iλ�õ��� 
			int digit2 = number[i + 1] - '0';//i+1λ�õ��� 
			int converted = digit1 * 10 + digit2;//ƴ��һ�����λ�� 
			//�ж��Ƿ�����ȷ�ķ�Χ��
			if(converted >= 10 && converted <= 25) {//�������ȷ��Χ�� 
				if(i < length - 2) //����ֻ�е�i�������ٻ���������ʱ 
					count += counts[i + 2];//�Ŵ���f(i+2)��һ˵ 
				else//i�������ֻ��һ����,��i==length-2 
					count += 1;//��ʱ���ͺ�����һ����ƴ�������µ�1�ַ��� 
			}
		}
		//count������μ����f(i),�����ַ�ʽ���Ա��ⲻͣ��������Ѱַ 
		counts[i] = count;
	}

	count = counts[0];//����������Ǵ��±�Ϊ0������ʼ����β 
	delete[] counts;//�ͷŶѿռ� 
	return count;
}

int main(){
	cout<<GetTranslationCount(12258)<<endl;	
	return 0;
} 
