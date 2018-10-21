// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct  TreeNode
{
	int val;
	struct  TreeNode * left;
	struct  TreeNode * right;

};

// 将初始化好的二叉树传进来 
// 将需要生成的链表头传进来
void tans(TreeNode * tn , TreeNode * head) 
{
	TreeNode* s[100];
	int top = -1;
	TreeNode * tmp = head;
	while (tn != NULL || top != -1)
	{
		while (tn!=NULL)
		{		
			tmp->left = tn;
			tmp = tn;
			s[++top] = tn;
			tn = tn->left;
		}
		if (top != -1)
		{
			tn = s[top--];
			tn = tn->right;
		}
	}

	tmp->left = NULL;
}

ListNode* merge_sort(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;

	ListNode* head1 = head;
	ListNode* head2 = getMid(head);  //获取中间节点，将链表分为两段
	head1 = merge_sort(head1);   //分别对两段链表进行排序
	head2 = merge_sort(head2);
	return merge(head1, head2);  //将两段有序链表合并
}
ListNode* merge(ListNode* head1, ListNode* head2) //合并两个有序链表
{
	ListNode* newhead = new ListNode(-1);
	ListNode* newtail = newhead;
	while (head1 && head2)
	{
		if (head1->val <= head2->val)
		{
			newtail->next = head1;
			head1 = head1->next;
		}
		else
		{
			newtail->next = head2;
			head2 = head2->next;
		}
		newtail = newtail->next;
		newtail->next = NULL;
	}
	if (head1)   newtail->next = head1;
	if (head2)   newtail->next = head2;
	return newhead->next;  //链表头节点
}
ListNode* getMid(ListNode* head)  //获取中间节点并分段
{
	ListNode* fast = head->next;
	ListNode* slow = head->next;
	ListNode* prev = head;
	while (true)
	{
		if (fast == NULL) break;
		fast = fast->next;
		if (fast == NULL)    break;
		fast = fast->next;

		prev = slow;
		slow = slow->next;
	}
	prev->next = NULL;  //将链表分为两段
	return slow;
}
int main()
{
    return 0;
}

