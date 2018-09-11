#include<bits/stdc++.h>
using namespace std;

// ����:
//        pPush:       ѹջ����
//        pPop:        ��ջ����
//        nLength:     ���еĳ���
// ����ֵ:
//        �����������ܷ�ƥ��
//constλ��*�����,��const������������ָ����ָ��ı���,��ָ��ָ��Ϊ����
//���constλ��*���Ҳ�,const��������ָ�뱾��,��ָ�뱾���ǳ���
bool IsPopOrder(const int* pPush, const int* pPop, int nLength) {
	bool bPossible = false;//��ʼ:����ƥ��
	//����Ϸ��Լ��
	if(pPush != nullptr && pPop != nullptr && nLength > 0) {
		//�������������ƶ���ָ��,����֮ǰ��ָ�������Ƚ�
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;

		std::stack<int> stackData;//��һ��STLջ��ģ��

		//ֻҪû���ƶ�������(����������һ����),��Ҫ�����ж�
		while(pNextPop - pPop < nLength) {
			//ջΪ��,����ջ�ڵ�ջ��Ԫ�ز���Ҫ������Ԫ��
			while(stackData.empty() || stackData.top() != *pNextPop) {
				//ѹջ֮ǰ�ȼ��һ��,����������ֶ�ѹ�븨��ջ��,�˳�ѭ��
				if(pNextPush - pPush == nLength)
					break;
				//ѹջ
				stackData.push(*pNextPush);
				//ѹջ�Ժ�,ѹջ���е�ָ��Ҫ�����,��ʾһ��Ԫ���Ѿ�ѹ��ջ��
				pNextPush ++;
			}

			//����,ջ�ڵ�ջ��Ԫ�ؿ�����Ҫ������Ԫ��
			//����һ�ֿ��ܾ����������ֶ�ѹ�븨��ջ��

			//��֮��Ҫ���ж�һ��ջ��Ԫ���ǲ��ǵ���������Ҫ������Ԫ��
			if(stackData.top() != *pNextPop)//�������
				break;//ʧ���˳�

			//����,һ������������
			stackData.pop();
			pNextPop ++;//����������ǰ��,�¸�ѭ�������ж�
		}

		//ѭ��������,ͨ���ж�ջ���Ƿ�����ҵ�����������
		if(stackData.empty() && pNextPop - pPop == nLength)
			bPossible = true;//����֪���Ƿ�ɹ�ƥ����
	}

	return bPossible;
}

int main() {
	const int nLength = 5;
	int push[nLength] = {1, 2, 3, 4, 5};
	int pop[nLength] = {3, 5, 4, 2, 1};
	cout<<boolalpha<<IsPopOrder(push,pop,nLength);
	return 0;
}
