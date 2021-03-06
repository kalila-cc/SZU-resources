#include <iostream>
using namespace std;
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

template <class T>
class Sqlist {
private:
	T* elem;
	int length;
	int listsize;
public:
	Sqlist() {
		elem = new T[LIST_INIT_SIZE];
		if (!elem) exit(-1);
		length = 0;
		listsize = LIST_INIT_SIZE;
	}
	~Sqlist() {
		if (elem) delete elem;
	}
	int getLength() {
		return length;
	}
	T getItem(int i) {
		if (i>length || i<1) exit(-1);
		else return elem[i - 1];
	}
	bool Insert(int i, T e) {
		if (i<1 || i>length + 1) return false;
		if (length >= listsize) {
			T* newbase = new T[listsize + LISTINCREMENT];
			if (!newbase) exit(OVERFLOW);
			for (int j = 0; j<length; j++) newbase[j] = elem[j];
			delete [] elem;
			elem = newbase;
			listsize += LISTINCREMENT;
		}	                                // 以上皆为准备阶段
		T* q = &(elem[i - 1]);			// 找到插入位置
		for (T* p = &(elem[length - 1]); p >= q; --p)
			*(p + 1) = *p;	              // 右移
		*q = e;
		++length;
		return true;
	} // ListInsert_Sq
	bool Delete(int i) {
		if (i<1 || i>length) return false;
		T* p = &(elem[i - 1]);	// 找到要删除的元素位置
		T* q = elem + length - 1;	// 找到最后一个元素位置
		for (++p; p <= q; ++p)
			*(p - 1) = *p;	// 左移
		--length;		// 表长减1
		return true;
	} // ListDelete_Sq
	bool isEmpty() {
		if (length == 0) return true;
		else return false;
	}
	int locateItem(T x) {
		for (int i = 0; i<length; i++)
			if (elem[i] == x) return i + 1;
		return -1;
	}
	void Traverse() {
		cout << "共有" << length << "个元素。" << endl;
		for (int i = 0; i<length; i++)
			cout << "第" << i + 1 << "个元素是：" << elem[i] << endl;
	}
	T* getElem() { return elem; }
	void setLength(int i) { length = i; }
};

template<class T>
void MergeList(Sqlist<T>& la, Sqlist<T>& lb, Sqlist<T>& lc) {
	T *pa = la.getElem(), *pb = lb.getElem(), *pc = lc.getElem();
	lc.setLength(la.getLength() + lb.getLength());
	while (pa <= la.getElem() + la.getLength() - 1 && pb <= lb.getElem() + lb.getLength() - 1) {
		if (*pa <= *pb) { *pc++ = *pa++; }
		else { *pc++ = *pb++; }
	}
	while (pa <= la.getElem() + la.getLength() - 1) *pc++ = *pa++;
	while (pb <= lb.getElem() + lb.getLength() - 1) *pc++ = *pb++;
}
/*template<class T>
void MergeList(Sqlist<T>& la,Sqlist<T>& lb,Sqlist<T>& lc){
int i=0,j=0,k=1;
while(i<la.getLength()&&j<lb.getLength()){
if(la.getItem(i+1)<=lb.getItem(j+1)) {lc.Insert(k++,la.getItem(i+1));i++;}
else {lc.Insert(k++,lb.getItem(j+1));j++;}
}
while(i<la.getLength()) lc.Insert(k++,la.getItem(++i));
while(j<lb.getLength()) lc.Insert(k++,lb.getItem(++j));
}*/

void main() {
	Sqlist<int> list1, list2, list3;
	for (int i = 1; i <= 5; i++)
		list1.Insert(i, i * 10);
	for (int j = 1; j <= 5; j++)
		list2.Insert(j, j * 3);
	list1.Traverse();
	list2.Traverse();
	MergeList(list1, list2, list3);
	list3.Traverse();
}
