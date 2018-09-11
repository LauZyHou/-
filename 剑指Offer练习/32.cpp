#include<bits/stdc++.h>
#include "..\Utilities\BinaryTree.h"
using namespace std;

//��������������,��������￪ʼ�������������
void PrintFromTopToBottom(BinaryTreeNode* pRoot) {
	if(pRoot == nullptr)//����ǿ�У��
		return;

	//ʹ��STL��deque(˫�˶���),��ʵֻҪ����ͨ�Ķ��о͹���
	deque<BinaryTreeNode *> dequeTreeNode;

	dequeTreeNode.push_back(pRoot);//���ڵ�Ӻ����

	//ֻҪ���зǿ�,��һֱ��
	while(dequeTreeNode.size()) {
		//ȡ��ͷ
		BinaryTreeNode *pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		//�������
		printf("%d ", pNode->m_nValue);
		//�ǿ����ӴӺ����
		if(pNode->m_pLeft)
			dequeTreeNode.push_back(pNode->m_pLeft);
		//�ǿ��Һ��ӴӺ����
		if(pNode->m_pRight)
			dequeTreeNode.push_back(pNode->m_pRight);
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
	
	PrintFromTopToBottom(pNode10);
	
	DestroyTree(pNode10);

	return 0;
}
