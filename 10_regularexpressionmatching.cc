#include <iostream>
using namespace std;

class Solution
{
public:
   
    bool isMatch(string s, string p)
    {
		int ns = s.length();
		int np = p.length();
		bool ismatch[ns+1][np+1];
		ismatch[0][0] = true;
		for(int i = 1; i <= ns; i++){
			ismatch[i][0] = false;
		}
		for(int j = 1; j <=np; j++){
			ismatch[0][j] = j >= 2 && p[j - 1] == '*' && ismatch[0][j - 2];
		}
		for(int i = 1; i <= ns; i++){
			for(int j = 1; j <= np; j++){
				if( p[j - 1] == '*'){
					ismatch[i][j] = ismatch[i][j - 2] 
						             || ( (s[i - 1] == p[j - 2] || p[j - 2] == '.')
						             && ismatch[i - 1][j]);
				}
				else 
					ismatch[i][j] = ismatch[i - 1][j - 1] &&
						(p[j - 1] == s[i - 1] || p[j - 1] == '.');
			}
		}
		return ismatch[ns][np];
    }
};

int main(){
	Solution t;
	string s = "aab";
	string p = "c*a*b*";
	if(t.isMatch(s,p))cout<<"1";
	else cout<<"0";
	return 0;
}
