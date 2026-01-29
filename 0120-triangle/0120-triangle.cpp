class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();  //no of rows
        vector<vector<int>> dp(n, vector<int>(n,-1));
        dp[0][0] = triangle[0][0];
        int up, uleft;

        for( int r = 1; r<n; r++){
            for( int c = 0; c<=r; c++ ){
                up = INT_MAX;
                uleft = INT_MAX;

                if( c<r ){
                    up = dp[r-1][c];
                }
                
                if( c>=1 ){
                    uleft = dp[r-1][c-1];
                }

                dp[r][c] = min( up, uleft ) + triangle[r][c];
            }
        }
        int ans = dp[n-1][0];
        for( int it : dp[n-1] ){
            ans = min (ans, it);
        }
        return ans;
    }
};