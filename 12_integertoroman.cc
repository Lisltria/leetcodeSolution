#include <iostream>
using namespace std;

class Solution {
public:
	string intToRoman(int num){
		int n1,n2,n3,n4;
		string s = "";
		n1 = num / 1000;
		n2 = (num - n1 *1000) / 100;
		n3 = (num % 100) /10;
		n4 = num % 10;
		if(n1 != 0){
			switch(n1){
				case 1: s += "M";
					    break;
				case 2: s += "MM";
						break;
				case 3: s += "MMM";
						break;	
			}
		}
		if(n2 != 0){
			string roman[9] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC","CM"};
			s += roman[n2 - 1];
		}
		if(n3 != 0){
			string roman[9] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
			s += roman[n3 - 1];
		}
		if(n4 != 0){
			string roman[9] = {"I","II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
			s += roman[n4 -1];
		}
		return s;
	}
};

int main() {
	Solution t;
	cout<< t.intToRoman(1008);
	return 0;
}
