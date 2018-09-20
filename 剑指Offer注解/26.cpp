#include<bits/stdc++.h>
#include "../Utilities/DblBinaryTree.h"
using namespace std;

bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);
bool Equal(double num1, double num2);

//�ݹ麯��,��������������(����),�жϵڶ����Ƿ��ǵ�һ�����ӽṹ
bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	bool result = false;

	//������������Ϊ��ʱ�����ж�
	if(pRoot1 != nullptr && pRoot2 != nullptr) {
		if(Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))//���������ͬ
			result = DoesTree1HaveTree2(pRoot1, pRoot2);//�Ӹ�λ�ÿ�ʼ�ж��ǲ��ǲм�����
		if(!result)//�����һ���ж�����Ȼ��false
			result = HasSubtree(pRoot1->m_pLeft, pRoot2);//�ӵ�1�������������ϵ����������ж�
		if(!result)//�����һ���ж�����Ȼ��false
			result = HasSubtree(pRoot1->m_pRight, pRoot2);//�ӵ�1�������������ϵ����������ж�
	}

	return result;
}

//�ݹ麯��,��������������(����),�жϵڶ����Ƿ��ǵ�һ���Ĳм����
//���ڶ����Ƿ��ǵ�һ��ȥ��һЩ�Ǹ����,����ȥ��ȫ�����(nullptr)�����
bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	if(pRoot2 == nullptr)//����ڶ���Ϊ��
		return true;//�൱�ڵ�һ��ȥ�������н��

	if(pRoot1 == nullptr)//����ڶ�����Ϊ��(ִ������),�ҵ�һ��Ϊ��
		return false;//��ô��һ����ôȥ��������

	//����,����������Ϊ��,Ҫ���ݹ��ж�

	if(!Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))//����������ĸ��ڵ㶼�����
		return false;//��ôҲ�Ǵӵ�1��������ôȥ��������

	//�ݹ���ж����������Ƿ�Ҳ�ֱ��ǵ�1���������������Ĳм����
	return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) &&
	       DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

//�ж��������������
bool Equal(double num1, double num2) {
	//���ж�����֮��Ĳ�ֵ�㹻С
	if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

// ���н�㺬�зֲ�,��B����A���ӽṹ
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7
bool test1() {
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

	return HasSubtree(pNodeA1,pNodeB1);
}

// ���н�㺬�зֲ�,��B������A���ӽṹ
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     3
//               / \
//              4   7
bool test2() {
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);
	
	return HasSubtree(pNodeA1,pNodeB1);
}

int main() {
	cout<<boolalpha<<test1()<<endl;
	cout<<boolalpha<<test2()<<endl;
	return 0;
}
