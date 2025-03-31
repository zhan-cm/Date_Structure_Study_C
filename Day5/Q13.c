/*
    ջ��ʵ��
*/
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
typedef struct{
    int stackSize;
    int* top;
    int* base;
}Stack;
void initStack(Stack* s){
    s->base=(int*)malloc(MAXSIZE*sizeof(int));
    if(!s->base){
        exit(0);
    }
    s->top=s->base;
    s->stackSize=MAXSIZE;
}
void push(Stack* s,int data){
    if(s->top-s->base==s->stackSize){
        printf("ջ��\n");
        return;
    }
    s->top++;
    *s->top=data;
}
void pop(Stack* s){
    if(s->top==s->base){
        printf("ջ��\n");
        return ;
    }
    printf("����Ԫ��:%d\n",*s->top);
    s->top--;
}

int main(){
    Stack s;
    initStack(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    return 0;
   
}