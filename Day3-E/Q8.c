/*
        �����м�ڵ�        
*/
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};




//����˼·��
// 1. ����ָ�룬��ָ��ÿ�ο���������ָ��ÿ�ο�һ��
// 2. ����ָ�뵽������β��ʱ����ָ��ָ��������м�ڵ�
// 3. ������ָ��
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}





//���Դ���
int main() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 5;
    head->next = NULL;
    struct ListNode* mid = middleNode(head);
    printf("%d\n", mid->val);
    return 0;
}