/*
            ��������

            ����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���
            �����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� 
            Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����ע�⣺pos ����Ϊ�������д��� ��������Ϊ�˱�ʶ�����ʵ�������
            ��������д��ڻ� ���򷵻� true �� ���򣬷��� false ��
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct ListNode{
    int val;
    struct ListNode* next;
};

//����˼·��
// 1. ����ָ�뷨����ָ��ÿ�ο���������ָ��ÿ�ο�һ����������ڻ������ָ���׷����ָ�룬���򲻴��ڻ���
// 2. ����ָ�뷨���Ż������������Ϊn�����ָ��ÿ�ο���������ָ��ÿ�ο�һ�������ָ����ڵ�n/2��׷����ָ�룬������ڻ������ָ����ڵ�n/2��׷����ָ�룬���򲻴��ڻ���
// 3. ��ϣ��������������ÿ���ڵ��ֵ��Ϊkey�����ڵ�ĵ�ַ��Ϊvalue����������ظ���key����˵�����ڻ���
// 4. ˫ָ�뷨������ָ�뷨���Ż������������Ϊn�����ָ��ÿ�ο���������ָ��ÿ�ο�һ�������ָ����ڵ�n/2��׷����ָ�룬������ڻ������ָ����ڵ�n/2��׷����ָ�룬���򲻴��ڻ���
// 5. ����ָ�뷨�ı��Σ����������Ϊn�����ָ��ÿ�ο���������ָ��ÿ�ο�һ�������ָ����ڵ�n/2��׷����ָ�룬������ڻ������ָ����ڵ�n/2��׷����ָ�룬���򲻴��ڻ���
bool hasCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}






//���Դ���
int main(){
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next = head->next;
    if(hasCycle(head)){
        printf("Cycle exists\n");
    }else{
        printf("Cycle does not exist\n");
    }
    return 0;