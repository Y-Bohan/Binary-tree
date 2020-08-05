#include "Tree.h"
#include "iostream"
using namespace std;

Tree::Tree(int x)  
{
	root = new Node(x);  //堆中申请内存，创建一棵树并初始化根节点
	root->index = 0;  //根节点索引为0；
}

Node * Tree::searchTree(int node_index)  //搜索树，即从根节点开始搜索其子节点，直到找到该索引对应的节点
{
	return root->searchNode(node_index);   //从根节点开始搜索所有节点
}

bool Tree::insertTree(int index, int direction, Node* node)
{
	Node* temp= searchTree(index);  //在树上找到是在哪个节点上进行插入
	if (temp == NULL)
		return false;
	Node* new_node = new Node();  //申请内存
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
	Node* temp = searchTree(index);   //找到树上的哪个节点需要删除
	if (temp == NULL)
		return false;
	node->data = temp->data;   //将要删除的节点的数据传出
	temp->deleteNode();   //调用节点类的删除函数
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

void Tree::inorderTree()   //树的中序遍历
{
	if (flag == 0)
	{
		cout << "The tree is delete" << endl;
		return;
	}
	root->inorder();
}

void Tree::postorderTree()   //树的后序遍历
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
	if (this->index == node_index)   //判断节点是否是搜索的那个节点
		return this;

	if (this->l_child != NULL)    //左子节点不为空，则对左子节点进行递归搜索
	{
		Node* temp = this->l_child->searchNode(node_index);
		if (temp != NULL)
			return temp;
	}

	if (this->r_child != NULL)    //右子节点不为空，则对右子节点进行递归搜索
	{
		Node* temp = this->r_child->searchNode(node_index);
		if (temp != NULL)
			return temp;
	}
	return NULL;   //都没有搜索到，则返回NULL
}

void Node::deleteNode()   //删除节点不仅删除自己节点，还要将自己的所有子节点删除
{
	if (this->l_child != NULL)  //左子节点不为空，则对左子节点进行递归删除
	{
		this->l_child->deleteNode();
	}

	if (this->r_child != NULL)  //右子节点不为空，则对右子节点进行递归删除
	{
		this->r_child->deleteNode();
	}

	if (this->parent != NULL)
	{
		if (this->parent->l_child == this)   //现在删除本身，即将自己父节点的对应子节点指向空
		{
			this->parent->l_child = NULL;
		}

		if (this->parent->r_child == this)   //现在删除本身，即将自己父节点的对应子节点指向空
		{
			this->parent->r_child = NULL;
		}
	}
	delete this;   //释放自身节点的内存空间
}

void Node::preorder()
{
	cout << this->index << ":" << this->data << endl;  //输出自身节点数据
	if (this->l_child != NULL)    //对左子节点进行递归前序遍历
	{
		this->l_child->preorder();
	}

	if (this->r_child != NULL)   //对右子节点进行递归前序遍历
	{
		this->r_child->preorder();
	}
}

void Node::inorder()
{
	if (this->l_child != NULL)    //对左子节点进行递归中序遍历
	{
		this->l_child->inorder();
	}

	cout << this->index << ":" << this->data << endl;  //输出自身节点数据

	if (this->r_child != NULL)   //对右子节点进行递归前序遍历
	{
		this->r_child->inorder();
	}
}

void Node::postorder()
{
	if (this->l_child != NULL)    //对左子节点进行递归中序遍历
	{
		this->l_child->postorder();
	}

	if (this->r_child != NULL)   //对右子节点进行递归前序遍历
	{
		this->r_child->postorder();
	}

	cout << this->index << ":" << this->data << endl;  //输出自身节点数据
}