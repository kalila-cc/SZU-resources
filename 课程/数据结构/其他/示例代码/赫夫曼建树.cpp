#include <iostream>
using namespace std;

#define MAXCODELEN	15	// 每个字符编码的最大长度
struct HTNode {
	char c;			// 字符
	int  weight;		// 权值
	int  parent, lchild, rchild;//双亲、左右孩子指针
	char code[MAXCODELEN];	// 字符对应的Huffman编码
};	// 定义Huffman树的结点
class HuffmanTree {
	HTNode* HT;//根节点
	int num; //待编码字符数
public:
	HuffmanTree() { num = 0; HT = NULL; }
	HuffmanTree(char* c, int w[], int n) {
		num = n;	int i, m, s1, s2;	m = 2 * n - 1;
		HT = new HTNode[m + 1];
		for (i = 1; i <= n; ++i) { // 为Huffman树的叶子结点赋初值
			HT[i].c = c[i - 1];	HT[i].weight = w[i - 1];
			HT[i].parent = 0; // i结点为根结点	
			HT[i].lchild = HT[i].rchild = 0;
		}
		for (i = n + 1; i <= m; ++i) { // 为Huffman树的内部结点赋初值
			HT[i].c = ' ';		HT[i].weight = 0;
			HT[i].parent = HT[i].lchild = HT[i].rchild = 0;
		}
		for (i = n + 1; i <= m; ++i) {
			Select(i - 1, s1, s2); //从树集合中，找出根最小和次小的两棵树
			HT[s1].parent = i; HT[s2].parent = i; // 将最小的两棵树合并成一棵树
			HT[i].lchild = s1; HT[i].rchild = s2;
			HT[i].weight = HT[s1].weight + HT[s2].weight;
		}
	}
	void Select(int i, int& s1, int& s2) {
		int j;
		s1 = s2 = 0;
		for (j = 1; j <= i; j++) {
			if (HT[j].parent == 0) {
				if (s1 == 0) s1 = j;
				else if (s2 == 0) s2 = j;
				if (HT[j].weight < HT[s1].weight) { s2 = s1; s1 = j; }
				else if (HT[j].weight < HT[s2].weight&&s2 != 0) { s2 = j; }
			}
		}
	}
	~HuffmanTree() { if (HT) delete[] HT; }
	void InOrder() {
		InOrderTraverse(2 * num - 1);
	}
	void InOrderTraverse(int i) {
		if (i != 0) {
			InOrderTraverse(HT[i].lchild);
			cout << "("<<HT[i].weight<<") ";
			InOrderTraverse(HT[i].rchild);
		}
	}
	void HuffmanCoding() // 从叶子到根逆向求每个字符的编码
	{
		int  i, j, m, c, f, start;
	char cd[MAXCODELEN];			// 存放每个字符的编码序列
	m = MAXCODELEN;
	cd[m - 1] = '\0';				// 编码结束符
	for (i = 1; i <= num; i++) {	   // 对字符（叶子结点）逐个求Huffman编码
		start = m - 1;			// 编码结束符位置
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent) {
			if (HT[f].lchild == c) cd[--start] = '0';
			else                   cd[--start] = '1';
		} 			//从叶子到根逆向求每个字符的编码
		for (j = 0; j<m - start; j++) HT[i].code[j] = cd[start + j];
		HT[i].code[j] = '\0';	//将每个字符的Huffman编码存放起来
	}
}
	bool ShowHuffmanDecode(char *dString) {
		int root = 2 * num - 1, k = root;
		for (int i = 0; i<strlen(dString); i++) {
			if (HT[k].lchild == 0 && HT[k].rchild == 0) {
				cout << HT[k].c;	k = root;
			}
			if (dString[i] == '0') {
				if (HT[k].lchild == 0) return 0;
				k = HT[k].lchild;
			}
			else {
				if (HT[k].rchild == 0) return 0;
				k = HT[k].rchild;
			}
		}
		if ((HT[k].lchild == 0) && (HT[k].rchild == 0)) {
			cout << HT[k].c;
			cout << endl;
			return 1;
		}
		return 0;
	}

};

int main() {
	char a[9] = "abcdefgh";
	int w[8] = { 5,25,4,7,9,12,30,8 };
	HuffmanTree obj(a, w, 8);
	obj.InOrder();
	obj.HuffmanCoding();
	if (!obj.ShowHuffmanDecode("0010001")) cout << "error" << endl;
	return 0;
}

