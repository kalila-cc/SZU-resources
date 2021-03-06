#include <iostream>
using namespace std;

struct Node {
	float coef;
	int expn;
};

class Poly {
	float item[10];
	int n;
	int size;
public:
	Poly() {
		n = 0; size = 10;
		for (int i = 0; i < size; i++) item[i] = 0;		
	}
	Poly(float* c, int* e,int n1) {
		size = 10;
		for (int i = 0; i < size; i++) item[i] = 0;
		n = n1;
		for (int i = 0; i < n; i++)
			item[e[i]] = c[i];
	}
	void display() {
		int flag = 1;
		for (int i = 0; i < size; i++)
			if (item[i] != 0) {
				if (flag) {
					cout << item[i] << "x^" << i;
					flag = 0;
				}
				else
					cout << "+" << item[i] << "x^" << i;
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