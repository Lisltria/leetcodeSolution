#include <iostream>
#include <string>
using namespace std;

class Solution {
	bool F[1001][1001];
public:
	string longestPalindrome(string s) {
		int start,end;
		if ( s=="" ) return "";
		for ( int i=0; i < (int)s.length(); i++ )
			for ( int j=0; j < (int)s.length(); j++ ) 
		   		F[i][j] = false;	
		for ( int i=0; i < (int)s.length(); i++ ) {
			F[i][i]=true;
			if ( i+1 < (int)s.length() && s[i] == s[i+1] ) {
				F[i][i+1]=true;
			}
		}
		for ( int i=0; i < (int)s.length(); i++ ) {
			for ( int j=i; j < (int)s.length(); j++ ) {
				int v = 1;
				while ( i-v>=0 && j+v <(int)s.length() ) {
					if ( F[i-v+1][j+v-1]==true && s[i-v]==s[j+v] ) {
						F[i-v][j+v] = true;
						v++;
					}
					else
						break;
				}				
			}
		}
		int max = 0;
		for ( int i=0; i < (int)s.length(); i++ ) {
			for ( int j=i; j < (int)s.length(); j++ ) {
				if ( F[i][j] == true && j-i+1 > max ) {
				   max = j-i+1;
				   start = i;
				   end =j;
				}	   
			}
		}
		return s.substr( start, end-start+1 );
	}
};

int main() {
	Solution temp;
	cout<<temp.longestPalindrome("abcbe");
	return 0;
}
