/*
        ������⣺
        ����һ����飬��Ů��һ�룬Ҫ��˳����������ж��ȳ���Ů�Ӻ����
        ���룺
        ��һ�У�һ������n����ʾ����������
        ������n�У�ÿ��һ���ַ�������ʾһ���������ֺ��Ա��ÿո������
        �����
        ��˳������������ֺ��Ա��ж��ȳ���Ů�Ӻ����    
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAXQSIZE 100
typedef struct
{
    char name[20];
    char sex;//F or M   
}Person;
typedef struct
{
    Person *base;
    int front,rear;
}SqQueue;
SqQueue Mdancers,Fdancers;//Male and Female dancers
void InitQueue(SqQueue *q){
    q->base=(Person*)malloc(MAXQSIZE*sizeof(Person));
    if(q->base==NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }
    q->front=q->rear=0;
}
void DancePartner(Person dancer[],int num){
    InitQueue(&Mdancers);
    InitQueue(&Fdancers);
    for(int i=0;i<num;i++){
        if(dancer[i].sex=='M'){
            Enqueue(&Mdancers,dancer[i]);
        }else{
            Enqueue(&Fdancers,dancer[i]);
        }
    }
    printf("The dance partners are:\n");
    //�����ж���Ϊ�գ�����ѭ�������ν��������Ů����Ķ�Ա
    while(!isEmpty(&Mdancers)&&!isEmpty(&Fdancers)){
        Person p1,p2;
        Dequeue(&Mdancers,&p1);
        printf("%s(%c)\n",p1.name,p1.sex);
        Dequeue(&Fdancers,&p2);
        printf("%s(%c)\n",p2.name,p2.sex);
    }
    //���жӶ���Ϊ�գ������Ů�Ӷ���
    while(!isEmpty(&Fdancers)){
        Person p;
        Dequeue(&Fdancers,&p);
        printf("%s(%c)\n",p.name,p.sex);
    }
    //��Ů�Ӷ���Ϊ�գ�������жӶ���
    while(!isEmpty(&Mdancers)){
        Person p;
        Dequeue(&Mdancers,&p);
        printf("%s(%c)\n",p.name,p.sex);
    }
}
//�ж϶����Ƿ�Ϊ��
bool isEmpty(SqQueue *q){
    return (q->front==q->rear);
}
void Enqueue(SqQueue *q,Person p){
    if(q->rear==MAXQSIZE-1)
    {
        printf("Queue is full");
        return;
    }
    q->base[q->rear++]=p;
}
//����
void Dequeue(SqQueue *q,Person *p){
    if(isEmpty(q))
    {
        printf("Queue is empty");
        return;
    }
    *p=q->base[q->front++];
}

int main(){
    Person dancer[100];
    int num;
    printf("Enter the number of dancers:");
    scanf("%d",&num);
    DancePartner(dancer,num);
    return 0;
}
