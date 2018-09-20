#include<bits/stdc++.h>
#include "../Utilities/BinaryTree.h"
using namespace std;

void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int& currentSum);

// ����:
//        pRoot:         ��������
//        expectedSum:   �����·����
// ���:
//        �ҵ���·��
void FindPath(BinaryTreeNode* pRoot, int expectedSum) {
	if(pRoot == nullptr)
		return;
	//��vectorģ��ջ,��Ϊ��ӡ·��ʱ��Ҫ�õ�·�������н��,stack������
	vector<int> path;
	int currentSum = 0;//��ǰ·���ϵļӺ�
	FindPath(pRoot, expectedSum, path, currentSum);
}

//�ݹ麯��,�ڶ���������,���ݵ�ǰ�Ѽ�鵽��·���ͼ������,ֱ��Ҷ��
void FindPath
(
    BinaryTreeNode*   pRoot,		//����(��)����
    int               expectedSum,	//�����·����
    vector<int>&      path,			//��¼��ǰ·���Ͻ���ջ
    int&              currentSum	//��ǰ·���ϵļӺ�
) {
	currentSum += pRoot->m_nValue;	//��ǰ·����Ҫ������������ĸ�ֵ
	path.push_back(pRoot->m_nValue);//������뵽ջ��(β��)

	//�ж��Ƿ�Ҷ��:���Һ��Ӷ�Ϊ�վ���Ҷ���
	bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;
	//���·���Ͻ��ĺ͵��������ֵ,������Ҷ���
	if(currentSum == expectedSum && isLeaf) {
		//��ʱ���ҵ�������·��
		printf("A path is found: ");
		//�õ�������ͷ��β�������·���ϵĽ��ֵ
		vector<int>::iterator iter = path.begin();
		for(; iter != path.end(); ++ iter)
			printf("%d\t", *iter);
		printf("\n");
	}

	//�������Ҷ���,����������ӽ��
	if(pRoot->m_pLeft != nullptr)
		FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	if(pRoot->m_pRight != nullptr)
		FindPath(pRoot->m_pRight, expectedSum, path, currentSum);

	//�ڷ��ص������֮ǰ,��·����ɾ����ǰ���
	path.pop_back();//���䵯��(β��)
	//���ڵ�ǰ·�����м�ȥ�������ֵ
	currentSum -= pRoot->m_nValue;
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7  
int main() {
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode10, pNode5, pNode12);
	ConnectTreeNodes(pNode5, pNode4, pNode7);
	
	FindPath(pNode10,22);
	
	DestroyTree(pNode10);

	return 0;
}
