#include <iostream>
using namespace std;

template <class T>
struct LNode {
	T data;
	LNode<T>* next;
};

template <class T>
class Linklist {
private:
	LNode<T>* head;
public:
	LNode<T>* getHead() { return head; }
	Linklist() {
		head = new LNode<T>;
		head->next = NULL;
	}
	Linklist(T* r, int n) {
		head = new LNode<T>;		head->next = NULL;
		int	   j;
	    for (j = 1; j <= n; j++)	insertItem(j, r[j - 1]);
	}
	~Linklist() {
		LNode<T> *p = head->next, *q;
		while (p) { q = p; p = p->next; delete q; }
		delete head;
	}
	LNode<T>* getItem(int i) {
		int    j;
		LNode<T> *p;
		p = head;  j = 0;				// p指向第一个结点
		while (p && j < i) { p = p->next; j++; }	// 顺指针查找
		if (!p || j>i) return(NULL);			// 第i元素不存在
		return(p);
	}
	LNode<T>* search(T key) {
		LNode<T> *p = head->next;
		while (p != NULL&& p->data != key)    p = p->next;
		if (p&&p->data == key)   return p;
		else
			return(NULL);
	}
	bool Traverse()
	{
		LNode<T> *p;
		p = head->next;      /*  使p指向第一个结点  */
		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
		return  0;

	}
	bool insertItem(int i, T e) {
		// 在带头结点的单链表L中第i个位置之前插入元素e
		LNode<T> *p = head, *s;
		int j = 0;
		while (p && j<i - 1) { p = p->next; j++; }		// 寻找i-1结点
		if (!p || j>i - 1) return false;
		s = new LNode<T>;		// 生成新结点
		s->data = e; s->next = p->next; p->next = s;	// 插入L中
		return true;
	}
	bool deleteItem(T e) {
		LNode<T> *p = head->next, *q=NULL;
		while (p != NULL&& p->data != e) { q = p; p = p->next; }
		if (!p) return(false);
		q->next = p->next; 	// 删除i结点
		delete p;				// 取值并释放结点
		return(true);

	}
};

template<class T>
void MergeList(Linklist<T>& La, Linklist<T>& Lb) {
	Linklist<T>* Lc = La.getHead(), *p = La.getHead()->next, *q = Lb.getHead()->next;

		while (p!=NULL&&q!=NULL) {
			if (p->data <= q->data) Lc->next = p;
			else Lc->next = q;
			Lc = Lc->next;
		}
		if (p != NULL) Lc->next = p;
		if (q != NULL) Lc->next = q;
		Lb.getHead()->next = NULL;
		delete Lb->getHead();
} // MergeList_L



int main() {
	int a[]={1,2,3,4,5};
	Linklist<int> list(a,5);
	list.Traverse();


	Linklist<int> list1, list2;
	for (int i = 1; i <= 5; i++)
		list1.insertItem(i, i * 10);
	if (!list1.insertItem(1,0)) cout << "error" << endl;
	else list1.Traverse();
	if (!list1.deleteItem(10)) cout << "error" << endl;
	else list1.Traverse();

	return 0;


}
