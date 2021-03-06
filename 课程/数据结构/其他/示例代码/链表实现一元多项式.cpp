#include <iostream>
using namespace std;

struct Node {
	float coef;
	int expn;
	Node* next;
};

class Poly {
	Node* head;
public:
	Poly() {
		head = new Node;
		head->next = NULL;
	}
	Poly(float* c, int* e,int n) {
		head = new Node;
		head->next = NULL;
		for (int i = 0; i < n; i++)
		{
			insertItem(c[i], e[i], i);
		}
	}
	int insertItem(float c, int e, int i) {
		int j = 0; Node* p = head;
		while (p->next&&j<=i) { p = p->next; j++; }
		if (!p || j > i) return -1;
		Node* s = new Node;
		s->coef = c; s->expn = e; s->next = p->next; p->next = s;
		return i;
	}
	void display() {
		Node* p = head->next; int flag = 1;
		while(p){
			if(flag){
				cout << p->coef << "x^" << p->expn;
				flag = 0;
			}				
			else
				cout << "+" << p->coef << "x^" << p->expn;
			p = p->next;
		}
		cout << endl;
	}
};

int main() {
	float c[3] = { 2.3,4,5 };
	int e[3] = { 0,3,5 };
	Poly test(c, e, 3);
	test.display();
	return 0;
}