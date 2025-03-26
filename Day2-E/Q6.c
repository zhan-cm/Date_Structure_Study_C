/*
        ��ת����
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

//����˼·��
// 1. ��������ָ�룬�ֱ�ָ��ͷ��㣬��ǰ��㣬��һ�����
// 2. ������������ǰ����nextָ��ָ��ǰһ�����
// 3. �ƶ�ָ�룬ָ����һ�����
// 4. �ظ�����2��ֱ����������������
// 5. ����ͷ���
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* frist=NULL;
    struct ListNode* second = head;
    struct ListNode* third;
    while(second){
        third=second->next;
        second->next=frist;
        frist=second;
        second=third;
    }
    return frist;
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
    head->next = NULL;
    struct ListNode* newHead = reverseList(head);
    while(newHead) {
        printf("%d ", newHead->val);
        newHead = newHead->next;
    }
    return 0;