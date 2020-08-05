#include "Tree.h"
#include "iostream"
using namespace std;

Tree::Tree(int x)  
{
	root = new Node(x);  //���������ڴ棬����һ��������ʼ�����ڵ�
	root->index = 0;  //���ڵ�����Ϊ0��
}

Node * Tree::searchTree(int node_index)  //�����������Ӹ��ڵ㿪ʼ�������ӽڵ㣬ֱ���ҵ���������Ӧ�Ľڵ�
{
	return root->searchNode(node_index);   //�Ӹ��ڵ㿪ʼ�������нڵ�
}

bool Tree::insertTree(int index, int direction, Node* node)
{
	Node* temp= searchTree(index);  //�������ҵ������ĸ��ڵ��Ͻ��в���
	if (temp == NULL)
		return false;
	Node* new_node = new Node();  //�����ڴ�
	new_node->index = node->index;
	new_node->data = node->data;

	if (direction == 0)
	{
		temp->l_child = new_node;
		temp->l_child->index = temp->index * 2 + 1;
	}
	if (direction == 1)
	{
		temp->r_child = new_node;
		temp->r_child->index = temp->index * 2 + 2;
	}
	new_node->parent = temp;
	cout << "insertNode success" << endl;
	return true;
}

bool Tree::deleteTree(int index, Node* node)
{
	if (index == 0)
		this->flag = 0;
	Node* temp = searchTree(index);   //�ҵ����ϵ��ĸ��ڵ���Ҫɾ��
	if (temp == NULL)
		return false;
	node->data = temp->data;   //��Ҫɾ���Ľڵ�����ݴ���
	temp->deleteNode();   //���ýڵ����ɾ������
	return true;
}

Tree::~Tree()
{
	if (flag == 0)
	{
		return;
	}
	root->deleteNode();
}

void Tree::preorderTree()
{
	if (flag == 0)
	{
		cout << "The tree is delete" << endl;
		return;
	}
	root->preorder();
}

void Tree::inorderTree()   //�����������
{
	if (flag == 0)
	{
		cout << "The tree is delete" << endl;
		return;
	}
	root->inorder();
}

void Tree::postorderTree()   //���ĺ������
{
	if (flag == 0)
	{
		cout << "The tree is delete" << endl;
		return;
	}
	root->postorder();
}

Node::Node(int x)
{
	data = x;
	index = 0;
	parent = NULL;
	l_child = NULL;
	r_child = NULL;
}

Node* Node::searchNode(int node_index)
{
	if (this->index == node_index)   //�жϽڵ��Ƿ����������Ǹ��ڵ�
		return this;

	if (this->l_child != NULL)    //���ӽڵ㲻Ϊ�գ�������ӽڵ���еݹ�����
	{
		Node* temp = this->l_child->searchNode(node_index);
		if (temp != NULL)
			return temp;
	}

	if (this->r_child != NULL)    //���ӽڵ㲻Ϊ�գ�������ӽڵ���еݹ�����
	{
		Node* temp = this->r_child->searchNode(node_index);
		if (temp != NULL)
			return temp;
	}
	return NULL;   //��û�����������򷵻�NULL
}

void Node::deleteNode()   //ɾ���ڵ㲻��ɾ���Լ��ڵ㣬��Ҫ���Լ��������ӽڵ�ɾ��
{
	if (this->l_child != NULL)  //���ӽڵ㲻Ϊ�գ�������ӽڵ���еݹ�ɾ��
	{
		this->l_child->deleteNode();
	}

	if (this->r_child != NULL)  //���ӽڵ㲻Ϊ�գ�������ӽڵ���еݹ�ɾ��
	{
		this->r_child->deleteNode();
	}

	if (this->parent != NULL)
	{
		if (this->parent->l_child == this)   //����ɾ�����������Լ����ڵ�Ķ�Ӧ�ӽڵ�ָ���
		{
			this->parent->l_child = NULL;
		}

		if (this->parent->r_child == this)   //����ɾ�����������Լ����ڵ�Ķ�Ӧ�ӽڵ�ָ���
		{
			this->parent->r_child = NULL;
		}
	}
	delete this;   //�ͷ�����ڵ���ڴ�ռ�
}

void Node::preorder()
{
	cout << this->index << ":" << this->data << endl;  //�������ڵ�����
	if (this->l_child != NULL)    //�����ӽڵ���еݹ�ǰ�����
	{
		this->l_child->preorder();
	}

	if (this->r_child != NULL)   //�����ӽڵ���еݹ�ǰ�����
	{
		this->r_child->preorder();
	}
}

void Node::inorder()
{
	if (this->l_child != NULL)    //�����ӽڵ���еݹ��������
	{
		this->l_child->inorder();
	}

	cout << this->index << ":" << this->data << endl;  //�������ڵ�����

	if (this->r_child != NULL)   //�����ӽڵ���еݹ�ǰ�����
	{
		this->r_child->inorder();
	}
}

void Node::postorder()
{
	if (this->l_child != NULL)    //�����ӽڵ���еݹ��������
	{
		this->l_child->postorder();
	}

	if (this->r_child != NULL)   //�����ӽڵ���еݹ�ǰ�����
	{
		this->r_child->postorder();
	}

	cout << this->index << ":" << this->data << endl;  //�������ڵ�����
}