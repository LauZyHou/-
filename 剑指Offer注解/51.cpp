#include<bits/stdc++.h>
using namespace std;

// ����:
//        data:        һ����������
//        copy:        ��������
//        start:       ��������±�
//        end:         �����յ��±�
// ����ֵ:
//        data�����д�start��endλ������Ե�����
int InversePairsCore(int* data, int* copy, int start, int end) {
	if(start == end) {//�ݹ����:�������н���һ������
		copy[start] = data[start];//����ֱ�ӿ�����copy����
		return 0;//ֻ��һ������,һ�������������
	}

	int length = (end - start) / 2;//��������,������ĳ���

	//��ಿ��/�Ҳಿ�ֱַ�ݹ����:�����������������������data������
	int left = InversePairsCore(copy, data, start, start + length);
	int right = InversePairsCore(copy, data, start + length + 1, end);

	//i��ʼ��Ϊǰ������һ�����ֵ��±�(ǰ��������)
	int i = start + length;
	//j��ʼ��Ϊ�������һ�����ֵ��±�(���������)
	int j = end;
	int indexCopy = end;//Ҫ���Ƶ���copy�����λ���±�
	int count = 0;//�ȽϹ����з��ֵ��������Ŀ
	//�����������ж�������δ������
	while(i >= start && j >= start + length + 1) {
		if(data[i] > data[j]) {//��������е�������
			copy[indexCopy--] = data[i--];//���Ƶ�copy������
			//�Ҳ���������ʣ����������ֶ�����������е�������ֹ��������
			count += j - start - length;//ע��start+length���Ƿָ���λ���±�
		} else {//�Ҳ������е�������
			copy[indexCopy--] = data[j--];
		}
	}

	//�����&&������һ�߲��������ֹ,��ʱ������һ�����黹û������

	for(; i >= start; --i)//�������ʣ�ิ����
		copy[indexCopy--] = data[i];

	for(; j >= start + length + 1; --j)//�Ҳ�����ʣ�ิ����
		copy[indexCopy--] = data[j];

	//����������+�Ҳ��������+����������������
	return left + right + count;
}

// ����:
//        data:        һ����������
//        length:      ����ĳ���
// ����ֵ:
//        data����������Ե�����
int InversePairs(int* data, int length) {
	//��������߳��Ȳ��Ϸ�,����Ӧ��<=0������<0
	if(data == nullptr || length <= 0)
		return 0;

	//���data���鵽copy������
	int* copy = new int[length];
	for(int i = 0; i < length; ++i)
		copy[i] = data[i];

	//����ͳ���������Ŀ�ĵݹ麯��
	int count = InversePairsCore(data, copy, 0, length - 1);
	delete[] copy;

	return count;
}

int main() {
	int data[] = { 1, 2, 3, 4, 7, 6, 5 };
	cout<<InversePairs(data,7)<<endl;//3
	return 0;
}
