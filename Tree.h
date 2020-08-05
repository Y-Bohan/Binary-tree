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
	Node* searchNode(int node_index); //�����ڵ�
	void deleteNode();   //ɾ���ڵ�
	void preorder();  //ǰ�����
	void inorder();  //�������
	void postorder();  //�������
	int data;
	int index;
	Node* parent;    //���ڵ�
	Node* l_child;   //���ӽڵ�
	Node* r_child;   //���ӽڵ�
};

class Tree
{
public:
	Tree(int x);  //����һ����
	Tree() {}
	~Tree();  //����һ����
	Node* root;  //���ڵ�
	Node* searchTree(int node_index);  //������
	bool insertTree(int index, int direction, Node* node);  //�����в���ڵ�
	bool deleteTree(int index,Node* node);    //������ɾ���ڵ�
	void preorderTree();   //����ǰ�����
	void inorderTree();   //�����������
	void postorderTree();   //���ĺ������
	int flag = 1;   //�����ж����Ƿ���ڽڵ㣬ɾ�����ڵ�ʱflag=0;
};

#endif // !Tree_H

