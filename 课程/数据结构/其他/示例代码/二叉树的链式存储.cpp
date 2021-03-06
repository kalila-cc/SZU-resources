#include <iostream>
using namespace std;

struct BiNode {
	char data;
	BiNode  *lchild, *rchild;
};

class BiTree {
	BiNode  *root;
	//根节点
public:
	BiTree() { root = NULL; }
	BiTree(char *c, int n) { root = CreatTree(c, 1, n); }
	BiNode* CreatTree(char *c, int i, int n) {
		if (i > n) return NULL;		// i表示结点在c[]中的序号
		if (c[i - 1] == '0') return NULL;	// ‘0’表示空结点
		BiNode* p;
		p = new BiNode;			// 申请新结点
		p->data = c[i - 1];
		p->lchild = CreatTree(c, 2 * i, n);
		p->rchild = CreatTree(c, 2 * i + 1, n);
		return p;
	}
	void PreOrder() {
		PreOrderTraverse(root);
	}
	void PreOrderTraverse(BiNode* p) {
		if (p) {
			cout << p->data;
			PreOrderTraverse(p->lchild);
			PreOrderTraverse(p->rchild);
		}
	}
};

int main() {
	char c[100];
	cin >> c;
	BiTree t1(c, 10);
	t1.PreOrder();
	return 0;
}