#include<bits/stdc++.h>
#include "..\Utilities\BinaryTree.h"
using namespace std;

//����������д�ӡ������
void Print(BinaryTreeNode* pRoot) {
	if(pRoot == nullptr)//�ǿ�У��
		return;

	queue<BinaryTreeNode*> nodes;//�����������ַ�Ķ���
	nodes.push(pRoot);//��ʼ������ڵ�
	int nextLevel = 0;//������,��һ�������Ŀ
	int toBePrinted = 1;//������,��ǰ�㻹û����ӡ�Ľڵ���
	while(!nodes.empty()) {//ֻҪ���зǿ�
		//ÿ�������ͷ
		BinaryTreeNode* pNode = nodes.front();
		printf("%d ", pNode->m_nValue);
		//�пղ�ѹ�����ӽ��
		if(pNode->m_pLeft != nullptr) {
			nodes.push(pNode->m_pLeft);
			++nextLevel;//ѹ��ͬʱ���²�����+1
		}
		//�пղ�ѹ�����ӽ��
		if(pNode->m_pRight != nullptr) {
			nodes.push(pNode->m_pRight);
			++nextLevel;//ѹ��ͬʱ���²�����+1
		}
		//�����ո�������Ķ�ͷ,��������ڵ���-1
		nodes.pop();
		--toBePrinted;
		//[�ؼ�]���������໥ά��
		//�������ڵ������ٵ���0
		if(toBePrinted == 0) {
			printf("\n");//��ô˵�������Ѿ���ӡ����,Ҫ��ӡ��һ����
			toBePrinted = nextLevel;//���²��������Ƶ�����
			//��Ϊ��һ��ѭ��һ���ǳ�����"����"�����һ�����
			//ͬʱ����Я����"�²�"������
			//���⼸���������Ժ�"�²�"����ȫ���������
			//����û��"���²�"�Ľ��
			nextLevel = 0;//���Դ�ʱ���²�ڵ�������Ϊ0
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

