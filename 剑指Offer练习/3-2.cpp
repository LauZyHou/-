#include<bits/stdc++.h>
using namespace std;

// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
//        start:       ��Χ����ʼֵ
//        end:         ��Χ����ֵֹ
// ����ֵ:
//        ��������ָ����Χ�ڵ����ֵ���Ŀ
int countRange(const int* numbers, int length, int start, int end)
{
	//�����������Ϸ��� 
    if(numbers == nullptr || length <= 0)
        return 0;

	//ͳ�Ʋ�������������ָ����Χ�ڵ����ָ��� 
    int count = 0;
    for(int i = 0; i < length; i++)
        if(numbers[i] >= start && numbers[i] <= end)
            ++count;
    return count;
}

// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
// ����ֵ:             
//        ����  - ������Ч�����������д����ظ������֣�����ֵΪ�ظ�������
//        ����  - ������Ч������������û���ظ�������
int getDuplication(const int* numbers, int length)
{
	//�����������Ϸ��� 
    if(numbers == nullptr || length <= 0)
        return -1;

	//��ʼ��������䷶Χ��0~n-1֮�� 
    int start = 0;
    int end = length - 1;
    //��������仹��ȷ���� 
    while(end >= start)
    {
    	//ȡ������м���,���仮�ֳ����������� 
        int middle = ((end - start) >> 1) + start;
        cout<<"middle="<<middle<<"\n";
        //�ж�һ������������ǰһ�������е����ĸ��� 
        int count = countRange(numbers, length, start, middle);
        
        //��ֹ����:�����������Ѿ���������ʣһ���� 
        if(end == start)
        {
        	//��ʱstart=middle=end,�ո�ͳ�Ƶ�Ҳ���������и����ĸ���
            if(count > 1)//�����������>1
                return start;//��ô��Ҫ����ظ��������� 
            else//����,û���ҵ��ظ����� 
                break;//ֱ���˳�Ѱ�� 
        }

		//�����ⲿ����û����[��ֹ����]ʱ�������е�
		
		//�������������ǰһ����������ĸ������������䳤��
		//˵�����ٴ���һ�����������,�����������ظ������˵� 
        if(count > (middle - start + 1))
            end = middle;//��˽�����ķ�Χ��С����ǰ��������� 
        else//���� 
            start = middle + 1;//������ķ�Χ��С������������ 
    }
	//��������,û���ҵ��ظ�����
	//���㷨���ܱ�֤���û���ظ�����,���������0113��0~3�������Ͽɱ����� 
	return -1;
}


int main(){
	//��0~3������,��������2,2,3,3����4��
	//��4~7������,��������4,5,6,7����4��
	//ʶ�𲻳���������µ��ظ�����
	//�������������ϴ�1~n-1�����������ʶ������� 
	int a[8]={2,3,5,4,3,2,6,7};
	cout<<getDuplication(a,8)<<"--------------------"<<endl;
	//������������Ҳ�Ҳ����ظ���1 
	int b[8]={0,1,1,3,4,5,6,7};
	cout<<getDuplication(b,8)<<"--------------------"<<endl;
	//�������ݾ����ҳ���
	int c[7]={3,1,2,0,2,5,3};
	cout<<getDuplication(c,7)<<"--------------------"<<endl;
	return 0;
}

