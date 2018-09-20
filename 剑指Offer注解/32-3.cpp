#include<bits/stdc++.h>
#include "../Utilities/BinaryTree.h"
using namespace std;


//��������,����֮���δ�ӡ������
void Print(BinaryTreeNode* pRoot) {
	if(pRoot == nullptr)//�ǿ�У��
		return;
	//��������ջ,�ֱ���������֮���͵�����˳��
	//��֮ǰд���������,һ��������Ҳ���ֻ�ܳ�����������Ľ��
	//��������ջ�㹻��,�ֱ���Խ�����һ��Ľ��(��ջ˳���෴),�ٸ���pop����
	stack<BinaryTreeNode*> levels[2];
	//�����һ����:���в����ӡ������,��Ҫʹ����������ά��
	int current = 0;//��ǰ����ջ��,0ջ��ż����
	int next = 1;//��һ��Ӧ����ջ��,1ջ��������

	levels[current].push(pRoot);//����ѹ��0��(ż����)ջ
	//ֻҪ����ջ�����ǿ�,���߼����зǿ�
	while(!levels[0].empty() || !levels[1].empty()) {
		//ȡ��ǰ��ջ��Ԫ��
		BinaryTreeNode* pNode = levels[current].top();
		levels[current].pop();

		printf("%d ", pNode->m_nValue);//�������

		//�����ǰ��0��ջ(ż����ջ)
		if(current == 0) {
			//�������������ҵ�˳����1��ջ(������ջ)
			if(pNode->m_pLeft != nullptr)
				levels[next].push(pNode->m_pLeft);
			if(pNode->m_pRight != nullptr)
				levels[next].push(pNode->m_pRight);
		}
		//�����ǰ��1��ջ(������ջ)
		else {
			//���������������˳����0��ջ(ż����ջ)
			if(pNode->m_pRight != nullptr)
				levels[next].push(pNode->m_pRight);
			if(pNode->m_pLeft != nullptr)
				levels[next].push(pNode->m_pLeft);
		}
		//������ֵ�ǰջΪ��,˵����һ���ӡ����
		if(levels[current].empty()) {
			printf("\n");//����
			//��ջ,�´�ѭ��Ҫ��ӡ������һ��ջ��
			//����Ĳ�������0��1,1��0
			current = 1 - current;
			next = 1 - next;
		}
	}
}

//            8
//        6      10
//       5 7    9  11
int main() {
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	Print(pNode8);

	DestroyTree(pNode8);
	return 0;
}
