#include<bits/stdc++.h>
using namespace std;

// ����:
//        matrix:      һ����ά����
//        rows:        ��������� 
//        columns:     ���������  
//        number:      Ҫ���ҵ����� 
// ����ֵ:
//        true��ʾ�ҵ��ˣ�false��ʾ�Ҳ��� 
bool Find(int* matrix, int rows, int columns, int number)
{
    bool found = false;//��ʶ�Ƿ��ҵ������� 

    if(matrix != nullptr && rows > 0 && columns > 0)//����Ϸ��Լ�� 
    {
    	//���������Ͻ�(0,columns-1)��ʼ�Ƚ� 
        int row = 0;
        int column = columns - 1;
        //�к���������,�к����𽥼�С,����Խ�� 
        while(row < rows && column >=0)
        {
        	//row*columns+column���Ƕ�ά�����е�row�е�column�е�����
			//���������ֺ�numberһ��,���Ѿ��ҵ����� 
            if(matrix[row * columns + column] == number)
            {
                found = true;//��ʶ��Ϊ�� 
                break;//�˳�ѭ�� 
            }
            //���������ֱ�Ҫ�ҵ����ִ� 
            else if(matrix[row * columns + column] > number)
                -- column;//��ôҪˢȥ��ǰ��һ��,����ߵ��Ӷ�ά����ȥ�� 
            //���������ֱ�Ҫ�ҵ�����С 
			else
                ++ row;//��ôҪˢȥ��ǰ��һ��,���±ߵ��Ӷ�ά����ȥ��
        }
    }

    return found;
}

int main(){
	//C++ȷ���س�ʼ����ά����,�����������Զ�ʶ�� 
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	cout<<boolalpha<<Find((int*)matrix, 4, 4, 7)<<endl;
	return 0;
}
