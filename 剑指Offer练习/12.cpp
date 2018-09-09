#include<bits/stdc++.h>
using namespace std;


// ����:
//        matrix:      �ַ������׵�ַ
//        rows:        ���������
//        cols:        ���������
//        row:         ��ǰ��
//        col:         ��ǰ��
//        str:         Ҫ������ַ���������
//        pathLength:  ���������ƥ���·������
//        visited:     �����������
// ����ֵ:
//        �������ƥ��,true��ʾ�ɹ�ƥ��,false��ʾƥ��ʧ��
bool hasPathCore(const char* matrix, int rows, int cols, int row,
                 int col, const char* str, int& pathLength, bool* visited) {
	if(str[pathLength] == '\0')//����Ѿ�ƥ���������ַ�����,����β��
		return true;//��Ȼֱ�ӷ���true,��ʾ����������ַ���ƥ��

	bool hasPath = false;//��¼�Ƿ���ڸ�λ�õ�ƥ��
	//����α��ںϷ���Χ��,�����λ�õ�ֵ����ƥ��,��û�з��ʹ�
	if(row >= 0 && row < rows && col >= 0 && col < cols
	        && matrix[row * cols + col] == str[pathLength]
	        && !visited[row * cols + col]) {
		++pathLength;//·����ǰ+1
		visited[row * cols + col] = true;//�����λ�ñ��Ϊ���ʹ���

		//�ݹ��������,����/��/��/���ĸ�����ƥ��
		hasPath = hasPathCore(matrix, rows, cols, row, col - 1,
		                      str, pathLength, visited)
		          || hasPathCore(matrix, rows, cols, row - 1, col,
		                         str, pathLength, visited)
		          || hasPathCore(matrix, rows, cols, row, col + 1,
		                         str, pathLength, visited)
		          || hasPathCore(matrix, rows, cols, row + 1, col,
		                         str, pathLength, visited);
		//����ĸ����򶼲�����ƥ��,˵�����λ���ߴ���
		if(!hasPath) {
			--pathLength;//�����һ��
			visited[row * cols + col] = false;//���λ��ȡ�����
		}
	}
	return hasPath;//���ش����λ���ܷ����ƥ��
}

// ����:
//        matrix:      �ַ������׵�ַ
//        rows:        ���������
//        cols:        ���������
//        str:         Ҫ������ַ���������
// ����ֵ:
//        true��ʾ�ҵ�,false��ʾ�Ҳ���
bool hasPath(const char* matrix, int rows, int cols, const char* str) {
	//����Ϸ��Լ��
	if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
		return false;

	//���ַ������Сһ���Ĳ���ֵ����,������ʶĳ��λ���Ƿ���ʹ���
	bool *visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);//����Ϊ0������Ϊfalse

	int pathLength = 0;//·���ĳ���,��ʼ��Ϊ0
	//������������
	for(int row = 0; row < rows; ++row) {
		for(int col = 0; col < cols; ++col) {
			//����ƥ��ĺ���,�Ӿ����ϵ�ÿ���㿪ʼ�����ܷ����ƥ��
			if(hasPathCore(matrix, rows, cols, row, col, str,
			               pathLength, visited)) {
			    delete[] visited;//���ϵĴ���ȱ��һ��,�ɹ������ҲҪ��ȷ���� 
				return true;
				//ֻҪ���һ��ƥ��ͷ���true��,���Բ����������Ǿ���
				//���ǽ��䳹�׻��� 
			}
		}
	}
	delete[] visited;//�ͷŸ�������Ŀռ�
	return false;//��������,˵��ƥ��ʧ��,����false 
}


//ABTG
//CFCS
//JDEH
int main() {
	const char* matrix = "ABTGCFCSJDEH";
	const char* str = "BFCE";
	cout<<boolalpha<<hasPath(matrix,4,4,str)<<endl;
	return 0;
}

