class Solution {
public:
	bool ruse[9][10] = {false};//9��9����(1~9)
	bool cuse[9][10] = {false};//9��9����
	bool buse[3][3][10] = {false};//3*3������9����
	int rlen;
	int clen;

	void init() {
		for(int i=0;i<9;i++)
			for(int j=1;j<10;j++)
				ruse[i][j] = cuse[i][j] = false;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				for(int k=1;k<10;k++)
					buse[i][j][k] = false;
	}

	//�ݹ����
	bool rec(vector<vector<char>>& vv,int r,int c) {
		//һ�������
		if(c==clen) {
			c = 0;
			r++;
			if(r==rlen)//ÿ�ж�������
				return true;//������
		}
		//�ǿ�,���������һ��λ��
		if(vv[r][c]!='.')
			return rec(vv,r,c+1);
		//��,�������,����ÿ������
		for(int num=1;num<=9;num++) {
			//���bool�����Ƿ����
			bool canuse = !ruse[r][num] && !cuse[c][num] && !buse[r/3][c/3][num];
			if(!canuse)
				continue;
			//����,��һ�����Լ������µݹ��ܲ��ܵõ�true
			ruse[r][num] = true;
			cuse[c][num] = true;
			buse[r/3][c/3][num] = true;
			vv[r][c] = char(num+'0');

			if(rec(vv,r,c+1))
				return true;

			//���ܵõ�true,��ԭ����״̬��������һ������
			ruse[r][num] = false;
			cuse[c][num] = false;
			buse[r/3][c/3][num] = false;
			//vv[r][c] = '.';
		}
		//ֻ��Ҫ�����ﻹԭ
		vv[r][c] = '.';
		//�����û�ҵ����õ�����,˵����ǰ���ѡ��������,����false
		return false;
	}

    void solveSudoku(vector<vector<char>>& vv) {
        rlen = vv.size();
		if(!rlen)
			return ;
		clen = vv[0].size();
		if(!clen)
			return ;

		init();

		//��ʼ��,vv���Ѿ��е����־���Ϊtrue
		for(int i=0;i<rlen;i++) {
			for(int j=0;j<clen;j++) {
				int n = vv[i][j]-'0';
				if(1<=n && n<=9)
					ruse[i][n] = cuse[j][n] = buse[i/3][j/3][n] = true;
			}
		}
		//�ݹ����
		rec(vv,0,0);
    }
};