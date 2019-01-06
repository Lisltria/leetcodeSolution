#include <iostream>
#include <vector>
using namespace std;
vector<int> abc;
class Solution{
public:
	double findMedianSortedArrays
		(vector<int>& nums1, vector<int>& nums2) {
		int m=nums1.size();
		int n=nums2.size();
		vector<int> *n1;
		vector<int> *n2;
		if ( m>n )
		{
			n1=&nums2;
			n2=&nums1;
		}	
		else
		{
			n1=&nums1;
			n2=&nums2;
		}
		m=n1->size();
		n=n2->size();
				
		int ileft=0,iright=m,halg=(m+n+1)/2;
		while(ileft<=iright){
			int i=(ileft+iright)/2;
			int j=halg-i;
			if(i<iright && (*n2)[j-1] > (*n1)[i] ){
				ileft=i+1;
			}
			else if(i>ileft && (*n1)[i-1] > (*n2)[j]){
				iright=i-1;
			}
			else{
				int maxLeft=0;
				if (i==0){
					maxLeft=(*n2)[j-1];
				}
				else if (j==0){
					maxLeft=(*n1)[i-1];
				}
				else {
					maxLeft=(*n1)[i-1]>(*n2)[j-1] ? (*n1)[i-1]:(*n2)[j-1];
				}
				if((m+n)%2==1){
					return maxLeft;
				}

				int minRight=0;
				if(i==m){minRight=(*n2)[j];}
				else if(j==n){minRight=(*n1)[i];}
				else minRight=(*n1)[i] < (*n2)[j] ? (*n1)[i]:(*n2)[j];

				return (maxLeft+minRight)/2.0;
			}
		}

		return 0.0;
    }
};

int main()
{
	
	Solution temp;
	vector<int>nn1={1,2,3,5};
	vector<int>nn2={4,5,6,7,8};
	cout<<temp.findMedianSortedArrays(nn1,nn2)<<endl;
	return 0;
}
