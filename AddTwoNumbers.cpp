#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		
		int num1,num2;
		ListNode *head=NULL,*last=NULL;
		addPoint = 0;
		while( l1!=NULL || l2!=NULL || addPoint!=0 ) {
			if( l1!=NULL) {
				num1=l1->val;
				l1=l1->next;
			}
			else num1 = 0;
			if( l2!=NULL ) {
				num2=l2->val;
				l2=l2->next;
			}
			else num2 = 0;
			ListNode *p=new ListNode( (num1 + num2 + addPoint)%10 );
			addPoint = (num1 + num2 + addPoint) / 10;
			if ( last==NULL ) {
				last=p;
			}
			else {
				last->next=p;
				last=last->next;
			}
			if ( head==NULL ) {
				head=last;
			}
		}
		return head;
	}
private:
	int addPoint;
};

int main(){
	Solution temp;
	ListNode *a1=new ListNode(2);     
	ListNode *a2=new ListNode(4);     
	ListNode *a3=new ListNode(3);     
	ListNode *b1=new ListNode(5);     
	ListNode *b2=new ListNode(6);     
	ListNode *b3=new ListNode(7);
	ListNode *b4=new ListNode(9);
	a1->next=a2;
	a2->next=a3;
	b1->next=b2;
	b2->next=b3;
	b3->next=b4;
	ListNode *out=temp.addTwoNumbers(a1, b1);
	
	while (out!=NULL) {
		cout<<out->val<<endl;
		out=out->next;
	}

	return 0;
}
