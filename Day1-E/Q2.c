/*
        ɾ�����������е��ظ�Ԫ��
*/
#include<stdio.h>
#include<stdlib.h>
struct ListNode{
    int val;
    struct ListNode* next;
};

//����˼·��
//1. ������������ǰ�ڵ��ֵ����һ���ڵ��ֵ���бȽϣ������ͬ����ɾ����һ���ڵ�
//2. �ظ�����1��ֱ������ĩβ
//3. ����ͷ�ڵ�
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head||!head->next)return head;
    struct ListNode* p = head ;
    while(p->next){
        if(p->val==p->next->val){
            struct ListNode* q = p->next;
            p->next=q->next;
            free(q);
        }else{
            p=p->next;
        }
        
    }
    return head;
}

//���Դ���
int main(){
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));    
    head->next->next->val = 3;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 4;
    head->next->next = NULL;
    head = deleteDuplicates(head);
    while(head){
        printf("%d ",head->val);
        head = head->next;
    }
    return 0;
}
