#include<bits/stdc++.h>
using namespace std;

//�������ӵĳ���,������˻� 
int maxProductAfterCutting_solution1(int length) {
	if(length < 2)//��ΪҪ�󳤶�n>1,�������ﷵ��0��ʾ����Ƿ� 
		return 0;
	if(length == 2)//����Ϊ2ʱ,��ΪҪ����¶���m>1,���������1x1=1 
		return 1;
	if(length == 3)//����Ϊ3ʱ,��ΪҪ����¶���m>1,���������1x2=2 
		return 2;
	
	//��������,˵�����ӵĳ�����>3��,��֮��0/1/2/3������������������������
	//��������Ҫ���Ǽ�һ��������,��Ϊ���Ǽ�һ��û�в������������
	//���ڵ�����ô���������ϼ����ſ�������0/1/2/3���ֳ��ȵ�����,���ǲ���Ҫ�ټ�
	//��������ı��п��Կ���������Ϊ�������ֵ������ʵ�ʷ��ص��ǲ�һ���� 
	
	//�ڱ����ȴ��������ӵ����˻� 
	int* products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;//��3Ϊֹ���ǲ������ 

	int max = 0;//���ڼ�¼���˻� 
	//����4���ϵ����,ÿ��ѭ��Ҫ��f(i) 
	for(int i = 4; i <= length; ++i) {
		max = 0;//ÿ�ν����˻����
		//��ΪҪ����f(j)����f(i-j)�����ֵ,j����i��һ��ʱ���ظ�����
		//����ֻ��Ҫ����j������i��һ������ 
		for(int j = 1; j <= i / 2; ++j) {
			//����f(j)����f(i-j)
			int product = products[j] * products[i - j];
			//����ȵ�ǰ�ҵ��Ļ��� 
			if(max < product)
				max = product;//�Ͱ����ֵ���� 
		}
		//������ѭ���޹ص�,������for����,�Ұ�������� 
		products[i] = max;//����,���±��е�f(i)=max(f(j)��f(i-j))
	}
	//ѭ��������,�����f(length)Ҳ��������� 
	max = products[length];//�����¼�����������ٺ��ܷ��� 
	delete[] products;//���ٴ��ĸ����ռ� 
	return max; 
}

int main(){
	cout<<maxProductAfterCutting_solution1(9)<<endl;
	return 0;
}
