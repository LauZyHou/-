class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
		nums.push_back(1);//1,...,1
		int n = nums.size();
		
		vector<vector<int>> dp(n,vector<int>(n));
		//������nums[0][n-1]
		//dp[i][j]��j=i+len,��ʾ��i+1��j-1֮���ܻ�õĽ�����ֵ
		//dp[i][j] = ����kʹ�� dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j] ���
		for(int len=2;len<n;len++) {
			for(int i=0;i+len<n;i++) {
				int j = i+len;
				for(int k=i+1;k<j;k++)
					dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);
			}
		}
		return dp[0][n-1];
    }
};