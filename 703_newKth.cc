#include <iostream>
#include <vector>

using namespace std;

class KthLargest{
	int kth;
	vector<int> heap;
	
public:
	KthLargest(int k, vector<int>& nums){
		//build heap
		kth = k;
		for(auto it = nums.begin(); it != nums.end(); it++){
			insetheap(*it);

		}
	}
	void insetheap(int val){
		heap.push_back(val);
		int last = heap.size() - 1;
		int n = heap.size();
		while(last > 0){
			int root = (last - 1) / 2;
			int tmp = heap[root];
			int flag = -1;
			if(root * 2 + 1 < n && tmp > heap[root * 2 + 1]){
				tmp = heap[root * 2 + 1];
				flag = root * 2 + 1;
			}
			if(root * 2 + 2 < n && tmp > heap[root * 2 + 2]){
				tmp = heap[root * 2 + 2];
				flag = root * 2 + 2;
			}
			if(flag != -1){
				heap[flag] = heap[root];
				heap[root] =tmp;
				last = root;
			}
			else break;
		}
		if( n > kth){
			swap(heap[0],heap[heap.size()-1]);
			int i =0;
			while(i < kth ){
				int tmp = heap[i];
				int next = -1;
				if( i * 2 + 1 < kth && tmp > heap[i * 2 + 1]){
					tmp = heap[i *2 + 1];
					next = i * 2 + 1;
				}
				if( i * 2 + 2 < kth && tmp > heap[i * 2 + 2]){
					tmp = heap[i *2 + 2];
					next = i * 2 + 2;
				}	
				if( next != -1){
					heap[next] = heap[i];
					heap[i] = tmp;
					i = next;
				}
				else break;

			}
			heap.erase(heap.end()-1);
		}

	}

	int add(int val){
		insetheap(val);	
		//for(auto it = heap.begin(); it != heap.end(); it++){
		//	cout<< *it <<endl;
		//}
		return heap[0];
	}
};


int main(){
	vector<int> nums{4,5,8,2};
	KthLargest t(3,nums);
	cout<<t.add(3)<<endl;
	cout<<t.add(5)<<endl;
	cout<<t.add(10)<<endl;
	cout<<t.add(9)<<endl;
	cout<<t.add(4)<<endl;

	return 0;
}
