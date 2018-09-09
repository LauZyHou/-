#include <cstdio>
#include "BinaryTree.h"

//�������ֵ,����һ�����������
BinaryTreeNode* CreateBinaryTreeNode(int value) {
	//�������������
	BinaryTreeNode* pNode = new BinaryTreeNode();
	//����ֵ,��������Ĭ��Ϊ��
	pNode->m_nValue = value;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;
	return pNode;
}

//���ӽ��,�������ڵ�������������
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
	if(pParent != nullptr) { //У�鸸�ڵ�������
		//ʹ���ڵ�ָ��������������
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
	}
}

//���ָ���Ķ��������
void PrintTreeNode(const BinaryTreeNode* pNode) {
	if(pNode != nullptr) { //У��ý��ǿ�
		printf("value of this node is: %d\n", pNode->m_nValue);

		if(pNode->m_pLeft != nullptr)//���ӽ��
			printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
		else
			printf("left child is nullptr.\n");

		if(pNode->m_pRight != nullptr)//���ӽ��
			printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
		else
			printf("right child is nullptr.\n");
	} else {
		printf("this node is nullptr.\n");
	}
	printf("\n");
}

//�������ڵ�,������ö�����
void PrintTree(const BinaryTreeNode* pRoot) {
	PrintTreeNode(pRoot);//����������Ϣ

	if(pRoot != nullptr) {//У��������ǿ�
		//�ݹ�ص���������,���������������Ϣ
		if(pRoot->m_pLeft != nullptr)
			PrintTree(pRoot->m_pLeft);

		if(pRoot->m_pRight != nullptr)
			PrintTree(pRoot->m_pRight);
	}
	//���������ʽ����,�Ժ��п����Ҹ����Ի��Ŀ���̨�����ʽ��
}

//�������ڵ�,ɾ�����ö�����
void DestroyTree(BinaryTreeNode* pRoot) {
	if(pRoot != nullptr) {//У��������ǿ�
		//�������������ĵ�ַ�ȷֱ��¼���� 
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;
		//Ȼ��ɾ��������ڵ� 
		delete pRoot;
		pRoot = nullptr;
		//Ȼ����������������,�ݹ��ɾ���������� 
		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}
