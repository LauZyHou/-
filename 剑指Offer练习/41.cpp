#include<bits/stdc++.h>
using namespace std;

//�������߼���С��ʵ�ֵ�,�ܻ�ȡ��λ�������� 
template<typename T> class DynamicArray {
	public:
		//�������в���һ��Ԫ��,��������������С���е�һ�� 
		void Insert(T num) {
			//���������Ԫ�ظ�����ż��,��������[�Ҳ���С��] 
			if(((min.size() + max.size()) & 1) == 0) {
				//������ֱ�[�������]�ĵ�һ��Ԫ��(���Ԫ��)С
				//��ôֻҪ[�������]�ﻹ��Ԫ��,Ҫ���ǻ�һ������ 
				if(max.size() > 0 && num < max[0]) {
					max.push_back(num);//�Ƚ�Ԫ�ز���[�������] 
					//push_heap���ԶԸղ����β������������
					push_heap(max.begin(), max.end(), less<T>());
					
					//����,[�������]�����Ԫ�ؾͳ������������ 
					num = max[0];//�����滻������Ԫ��,�����¼���� 

					//���Ѷ�,����һ��(���)Ԫ���ƶ���β�͵�λ�� 
					//ͬʱ��ʣ�µ�Ԫ�����¹����(������)һ���µ�heap
					pop_heap(max.begin(), max.end(), less<T>());
					//��ʱ,[�������]�����Ԫ�ؾͳ�������β��,���䵯�� 
					max.pop_back();
				}
				
				//Ҳ�������滻,�����Ѿ����Է��Ĳ���[�Ҳ���С��]��
				min.push_back(num);
				//push_heap���ԶԸղ����β������������
				push_heap(min.begin(), min.end(), greater<T>());
			} 
			//���������Ԫ�ظ���������,��������[�������]
			else {
				//������ֱ�[�Ҳ���С��]�ĵ�һ��Ԫ��(��СԪ��)����
				//��ôֻҪ[�Ҳ���С��]�ﻹ��Ԫ��,Ҫ���ǻ�һ������ 
				if(min.size() > 0 && min[0] < num) {
					min.push_back(num);//�Ƚ�Ԫ�ز���[�Ҳ���С��] 
					//push_heap���ԶԸղ����β������������
					push_heap(min.begin(), min.end(), greater<T>());

					//����,[�Ҳ���С��]����СԪ�ؾͳ������������ 
					num = min[0];//�����滻������Ԫ��,�����¼����

					//���Ѷ�,����һ��(��С)Ԫ���ƶ���β�͵�λ�� 
					//ͬʱ��ʣ�µ�Ԫ�����¹����(������)һ���µ�heap
					pop_heap(min.begin(), min.end(), greater<T>());
					//��ʱ,[�Ҳ���С��]����СԪ�ؾͳ�������β��,���䵯��
					min.pop_back();
				}

				//Ҳ�������滻,�����Ѿ����Է��Ĳ���[�������]��
				max.push_back(num);
				//push_heap���ԶԸղ����β������������
				push_heap(max.begin(), max.end(), less<T>());
			}
		}
		//��ȡ�������λ��Ԫ�� 
		T GetMedian() {
			//��������ǿյ�,û����ȡ��λ�� 
			int size = min.size() + max.size();
			if(size == 0)
				throw exception();

			T median = 0;//����λ���ı��� 
			if((size & 1) == 1)//���������Ԫ����������
				//��Ϊ�Ȳ��С���ٲ�Ĵ��,С��(��)�ȴ��(��)��һ��Ԫ�� 
				median = min[0];//���Ԫ�ؾ���[�Ҳ���С��]����СԪ�� 
			else//ż����Ԫ��
				//������һ����,ȡ���������Ԫ����ƽ�� 
				median = (min[0] + max[0]) / 2;
			return median;
		}

	private:
		//������vectorģ���,����Ԫ����Ŀ֮�����1 
		vector<T> min;//�����С�� 
		vector<T> max;//�Ҳ����� 
};

int main() {
	DynamicArray<double> numbers;
	numbers.Insert(5);
	numbers.Insert(2);
	numbers.Insert(3);
	numbers.Insert(4);
	cout<<numbers.GetMedian()<<endl;
	numbers.Insert(0);
	cout<<numbers.GetMedian()<<endl;
	return 0;
}
