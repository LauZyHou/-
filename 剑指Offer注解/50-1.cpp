#include<bits/stdc++.h>
using namespace std;

//�ַ�ͳ���� 
class CharStatistics {
	public:
		//��������ʼ��
		CharStatistics() : index(0) {//������±��0��ʼ 
			for(int i = 0; i < 256; ++i)
				occurrence[i] = -1;//��ʼ�������ַ�Ϊ"δ����" 
		}

		//����һ���ַ�chʱ,����״̬�� 
		void Insert(char ch) {
			if(occurrence[ch] == -1)//û�����->������,��¼���뵽���±� 
				occurrence[ch] = index;
			else if(occurrence[ch] >= 0)//�����->���ֳ���һ�� 
				occurrence[ch] = -2;
			index++;//����һ��λ�õ��ַ�,λ��+1 
		}

		//�ҳ�������ǰλ�õĵ�һ�γ���һ�ε��ַ� 
		char FirstAppearingOnce() {
			char ch = '\0';//�Ҳ�������'\0' 
			//��������������int 
			int minIndex = numeric_limits<int>::max();
			//������ϣ��,�ҵ���С���Ǹ��Ǹ���(����λ��)��Ӧ���ַ� 
			for(int i = 0; i < 256; ++i) {
				//�Ǹ�(״̬�� )��С�ڵ�ǰ�ҵ�����С(�����ܳ��ֵ��ڵ����) 
				if(occurrence[i] >= 0 && occurrence[i] < minIndex) {
					ch = (char) i;//�����ַ� 
					minIndex = occurrence[i];//������С�±� 
				}
			}
			return ch;
		}

	private:
		// occurrence[i]: A character with ASCII value i;
		// occurrence[i] = -1: The character has not found;
		// occurrence[i] = -2: The character has been found for mutlple times
		// occurrence[i] >= 0: The character has been found only once
		int occurrence[256];//��ϣ��,occurrence�ǳ��ֵ���˼ 
		int index;
};

int main() {
	CharStatistics cs;
	cs.Insert('g');
	cout<<cs.FirstAppearingOnce()<<endl;//g
	cs.Insert('o');
	cout<<cs.FirstAppearingOnce()<<endl;//g
	cs.Insert('o');
	cout<<cs.FirstAppearingOnce()<<endl;//g
	cs.Insert('g');
	cout<<cs.FirstAppearingOnce()<<endl;//
	cs.Insert('l');
	cout<<cs.FirstAppearingOnce()<<endl;//l
	cs.Insert('e');
	cout<<cs.FirstAppearingOnce()<<endl;//l
	return 0;
}

