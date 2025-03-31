/*
        �����е�ʵ��
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QNode{
    int data;
    struct QNode *next;
}QNode;

typedef struct{
    QNode *front;
    QNode *rear;
}ListQueue;


// ��ʼ������
void InitQueue(ListQueue *q){
    q->front = q->rear = (QNode*)malloc(sizeof(QNode));
    q->front->next = NULL;
}

//��Ӳ���
void EnQueue(ListQueue* q,int data){
    QNode *p = (QNode*)malloc(sizeof(QNode));
    p->data=data;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
}

// ���Ӳ���
int DeQueue(ListQueue* q){
    if(q->front==q->rear)
        return -1;
    QNode *p=q->front->next;
    int data=p->data;
    q->front->next=p->next;
    if(q->rear==p)
        q->rear=q->front;
    free(p);
    return data;
}

// �����пղ���
int QueueEmpty(ListQueue* q){
    return (q->front==q->rear);
}

// ������������
int QueueFull(ListQueue* q){
    return (q->rear->next!=NULL);
}

// ��ӡ����
void PrintQueue(ListQueue* q){
    QNode *p=q->front->next;
    printf("Queue: ");
    while(p!=NULL){
        printf("%d\n ",p->data);
        p=p->next;
    }
    printf("\n");   
}
// ���ٶ���
void DestroyQueue(ListQueue* q){
    QNode *p=q->front->next;
    while(p!=NULL){
        QNode *q=p;
        p=p->next;
        free(q);
    }
    free(q->front);
}   
// ���Զ���
int main(){
    ListQueue q;
    InitQueue(&q);
    EnQueue(&q,1);
    EnQueue(&q,2);
    EnQueue(&q,3);
    EnQueue(&q,4);
    EnQueue(&q,5);
    PrintQueue(&q);
    DeQueue(&q);
    DeQueue(&q);    
    PrintQueue(&q);
    DestroyQueue(&q);
    return 0;
}

