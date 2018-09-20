#include<bits/stdc++.h>
using namespace std;

/*��������*/
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited);
bool check(int threshold, int rows, int cols, int row, int col, bool* visited);
int getDigitSum(int number);

// ����:
//        threshold:      ��ֵ,����Ŀ�е�kֵ
//        rows:           ���������
//        cols:           ���������
// ����ֵ:
//        ��ĿҪ��Ľ��,�������˿ɴ�ĸ�����Ŀ
int movingCount(int threshold, int rows, int cols) {
	//����Ϸ��Լ��
	if(threshold < 0 || rows <= 0 || cols <= 0)
		return 0;
	//���������������,ȫ����ʼ��Ϊfalse
	bool *visited = new bool[rows * cols];
	for(int i = 0; i < rows * cols; ++i)
		visited[i] = false;
	//�����Ͻ�(0,0)�㿪ʼ,���������Ѱ�ɴ��ĺ���������ɴ����Ŀ
	int count = movingCountCore(threshold, rows, cols,
	                            0, 0, visited);
	delete[] visited;//�ͷŸ����ռ�(�����������)
	return count;
}

// ����:
//        threshold:      ��ֵ,����Ŀ�е�kֵ
//        rows:           ���������
//        cols:           ���������
//        row:            ��ǰ��
//        col:            ��ǰ��
//        visited:        �����������
// ����ֵ:
//        �Ӹõ㿪ʼ(�з�������������Ʋ��ظ�),�·��ֵĿɴ����Ŀ
int movingCountCore(int threshold, int rows, int cols, int row,
                    int col, bool* visited) {
	int count = 0;//����(�·��ֵĿɴ����Ŀ),��0��ʼ
	//��鵱ǰ���ǿ��Խ����
	if(check(threshold, rows, cols, row, col, visited)) {
		visited[row * cols + col] = true;//���õ���Ϊ�ѱ�����
		//��Ϊ�õ���Խ���,���Լ���Ҫ���������,��1��ʼ��
		//�ݹ����,������/��/��/���ĸ������ֵĿɴ����Ŀ
		count = 1 + movingCountCore(threshold, rows, cols,
		                            row - 1, col, visited)
		        + movingCountCore(threshold, rows, cols,
		                          row, col - 1, visited)
		        + movingCountCore(threshold, rows, cols,
		                          row + 1, col, visited)
		        + movingCountCore(threshold, rows, cols,
		                          row, col + 1, visited);
	}
	//������ܽ���,��Ȼ����0
	return count;//���ؼ���
}

// ����:
//        threshold:      ��ֵ,����Ŀ�е�kֵ
//        rows:           ���������
//        cols:           ���������
//        row:            ��ǰ��
//        col:            ��ǰ��
//        visited:        �����������
// ����ֵ:
//        true��ʾ�ܽ���÷���,false��ʾ����
bool check(int threshold, int rows, int cols, int row, int col,
           bool* visited) {
	//��������Ϸ�,�����е�λ��֮�Ͳ�������ֵ,�Ҹ�λ��δ���ʹ�
	if(row >= 0 && row < rows && col >= 0 && col < cols
	        && getDigitSum(row) + getDigitSum(col) <= threshold
	        && !visited[row* cols + col])
		return true;//������Щ����,���ܽ����������
	return false;//�����ܽ���
}

//����������number,����������λ֮��
int getDigitSum(int number) {
	int sum = 0;
	while(number > 0) {
		sum += number % 10;//�����λȡ�����ӵ��ܺ���
		number /= 10;//ȥ�����λ
	}
	return sum;
}

int main() {
	cout<<movingCount(15,20,20)<<endl;
	return 0;
}
