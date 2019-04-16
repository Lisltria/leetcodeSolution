#include <iostream>
#include <climits>
using namespace std;
class Solution {
public:
    int myAtoi(string str){
		int i = 0;
		long long ans = 0;
		bool f = true;
		while(str[i] == ' ')i++;
		if(str[i] == '+' || str[i] == '-'){
			f = str[i] == '+' ? true : false;
			i++;
		}
		
		while(i<(int)str.length() && str[i] >= '0' && str[i] <= '9'){
			ans = ans * 10 + (str[i] - 48);
			if(f && ans >= INT_MAX) return INT_MAX;
			if(!f && -ans <= INT_MIN )return INT_MIN;
			i++;
		}
		return f ? ans : -ans;
	}
};

int main(){
	Solution t;
	string s("456546456456456456456");
	cout<<t.myAtoi(s);
	return 0;
}
