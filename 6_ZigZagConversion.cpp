#include <iostream>

using namespace std;
class Solution {
public :
	string convert(string s, int numRows) {
		string sol = "";
		int pointer = 0;
		int c1 = (numRows - 2 ) * 2 + 1, c2 = -1;
		for ( int i=1; i <= numRows ; i++ ) {
			pointer = i-1;
			while ( pointer < s.length() ) {
				if ( i!= numRows ) {
					sol += s[pointer];
					pointer += c1+1 ;
				}
				if ( i != 1 && pointer < s.length() ) {
					sol += s[pointer];
					pointer += c2+1;
				}
			}
			c1 -= 2;
			c2 += 2;
		}
		if(numRows==1)return s;
		return sol;
	}
};

int main() {
	Solution temp;
	cout<<temp.convert("PAYPALISHIRING",4)<<endl;
	return 0;
}
