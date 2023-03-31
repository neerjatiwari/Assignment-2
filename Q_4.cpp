class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        int n = s.length();
        if(s[n-1]=='1') return false;
        
        vector<int> preSum(n,0);
        
        int sum = 1;
        preSum[n-1] = 1;
        int res;
        bool ans;
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            res = 0;
            
            if(s[i]=='0')
            {
                if(i+minJump < n)
                {
                    if(i+maxJump >= n-1)
                    {
                        res = preSum[i+minJump] ;
                    }
                    else
                    {
                        res = preSum[i+minJump] - preSum[i+maxJump+1];
                    }
                }
            }
            
            if(res) sum++;
            ans = res;
            preSum[i] = sum;
        }
        
        return ans;
    }
};

