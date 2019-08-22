//https://www.nowcoder.com/discuss/95743
//��Ҫע��,�������/��Сʱ��,��ߺ��ұ�ֻ��һ�ߴ��Ⱥ�,�����ظ�Ԫ��AB�Ͳ����ظ�����
//Ҳ����˵��A�ҵ�B,��ô�ʹ�B�����һ�A
//���ߴ�B�ҵ�A,��ô��A�����ҵ�B

#include<bits/stdc++.h>
using namespace std;

void myprint(vector<long long>& v) {
	int len = v.size();
	for(int i=0;i<len;i++)
		cout<<v[i]<<" ";
	cout<<endl;
}

void myprint(vector<int>& v) {
	int len = v.size();
	for(int i=0;i<len;i++)
		cout<<v[i]<<" ";
	cout<<endl;
}

int main() {
	int n;
	cin >> n;
	if (n <= 1) {
		cout << 0;
		return 0;
	}
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	myprint(a);//3 2 2 2 1 4

	stack<pair<int, int> > s;//���ֵط�Ҫ�����ո�,����д��>>
	vector<int> c(n), d(n);
	//����c����,c[i]��ʾ��a[i]�����<=a[i]�����Ԫ��a[j]���±�j
	for (int i = 0; i < n; i++) {
		while (!s.empty() && s.top().first > a[i])
			s.pop();
		if (s.empty())
			c[i] = -1;
		else
			c[i] = s.top().second;
		s.push({ a[i], i });//����pair
	}
	
	myprint(c);//-1 -1 1 2 -1 4

	s = stack<pair<int, int> >();//���ջ
	//����d����,d[i]��ʾ��a[i]�ұ���<a[i]�����Ԫ��a[k]���±�k
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && s.top().first >= a[i])
			s.pop();
		if (s.empty())
			d[i] = n;
		else
			d[i] = s.top().second;
		s.push({ a[i], i });
	}

	myprint(d);//1 4 4 4 6 6

	long long res = 0;
	for (int i = 0; i < n; i++) {
		//��(i - c[i]) * (d[i] - i)��ô�������a[i]��������a[i]����С��,�����ȥ
		res -= a[i] * (i - c[i]) * (d[i] - i);
	}

	s = stack<pair<int, int> >();
	//����c����,c[i]��ʾ��a[i]�����>a[i]�����Ԫ��a[j]���±�j
	for (int i = 0; i < n; i++) {
		while (!s.empty() && s.top().first <= a[i])
			s.pop();
		if (s.empty())
			c[i] = -1;
		else
			c[i] = s.top().second;
		s.push({ a[i], i });
	}
	
	myprint(c);//-1 0 0 0 3 -1

	s = stack<pair<int, int> >();
	//����d����,d[i]��ʾ��a[i]�ұ���>=a[i]�����Ԫ��a[k]���±�k
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && s.top().first < a[i])
			s.pop();
		if (s.empty())
			d[i] = n;
		else
			d[i] = s.top().second;
		s.push({ a[i], i });
	}
	
	myprint(d);//5 2 3 5 5 6

	for (int i = 0; i < n; i++) {
		//��(i - c[i]) * (d[i] - i)��ô�������a[i]��������a[i]������,�������
		res += a[i] * (i - c[i]) * (d[i] - i);
	}

	cout << res;
	return 0;

}
