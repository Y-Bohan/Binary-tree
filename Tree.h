#ifndef Tree_H
#define Tree_H
#include "iostream"
using namespace std;
class Node
{
public:
	Node() {}
	Node(int x);
	~Node() {}
	Node* searchNode(int node_index); //搜索节点
	void deleteNode();   //删除节点
	void preorder();  //前序遍历
	void inorder();  //中序遍历
	void postorder();  //后序遍历
	int data;
	int index;
	Node* parent;    //父节点
	Node* l_child;   //左子节点
	Node* r_child;   //右子节点
};

class Tree
{
public:
	Tree(int x);  //创建一棵树
	Tree() {}
	~Tree();  //销毁一棵树
	Node* root;  //根节点
	Node* searchTree(int node_index);  //搜索树
	bool insertTree(int index, int direction, Node* node);  //向树中插入节点
	bool deleteTree(int index,Node* node);    //在树中删除节点
	void preorderTree();   //树的前序遍历
	void inorderTree();   //树的中序遍历
	void postorderTree();   //树的后序遍历
	int flag = 1;   //用于判断树是否存在节点，删除根节点时flag=0;
};

#endif // !Tree_H

