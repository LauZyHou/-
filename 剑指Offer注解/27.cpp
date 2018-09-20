#include<bits/stdc++.h>
#include "../Utilities/BinaryTree.h"
using namespace std;

//�ݹ麯��,����һ�ö���(��)���ĸ��ڵ�,���侵��
void MirrorRecursively(BinaryTreeNode *pNode) {
	//�Ӷ������ķǿ�У��,�������������Ϊ������Ͳ�������һ��,ֱ�ӷ���
	if((pNode == nullptr) || (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr))
		return;
	//������ǰ���������������ָ��
	BinaryTreeNode *pTemp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = pTemp;
	//�������������
	if(pNode->m_pLeft)
		MirrorRecursively(pNode->m_pLeft);//������Ҳ��Ҫ����
	//�������������
	if(pNode->m_pRight)
		MirrorRecursively(pNode->m_pRight);//������Ҳ��Ҫ����
}

//����ķǵݹ�ʵ��,����һ�ö������ĸ��ڵ�,���侵��
void MirrorIteratively(BinaryTreeNode* pRoot) {
	if(pRoot == nullptr)//����ǿ�У��
		return;
	//��������(��ַ)��ջ,�����ڵ����
	stack<BinaryTreeNode*> stackTreeNode;
	stackTreeNode.push(pRoot);
	//ֻҪջ�зǿ�,���������û�н���
	while(stackTreeNode.size() > 0) {
		BinaryTreeNode *pNode = stackTreeNode.top();//ȡջ�����
		stackTreeNode.pop();//�����䵯��
		//��ջ��������ҵ�������������
		BinaryTreeNode *pTemp = pNode->m_pLeft;
		pNode->m_pLeft = pNode->m_pRight;
		pNode->m_pRight = pTemp;

		if(pNode->m_pLeft)//���������ǿ�
			stackTreeNode.push(pNode->m_pLeft);//�����ڲ�Ҳ��Ҫ������,����ѹ��

		if(pNode->m_pRight)//���������ǿ�
			stackTreeNode.push(pNode->m_pRight);//ͬ����Ҫ����,ѹ��ջ
	}
	//ѭ��������,�����������˳�����н��������������˽���
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

	PrintTree(pNode8);

	printf("=====MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintTree(pNode8);

	printf("=====MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintTree(pNode8);

	DestroyTree(pNode8);
	return 0;
}

