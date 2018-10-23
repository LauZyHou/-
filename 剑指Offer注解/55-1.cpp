#include<bits/stdc++.h>
#include"../Utilities/BinaryTree.h"
using namespace std;

//�ݹ麯��:������������������
int TreeDepth(const BinaryTreeNode* pRoot) {
	if(pRoot == nullptr)//�ݹ����:�ս��߶�Ϊ0
		return 0;

	int nLeft = TreeDepth(pRoot->m_pLeft);//�ݹ����������� 
	int nRight = TreeDepth(pRoot->m_pRight);//�ݹ����������� 

	//����max(��,��)+�������ĸ��ڵ�߶�1
	return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

//            1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
int main() {
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, nullptr, pNode6);
	ConnectTreeNodes(pNode5, pNode7, nullptr);

	cout<<TreeDepth(pNode1)<<endl;//4

	DestroyTree(pNode1);
	return 0;
}
