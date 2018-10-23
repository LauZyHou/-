#include<bits/stdc++.h>
#include"../Utilities/BinaryTree.h"
using namespace std;

//�ݹ麯��:�ж϶������ǲ���ƽ�������,�����߶ȱ����ڵڶ�������ָ�����ڴ���
bool IsBalanced(const BinaryTreeNode* pRoot, int* pDepth) {
	//�ݹ����
	if(pRoot == nullptr) {//�ս��
		*pDepth = 0;//�ս��û�и߶�(�߶���0)
		return true;//�ս��û����������,��Ϊ��ƽ���
	}

	int left, right;//�����������ĸ߶�
	//�ݹ�����ж���������ƽ��,���㱣�����������ĸ߶�
	if(IsBalanced(pRoot->m_pLeft, &left)
	        && IsBalanced(pRoot->m_pRight, &right)) {//���������������ƽ��Ĳż����ж�
		int diff = left - right;//���������߶Ȳ�
		if(diff <= 1 && diff >= -1) {//��[-1,1]�ڸ���������ƽ���
			*pDepth = 1 + (left > right ? left : right);//�߶�=max(��,��)+1
			return true;//ƽ�ⷵ��true
		}
	}
	//�����������������ƽ���,�����ټ����ж���
	return false;
}

//�ж�һ�ö������ǲ���ƽ�������
bool IsBalanced_Solution(const BinaryTreeNode* pRoot) {
	int depth = 0;//���ڱ���������ĸ߶ȼ�����
	return IsBalanced(pRoot, &depth);//���õݹ麯���ж�
}


// ������ȫ������������ƽ�������
//             1
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

	cout<<boolalpha<<IsBalanced_Solution(pNode1)<<endl;//true 

	DestroyTree(pNode1);
	return 0;
}
