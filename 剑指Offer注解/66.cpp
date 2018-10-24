#include<bits/stdc++.h>
using namespace std;

//�����˻�����,A=input,B=output
void BuildProductionArray(const vector<double>& input, vector<double>& output) {
	//A��B�ĳ���
	int length1 = input.size();
	int length2 = output.size();

	//�Ϸ��Լ��:A��B�ĳ�����Ҫһ��,���Ҷ�����1
	if(length1 == length2 && length2 > 1) {
		//���϶��¼���C[i]����,������output������
		output[0] = 1;//C[0]=1
		for(int i = 1; i < length1; ++i) {//���϶���
			output[i] = output[i - 1] * input[i - 1];//C[i]=C[i-1]*A[i-1]
		}

		//���¶��ϼ���D[i]����,˳���C[i]��˼�Ϊ���������output������
		double temp = 1;//D[length-1]=1
		for(int i = length1 - 2; i >= 0; --i) {//���¶���
			temp *= input[i + 1];//D[i]=D[i+1]*A[i+1]
			output[i] *= temp;//�˵�C[i]��
		}
	}
}

int main() {
	double input[] = { 1, 2, 3, 4, 5 };
	double output[] = { 0, 0, 0, 0, 0 };
	vector<double> A(input,input+sizeof(input)/sizeof(double));
	vector<double> B(output,output+sizeof(output)/sizeof(double));
	BuildProductionArray(A,B);
	for(vector<double>::const_iterator cit=B.cbegin();cit!=B.cend();cit++){
		cout<<*cit<<" ";
	}//120 60 40 30 24
	return 0;
}
