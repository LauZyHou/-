#include<iostream>
using namespace std;

class Solution {
	public:
		int  NumberOf1(int n) {
			unsigned int test=1;
			int count=0;
			while(test!=0){//���1�������ʱ�������־ͱ��0�� 
				if(n & test)
					count++;
				test=test<<1;
			}
			return count;
		}
};

int main() {


	return 0;
}
