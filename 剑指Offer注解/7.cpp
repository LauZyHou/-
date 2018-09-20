#include "../Utilities/BinaryTree.h"
#include<bits/stdc++.h>
#include<exception>
using namespace std;

// ����:
//        startPreorder:     ��ǰǰ��������鿪ͷ��ַ
//        endPreorder:       ��ǰǰ����������β��ַ
//        startInorder:      ��ǰ����������鿪ͷ��ַ
//        endInorder:        ��ǰ������������β��ַ
// ����ֵ:
//        �������ǰ��������������������Ķ���(��)���ĸ��ڵ��ַ
BinaryTreeNode* ConstructCore
(
    int* startPreorder, int* endPreorder,
    int* startInorder, int* endInorder
) {
	//����ǰ��������еĵ�һ�����ִ��������
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;//����������ʼ��Ϊ��

	//[�ݹ����]���ǰ��������п�ͷ�ͽ�β��ַһ��,��ֻ����һ��ֵ
	if(startPreorder == endPreorder) {
		//��ʱȥ�������������,Ҳ�����ǿ�ͷ�ͽ�β��ַһ��,��ֻ��һ��ֵ
		//�����ֵ��ǰ��������е�ֵ���,���Ǹ��ڵ��ֵ
		if(startInorder == endInorder && *startPreorder == *startInorder)
			return root;//��ʱ�����Ķ�������ֻ����һ�����ڵ�,����
		else//����,˵�������������ǲ���Ӧ��,�޷��������������
			throw exception();
	}

	//ҪѰ��������������и�����ָ��λ��,������������п�ͷ����ʼ
	int* rootInorder = startInorder;
	//��û�г��������������ĩβ���,�Ҳ�����ǰ��������е�һ������ʱ
	while(rootInorder <= endInorder && *rootInorder != rootValue)
		++ rootInorder;//һֱ������

	//�����Ժ�,�ж�һ��,�����ǰ�ߵ���ĩβ,���һ���û���������
	if(rootInorder == endInorder && *rootInorder != rootValue)
		throw exception();//˵�������������ǲ�ƥ���,����

	//����,�Ѿ��ҵ���������������и�����ָ��λ��

	//��ʱ�������ĳ��ȾͿ�����������и��ڵ�����м�����(�����������)
	int leftLength = rootInorder - startInorder;
	//����������������,��ǰ����������ҵ����������е�ĩβ��
	int* leftPreorderEnd = startPreorder + leftLength;
	//��ô������һ����Ҳ�������������е���ʼ��!

	//�����������㲻Ϊ0,������������
	if(leftLength > 0) {
		//�ݹ�����������������������
		//ǰ��������:��ʼ��ֻҪȥ�������,��ֹ��ոռ��������
		//����������:��ʼ�㻹�Ǵ��������е���ʼ��,��ֹ��Ҫ�Ӹ������ǰһ��
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd,
		                              startInorder, rootInorder - 1);
		//����֮��ҳɱ����������
	}
	//��������������û��ռ����˿�ͷ���ڵ��ʣ�µ����н��,������������
	if(leftLength < endPreorder - startPreorder) {
		//�ݹ�����������������������
		//ǰ��������:��ʼ��ոռ��������������������+1,��ֹ��ʹ�ô����ֹ��
		//����������:��ʼ��Ҫ�Ӹ��������һ��,��ֹ��ʹ�ô����ֹ��
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder,
		                               rootInorder + 1, endInorder);
		//����֮��ҳɱ����������
	}

	return root;//���ع���õĽ����ϲ������
}


// ����:
//        preorder:     ǰ�������������
//        inorder:      ���������������
//        length:       ����ĳ���,��������һ��
// ����ֵ:
//        �������ǰ��������������������Ķ������ĸ��ڵ��ַ
BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
	//����Ϸ���У��
	if(preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;

	//���õݹ�Ĺ�����ĺ���,������������ǰ��ֵ,��������ö�����
	return ConstructCore(preorder, preorder + length - 1,
	                     inorder, inorder + length - 1);
}

//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
int main() {
	const int length = 8;//���г��� 
	int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};//ǰ�� 
	int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};//����
	 
	try {
		//ʹ��ǰ������������ö�����,��ø��ڵ� 
		BinaryTreeNode* root = Construct(preorder, inorder, length); 
		PrintTree(root);//��� 
		DestroyTree(root);//���� 
	} catch(exception& exception) {
		printf("Invalid Input.\n");
	}
}

