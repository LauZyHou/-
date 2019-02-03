#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 30010;

int n;
int p[N];

int main() {
	cin>> n;
	for(int i=0; i<n; i++)
		cin>>p[i];
	if(n==1)
		cout<<(p[0]?p[0]:-1)<<endl;
	else if(p[0]<=p[n-1])
		cout<<-1<<endl;
	else {
		vector<int> sets;
		//����,�ҵ��ڵ�һ���������һ����֮������ŵ�������
		for(int i=1; i<n-1; i++) {
			if(p[i]<p[0] && p[i]>p[n-1]) {
				sets.push_back(p[i]);
			}
		}

		if(sets.size()) { //���ϲ�Ϊ��
			for(int i=14,k=0; i>=0; i--) {

				//�ѵ�ǰ��һλ��1�Ļ���ǰ��ȥ(��kλ��)
				for(int j=k; j<sets.size(); j++) {
					if(sets[j]>>i & 1) {
						swap(sets[j],sets[k]);
						break;//ֻҪһ��������
					}
				}

				//��ǰ��һλ�ҵ���1
				if(sets[k]>>i & 1) {
					//�Ѻ����������һλ��Ū��0
					for(int j=k+1; j<sets.size(); j++) {
						if(sets[j]>>i & 1)
							sets[j]^=sets[k];
					}
					k++;
				}

			}
		}

		int res=p[0]^p[n-1];
		//�����λ��ʼ,����ÿһλ��û�п�����1,���������1�Ͱ������1
		if(sets.size()) {
			for(int i=14,k=0; i>=0; i--) {
				if(sets[k]>>i & 1) {
					//�Ѿ�����õĽ����һλ�������1,�����һ�����Ա��1
					if(!(res>>i & 1))
						res^=sets[k];
					k++;
				}
			}
		}

		if(!res)
			res=-1;
		cout<<res<<endl;

	}

	return 0;
}
