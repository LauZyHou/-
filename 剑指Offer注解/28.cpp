#include<bits/stdc++.h>
#include "../Utilities/BinaryTree.h"
using namespace std;

bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

//����һ�ö������ĸ��ڵ�,�ж϶������ǲ��ǶԳƵ�
bool isSymmetrical(BinaryTreeNode* pRoot) {
	return isSymmetrical(pRoot, pRoot);
}

//����[��nullptr��]������[ǰ�����]��ͬ����[�Գ�ǰ�����]�����е��������
//�жϼ������±����������Ƿ��ǶԳƵ�
bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	//����㶼Ϊ�տ϶��Գ�
	if(pRoot1 == nullptr && pRoot2 == nullptr)
		return true;
	//�������Ϊ��,����ĳһ��Ϊ��,�ǿ϶����Գ�
	if(pRoot1 == nullptr || pRoot2 == nullptr)
		return false;
	//�������Ϊ��,��ֵ��ͬ,Ҳ���Գ�
	if(pRoot1->m_nValue != pRoot2->m_nValue)
		return false;
	//����,�ٸý���ϼ�����Ƿ���Ҫ���
	//��һ�����������[ǰ�����],[������]
	//�ڶ���������[ǰ������ĶԳ�],[������]
	//����[��]�Ѿ��������,�����ֱ���Ҫͬ���ؼ������¼��
	return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight)
	       && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}


//            8
//        6      6
//       5 7    7 5
int main() {
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode62 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode52 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode8, pNode61, pNode62);
	ConnectTreeNodes(pNode61, pNode51, pNode71);
	ConnectTreeNodes(pNode62, pNode72, pNode52);
	
	cout<<boolalpha<<isSymmetrical(pNode8);
	
	DestroyTree(pNode8);
	return 0;
}
