/*
        �ϲ�������������
*/

#include<stdio.h>
#include<stdlib.h>
struct ListNode{
    int val;
    struct ListNode* next;
};

//����˼·��
//1.��������ָ��p��q��pָ��ϲ���������ͷ����qָ��һ���սڵ㡣
//2.�Ƚ����������ͷ���ڵ��ֵ������С�Ľڵ���ӵ��ϲ������У�����ָ��ָ��ýڵ㡣
//3.�ظ�����2��ֱ������������������һ���ڵ�Ϊ�ա�
//4.��ʣ��Ľڵ���ӵ��ϲ������С�
//5.���غϲ������ͷ�ڵ㡣
//6.�ͷ�q�ڵ㡣
//7.���غϲ������ͷ�ڵ㡣
//ʱ�临�Ӷȣ�O(n+m)��n��m�ֱ�Ϊ��������ĳ��ȡ�
//�ռ临�Ӷȣ�O(1)��ֻ��Ҫ�����Ķ���ռ䡣
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* q =(struct ListNode*)malloc(sizeof(struct ListNode));
    q->val=0;
    q->next=NULL;
    struct ListNode* p = q;
    while(list1&&list2){
        if(list1->val<=list2->val){
            p->next=list1;
            list1=list1->next;
        }else{
            p->next=list2;
            list2=list2->next;
        }
        p=p->next;
    }
    if(list1){
            p->next=list1;
        }else{
            p->next=list2;
        }
        struct ListNode* result = q->next;
        free(q);
        return result;
}


//���Դ���
int main(){
    struct ListNode* list1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->val=1;
    list1->next=NULL;
    struct ListNode* list2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list2->val=2;
    list2->next=NULL;
    struct ListNode* list3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list3->val=3;
    list3->next=NULL;
    struct ListNode* list4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list4->val=4;
    list4->next=NULL;
    struct ListNode* list5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list5->val=5;
    list5->next=NULL;
    struct ListNode* list6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list6->val=6;
    list6->next=NULL;
    list1->next=list2;
    list2->next=list3;
    list3->next=list4;
    list4->next=list5;
    list5->next=list6;
    struct ListNode* result = mergeTwoLists(list1,list5);
    while(result){
        printf("%d ",result->val);
        result=result->next;
    }
    return 0;
}



