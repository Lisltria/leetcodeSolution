#include <iostream>
#include <string>
#include <set>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n=s.length();
		int ans=0;
		set<char>ss;
		int i=0,j=0;
		while( i<n && j<n) {
			if (ss.find(s[j]) == ss.end()) {
				ss.insert(s[j]);
				j++;
				ans= ans > j-i ? ans : j-i;
			}
			else {
				ss.erase(s[i]);
				i++;
			}
		}
		return ans;
	}
};

int main()
{
	Solution temp;
	string s1="abcabcbb";
	string s2="bbbb";
	string s3="pwwkew";
	cout<<temp.lengthOfLongestSubstring(s1)<<endl;
	cout<<temp.lengthOfLongestSubstring(s2)<<endl;
	cout<<temp.lengthOfLongestSubstring(s3)<<endl;
	return 0;
}
