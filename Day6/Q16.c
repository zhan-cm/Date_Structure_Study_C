/*
        �沨�����ʽ��ֵ
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize);

int main() {
    char* tokens[] = {"2", "1", "+", "3", "*"};
    int tokensSize = sizeof(tokens)/sizeof(tokens[0]);
    int result = evalRPN(tokens, tokensSize);
    printf("%d\n", result);
    return 0;
}

//˼·
// 1. ����tokens���飬���token�����֣���ѹջ�����token����������򵯳�ջ������Ԫ�أ��������㣬�������ѹջ
// 2. ���ջ��Ԫ�ؼ�Ϊ�����
int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize],top=-1;
    for(int i=0;i<tokensSize;i++){
        char* s = tokens[i];
        if(strlen(s)==1&&(s[0]<'0'||s[0]>'9')){
            int a = stack[top--];
            int b = stack[top--];
            switch(s[0]){
                case '+' : stack[++top]=b+a; break;
                case '-' : stack[++top]=b-a; break;
                case '*' : stack[++top]=b*a; break;
                case '/' : stack[++top]=b/a; break;
                default: break; // error-handling
            }
        }else{
            stack[++top]=atoi(s);
        }
    }    
    return stack[top];
}