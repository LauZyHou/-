#include<bits/stdc++.h>
using namespace std;

int howManyTransfer(int m,int n){
	int k=m^n;//������н���ͬΪ��ǳ���1
	//�����������1�ĸ���
	int count=0;
	while(k){
		k=k&(k-1);
		count++;
	} 
	return count;
}

int main(){
	cout<<howManyTransfer(8,9)<<endl;
	cout<<howManyTransfer(13,10)<<endl;
	cout<<howManyTransfer(11,-1)<<endl;
	return 0;
}
