#include<bits/stdc++.h>
#include "..\Utilities\BinaryTree.h"
using namespace std;

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList);

//����BST������,����ת�����˫�������ͷ���
BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree) {
	//pLastNodeInList���ڼ�¼ת����˫�������β���
	BinaryTreeNode *pLastNodeInList = nullptr;
	//����BST������,����ת����˫�������β���[ָ��ĵ�ַ],�Ӷ��ĵ����ָ��
	ConvertNode(pRootOfTree, &pLastNodeInList);

	//pHeadOfList���ڼ�¼ת����˫�������ͷ���
	//����Ҫ��β���λ����ǰѰ��ͷ���
	BinaryTreeNode *pHeadOfList = pLastNodeInList;
	//ֻҪ���ǿ�,���������(ԭBST�����������)�ǿ�
	while(pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
		pHeadOfList = pHeadOfList->m_pLeft;//һֱ������
	//�������whileѭ�������Ż�:��һ������ֻ��Ҫ�жϵ�һ�μ���
	//���ﻹ�Ǳ������ߵ�д��
	return pHeadOfList;//���շ���ת�����˫�������ͷ���
}

//�����ǵݹ�ʵ�ֲ���,�����ó����γ�һ������
//����BST��(��)����,����ת����˫�������β���[ָ��ĵ�ַ],�Ӷ��ĵ����ָ��
void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList) {
	if(pNode == nullptr)//BST���ǿ�У��
		return;

	BinaryTreeNode *pCurrent = pNode;//��ǰ���

	//�������˳��:��-��-��

	/*��*/
	if (pCurrent->m_pLeft != nullptr)//����������
		ConvertNode(pCurrent->m_pLeft, pLastNodeInList);//����������ת��

	/*��*/
	//����,�������Ѿ�ת������,����Ŀǰת�������������ҽ��ָ��*pLastNodeInList
	//Ӧ��ָ��������ת���ɵ�˫����������ҽ��
	//�������������������ϵ������,Ҳ���Ǳȵ�ǰ���С����ֵ�����һ�����
	//----------------------------------------------
	//��������������Ҷ�Ӷ���,�������ǲ����ڵ�,��ʱ*pLastNodeInList���������ĸ���˫��
	//----------------------------------------------
	//������һ��ÿ�ο�����������֮һ:
	//                   1.���ڵ�-����->������������Ҷ��
	//                   2.������������Ҷ��-����->���ڵ�
	//���,��ǰ������ָ��Ӧ��ָ��������
	pCurrent->m_pLeft = *pLastNodeInList;
	//���*pLastNodeInList�ǿ�(��Ҳ˵����������ʵ�ʴ��ڵ�(������һ�����))
	if(*pLastNodeInList != nullptr)
		//��ʱҪά����������ǰ����ָ��
		//ͬ��,��һ��Ҳ��ÿ�ο�����������֮һ:
		//               1.������������Ҷ��-����->���ڵ�
		//               2.���ڵ�-����->������������Ҷ��
		(*pLastNodeInList)->m_pRight = pCurrent;

	//��ʱ,�м�����Ѿ�ά��������������ת˫����������Ҳ�
	*pLastNodeInList = pCurrent;//�����������ҽ��ָ��Ϊ��ǰ���

	/*��*/
	if (pCurrent->m_pRight != nullptr)//����������
		ConvertNode(pCurrent->m_pRight, pLastNodeInList);//����������ת��
}

//�ṩ˫�������ͷ���,���˫������
void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList) {
	BinaryTreeNode* pNode = pHeadOfList;//�α�ָ���ͷ��㿪ʼ
	//���������һ��
	printf("The nodes from left to right are:\n");
	while(pNode != nullptr) {
		printf("%d\t", pNode->m_nValue);
		if(pNode->m_pRight == nullptr)
			break;
		pNode = pNode->m_pRight;
	}
	//���ҵ������һ��
	printf("\nThe nodes from right to left are:\n");
	while(pNode != nullptr) {
		printf("%d\t", pNode->m_nValue);
		if(pNode->m_pLeft == nullptr)
			break;
		pNode = pNode->m_pLeft;
	}
	printf("\n");
}

//�ṩ˫�������ͷ���,����˫������
void DestroyList(BinaryTreeNode* pHeadOfList) {
	BinaryTreeNode* pNode = pHeadOfList;//�α�ָ���ͷ��ʼ
	while(pNode != nullptr) {//ֻҪû����
		//��¼�Ҳ�Ľ��
		BinaryTreeNode* pNext = pNode->m_pRight;
		//���ٵ�ǰ�Ľ��
		delete pNode;
		//�Ҳ�Ľ����Ϊ�µĵ�ǰ���,����ѭ��
		pNode = pNext;
	}
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
int main() {
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

	ConnectTreeNodes(pNode10, pNode6, pNode14);
	ConnectTreeNodes(pNode6, pNode4, pNode8);
	ConnectTreeNodes(pNode14, pNode12, pNode16);

	BinaryTreeNode* pHeadOfList=Convert(pNode10);

	//���˫������
	PrintDoubleLinkedList(pHeadOfList);

	DestroyList(pHeadOfList);

	return 0;
}
