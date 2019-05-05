#include <iostream>
#include <vector>

using namespace std;

class KthLargest{
public:
	KthLargest(int k, vector<int>& nums){
		//build heap
		int n = nums.size();
		for(int it = n/2; it >= 0; it--){
			int i = it;
			while(i < n){
				int tmp = nums[i];
				int next = -1;
				if( i * 2 + 1 < n && tmp < nums[i * 2 + 1]){
					tmp = nums[i *2 + 1];
					next = i * 2 + 1;
				}
				if( i * 2 + 2 < n && tmp < nums[i * 2 + 2]){
					tmp = nums[i *2 + 2];
					next = i * 2 + 2;
				}	
				if( next != -1){
					nums[next] = nums[i];
					nums[i] = tmp;
					i = next;
				}
				else break;
			}
		}
	
	}

	int add(int val){
	}
};


int main(){
	vector<int> nums{4,5,8,2};
	
	return 0;
}
