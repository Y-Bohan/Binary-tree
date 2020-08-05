// 二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "Tree.h"
#include <iostream>
using namespace std;
int main()
{
    Tree my_tree(5);
    Node node1(1);
    Node node2(2);
    Node node3(3);
    Node node4(4);
    Node node5(5);
    Node node6(6);
    Node node7(7);
    Node node8(8);
    Node node9(9);

    my_tree.insertTree(0, 0, &node1);  //  向根节点插入左子节点
    my_tree.insertTree(0, 1, &node2);  //  向根节点插入右子节点
    my_tree.insertTree(1, 0, &node7);  //  向1节点插入左子节点
    my_tree.insertTree(1, 1, &node3);  //  向1节点插入右子节点
    my_tree.insertTree(2, 1, &node5);  //  向2节点插入右子节点
    my_tree.insertTree(4, 1, &node8);  //  向4节点插入右子节点
    my_tree.insertTree(3, 0, &node4);  //  向3节点插入左子节点
    my_tree.insertTree(6, 0, &node9);  //  向6节点插入左子节点
    my_tree.insertTree(6, 1, &node3);  //  向6节点插入右子节点

    my_tree.preorderTree();  //前序遍历输出：5，1，7，4，3，8，2，5，9，3
    cout << endl;
    my_tree.inorderTree();  //中序遍历输出：4，7，1，3，8，5，3，2，9，5，3
    cout << endl;
    my_tree.postorderTree();  //后序遍历输出：4，7，8，3，1，9，3，5，2，5
    cout << endl;

    Node temp;
    my_tree.deleteTree(2, &temp);
    my_tree.preorderTree();  //删除节点后前序遍历输出5，1，7，4，3，8，
    cout << endl;

    my_tree.deleteTree(0, &temp);  
    my_tree.preorderTree();  //删除根节点后遍历提示树已经被删除
    my_tree.inorderTree();  
    my_tree.postorderTree();  
    return 0;
}

