// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

struct  TreeNode
{
	int val;
	struct  TreeNode * left;
	struct  TreeNode * right;

};

// ����ʼ���õĶ����������� 
// ����Ҫ���ɵ�����ͷ������
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
	ListNode* head2 = getMid(head);  //��ȡ�м�ڵ㣬�������Ϊ����
	head1 = merge_sort(head1);   //�ֱ�����������������
	head2 = merge_sort(head2);
	return merge(head1, head2);  //��������������ϲ�
}
ListNode* merge(ListNode* head1, ListNode* head2) //�ϲ�������������
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
	return newhead->next;  //����ͷ�ڵ�
}
ListNode* getMid(ListNode* head)  //��ȡ�м�ڵ㲢�ֶ�
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
	prev->next = NULL;  //�������Ϊ����
	return slow;
}
int main()
{
    return 0;
}

