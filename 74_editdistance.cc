#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2){
		vector<vector<int> > dp(word1.size()+1, vector<int>(word2.size()+1));
		dp[0][0] = 0;
		for(int i = 1; i <= (int)word1.size(); i++){
			dp[i][0] = i; 
		}
		for(int j = 1; j <= (int)word2.size(); j++){
			dp[0][j] = j;
		}
		for(int i = 1; i <= (int)word1.size(); i++){
			for(int j = 1; j <= (int)word2.size(); j++){
				if( word1[i-1] == word2[j-1]){
					dp[i][j] = dp[i-1][j-1];
				}
				else{
					dp[i][j] = dp[i-1][j-1];
					if(dp[i][j]>dp[i][j-1])dp[i][j] = dp[i][j-1];
					if(dp[i][j]>dp[i-1][j])dp[i][j] = dp[i-1][j];
					dp[i][j]++;
				}
			}
		}
		return dp[word1.size()][word2.size()];

	}
};

int main(){
	string a = "intention";
	string b = "execution";
	Solution t;
	cout<<t.minDistance(a, b);
	return 0;
}

