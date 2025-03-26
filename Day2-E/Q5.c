/*
        �Ƴ�����Ԫ��
        ����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


//����˼·
//����һ���ƽ�㣬��ԭ�����ͷ���ָ���ƽ�㣬Ȼ��������������ǰ����ֵ����val���򽫵�ǰ������һ�����ָ��ǰ�������¸���㣬���ͷŵ�ǰ�����ڴ棬���򽫵�ǰ���ָ����һ����㡣��󷵻��ƽ�����һ����㣬�������ͷ��㡣

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val=0;
    dummy->next=head;
    struct ListNode* p = dummy;
    while(p&&p->next){
        if(p->next->val==val){
            struct ListNode* temp = p->next;
            p->next=temp->next;
            free(temp);
        }else{
            p=p->next;
        }
    }
    return dummy->next;
}


//���Դ���
int main() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 6;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 4;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 5;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 6;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 7;
    head->next = NULL;
    struct ListNode* newHead = removeElements(head, 6);
    while (newHead) {
        printf("%d ", newHead->val);
        newHead = newHead->next;
    }
    return 0;
}