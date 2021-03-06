#include <iostream>
using namespace std;

class BiNode{
public:	
	char		 data;
	BiNode  *lchild, *rchild;
	BiNode():lchild(NULL),rchild(NULL){}
};			

class BiTree{
	BiNode  *root;
	
public:

	BiTree(){
		
		root=CreateBiTree();
	}
	BiNode* CreateBiTree() {
		char ch;
		ch = getchar();
		BiNode* T;
		if (ch=='0')T = NULL;
		else {
			if (!(T = new BiNode))        exit(-1);
			T->data = ch;              // 生成根结点
			T->lchild=CreateBiTree();   // 构造左子树
			T->rchild=CreateBiTree();   // 构造右子树
		}
		return T;  
	} // CreateBiTree
	void PreOrderTraverse(BiNode* T) {
		if (T) {
			cout <<T->data;
			PreOrderTraverse (T->lchild );
			PreOrderTraverse (T-> rchild );
		}
	}
	void PreOrder() {
		PreOrderTraverse(root);
	}
};

int main(){
	BiTree bt;
	bt.PreOrder();
	return 0;
}

