#include <iostream>
#include <vector>
using namespace std;

class Solution{
	public:
		int maxArea(vector<int>& height){
			int area = 0;
			int left = 0;
			int right = height.size() - 1;
			while(left < right){
				int t = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
				area = area < t ? t :area;
				if( height[left] < height[right]){
					left++;
				}
				else right--;
			}
			return area;
		}
};

int main(){
	vector<int> h{1,8,6,2,5,4,8,3,7};
	Solution t;
	cout<<t.maxArea(h);
	return 0;
}
