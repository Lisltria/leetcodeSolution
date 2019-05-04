#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution{
	public:
		int threeSumClosest(vector<int>&nums, int target){
			sort(nums.begin(),nums.end());
			int ans = INT_MAX;
			int res ;
			for(int i = 0; i < nums.size(); i++){
				int front = i + 1;
				int back = nums.size() - 1;
				int d;
				while(front < back){
					d = nums[front] + nums[back] + nums[i] - target;
					if(d>0&&d<ans){
						ans = d;
						res = nums[front] + nums[back] + nums[i]; 
					}
					else if(d<0&&(-d)<ans){
					   	ans = -d;
						res = nums[front] + nums[back] + nums[i];
					}	

					if(d>0) back--;
					else if(d<0)front++;
					else{
						return target;
					}
				}
			}
			return res;
		}
};

int main(){
	Solution t;
	vector<int> a{-1,2,1,-4};
	cout<<t.threeSumClosest(a,1);
	return 0;
}
