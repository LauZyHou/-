#include<bits/stdc++.h>
using namespace std;

class Temp {
	private:
		//�������Ǿ�̬����,����ʵ������ 
		static unsigned int N;//��ǰҪ�ӵ�����N 
		static unsigned int Sum;//�����ܺ�Sum 

	public:
		Temp() {//�ڹ�������ʵ��N�������ͼӵ�Sum�� 
			++ N;
			Sum += N;
		}

		static void Reset() {//���� 
			N = 0;
			Sum = 0;
		}
		static unsigned int GetSum() {//��ȡ�ܺ� 
			return Sum;
		}
};

//static��Ա������Ҫ���ඨ��������г�ʼ���붨��
//��Ϊstatic���ݳ�Ա�������������������
//������������Ķ���,������������
unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int Sum_Solution1(unsigned int n) {
	Temp::Reset();//���þ�̬bianl 

	Temp *a = new Temp[n];//����n������,������n�ι����� 
	delete []a;//�������� 
	a = NULL;//����Ұָ�� 

	return Temp::GetSum();//���еľ�̬�����Ѿ��ı�,��ȡһ�� 
}

int main() {
	cout<<Sum_Solution1(5)<<endl;//15
	return 0;
}
