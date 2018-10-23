#include<bits/stdc++.h>
#include "../Utilities/BinaryTree.h"
using namespace std;


//�ݹ麯��:�������(��)����,����k,���������������(ʣ�µ�)��k�����
//k�����ô���,��ı����Ӱ�쵽����ĵݹ��,k�ڵ�����ÿ�ҵ�һ���ͼ�С1
const BinaryTreeNode* KthNodeCore(const BinaryTreeNode* pRoot, unsigned int& k) {
	const BinaryTreeNode* target = nullptr;//��Ҫ�ҵ�Ŀ����

	if(pRoot->m_pLeft != nullptr)//����������
		//�ݹ��������������,һֱ��û���������Ľ����ǵ�һ�����
		//���Եݹ�����е�kû�з����ı�
		target = KthNodeCore(pRoot->m_pLeft, k);

	if(target == nullptr) {//���û����������,�������������Ҳ�����k���(��������㲻��)
		if(k == 1)//������ҵ�1�����(����ʱ��ֻ����û����������)
			target = pRoot;//���"��"���ǵ�1�����
		k--;//���������ȥ
		//���û�����������if,���ǽ������������ȥ
		//��ʱû�и���target,������һ���ϻ�û���ҵ���k�����
	}

	//������Ҫ�������������������ʣ�µ�k=k-1�������(kֵ�Ѿ���k--����)

	//��һ������:��һ����������͸���㶼�����˽�㻹�ǲ���
	//�ڶ�������:����������,��ʱ��������������
	if(target == nullptr && pRoot->m_pRight != nullptr)
		//����������,�ݹ����(��������ÿ�����ҲҪ�����������˳��)
		target = KthNodeCore(pRoot->m_pRight, k);

	//������һ��
	return target;//�������nullptr��ʾҪ�ҵĽ�㲻�����(������)��
}

//�Ҹ�����������������ĵ�k�����
const BinaryTreeNode* KthNode(const BinaryTreeNode* pRoot, unsigned int k) {
	if(pRoot == nullptr || k == 0)//��������һ������Ϸ��Լ��
		return nullptr;

	return KthNodeCore(pRoot, k);
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
	
	cout<<KthNode(pNode8,5)->m_nValue<<endl;

	DestroyTree(pNode8);//9
	
	return 0;
}
