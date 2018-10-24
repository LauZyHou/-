#include<bits/stdc++.h>
using namespace std;

//��max�����Ķ���ģ���� 
template<typename T> class QueueWithMax {
	private:
		//����Զ�����е�Ԫ�ؽ��ṹ��
		struct InternalData { 
			T number;//Ԫ�ص�ֵ,�������� 
			int index;//����ʱ��������±� 
		};
		deque<InternalData> data;//�����ʵ�����ݵ�˫�˶��� 
		deque<InternalData> maximums;//�����ֵ��˫�˶��� 
		int currentIndex;//������Ҫ����Ԫ��Ӧ�ø�����±� 

	public:
		//������ 
		QueueWithMax() : currentIndex(0) {//��ʼ���±�ֵΪ0 
		}

		//���,�൱����һ�����滬�����ڻ���һ������ 
		void push_back(T number) {
			//�������ֱȽ�,��˫�˶����ﲻ���������Ԫ�ض�ɾ�� 
			while(!maximums.empty() && number >= maximums.back().number)
				maximums.pop_back();
 
			InternalData internalData = { number, currentIndex };//����Ԫ�ؽ��
			data.push_back(internalData);//�����Ԫ�صĶ��� 
			maximums.push_back(internalData);//Ҳ�������ֵ���� 

			++currentIndex;//id����1,��������һ�������Ԫ���� 
		}

		//����,�൱�ڻ�������,�������������Ϊ���ڴ��������1��ɵ� 
		void pop_front() {
			if(maximums.empty())//����Ϊ�ղ��ܳ��� 
				throw new exception();//queue is empty
			
			//����ͱ���һ��Ļ������׶���,ֱ���ж��ǲ��ǵ�ǰ��� 
			if(maximums.front().index == data.front().index)
				maximums.pop_front();//�����,�Ͱ��Ǹ���ǰ���Ҳ�õ�(�Ӷ�ͷ) 

			data.pop_front();//���� 
		}

		//��ȡ���ֵ
		//β��const��ʾ��Ա�������������thisָ��Ϊconstָ��
		//���������Ա�����ڲ����޸ķ�mutable��Ա 
		T max() const {
			if(maximums.empty())//Ϊ�վ�û�����ֵ 
				throw new exception();//queue is empty
			//�����ֵ��˫�˶��еĶ�ͷԪ�ص�number�� 
			return maximums.front().number;
		}
};

int main() {
	QueueWithMax<int> queue;
	queue.push_back(2);
	cout<<queue.max()<<endl;//2
	queue.push_back(4);
	cout<<queue.max()<<endl;//4
	queue.push_back(3);
	cout<<queue.max()<<endl;//4
	queue.push_back(2);
	cout<<queue.max()<<endl;//4
	queue.pop_front();
	cout<<queue.max()<<endl;//4
	queue.pop_front();
	cout<<queue.max()<<endl;//3
	return 0;
}
