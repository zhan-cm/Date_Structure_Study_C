/*
        ����������ת����
        ����һ������������ý�� head��������ÿ������ֵ���� 0 ���� 1��
        ��֪��������һ���������ֵĶ����Ʊ�ʾ��ʽ��
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct ListNode {
    int val;
    struct ListNode *next;
};





//����˼·
//1. ������������������len
//2. �����������ҵ�������ȡ��ÿ������ֵ������2��(len-1-i)�η������ۼӵ��������result��
//3. ���ؽ������result
int getDecimalValue(struct ListNode* head) {
    int len=0;
    struct ListNode* p = head;
    while(p){
        len++;
        p=p->next;
    }

    p=head;
    int result=0;

    for(int i=0;i<len;i++){
        result+=p->val*(int)pow(2,len-1-i);
        p=p->next;
    }
    return result;
}






//���Դ���
int main() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 0;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 1;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 0;
    head->next = NULL;

    int decimalValue = getDecimalValue(head);
    printf("%d\n", decimalValue);

    return 0;
}