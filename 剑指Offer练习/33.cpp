#include<bits/stdc++.h>
using namespace std;

// ����:
//        sequence:       ������������ 
//        length:         ���еĳ��� 
// ����ֵ:
//        ���������������ܷ�����ĳBST(����������) 
bool VerifySquenceOfBST(int sequence[], int length) {
	if(sequence == nullptr || length <= 0)//����Ϸ���У�� 
		return false;

	int root = sequence[length - 1];//���ڵ������һ����� 

	//�ڶ������������������Ľ��С�ڸ���� 
	int i = 0;
	for(; i < length - 1; ++ i) {//������,���Դ�������ɨ��
		if(sequence[i] > root)//���ֵ�һ�����ڸ��ڵ��ֵ 
			break;//��ʱ���˳�,i������ȫ��ֵ���������� 
	}

	//�ڶ������������������Ľ����ڸ����
	int j = i;//�Ӹո��ҵ��ķֽ�λ�� 
	for(; j < length - 1; ++ j) {//���������Ӧ�����������Ĳ��� 
		if(sequence[j] < root)//������ֱȸ����С��ֵ 
			return false;//˵�������в�����Ҫ��,������BST�ĺ����������� 
	}

	//�ж��������ǲ��Ƕ���������
	bool left = true;
	if(i > 0)//�ֽ��i>0������������ʵ���ڵ�,�������и�sequence[0]���\
		//�ֽ��i���ñ�ʾ�����Ľ����,������������� 
		left = VerifySquenceOfBST(sequence, i);

	//�ж��������ǲ��Ƕ���������
	bool right = true;
	if(i < length - 1)//�ֽ��i����������λ��,������������ʵ���ڵ�
		//������ʼ��Ҫ����i�����������,���г���Ҫ����1�����ڵ��i����������� 
		right = VerifySquenceOfBST(sequence + i, length - i - 1); 
	
	//����������ΪBSTʱ,�ڸ������ϲ�����Ϊ��BST 
	return (left && right);
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
int main() {
	int data[] = {4, 8, 6, 12, 16, 14, 10};
	cout<<boolalpha<<VerifySquenceOfBST(data,sizeof(data)/sizeof(int));
	return 0;
}

