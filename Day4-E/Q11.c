/*
    쳲��������еݹ�ʵ��
*/
#include <stdio.h>


//����˼·
//������洢쳲���������
//��ѭ������쳲���������
//���������е�n��Ԫ��   

int fib(int n) {
    if(n==0){return 0;}
    else if(n==1){return 1;}
    int a[n+1];
    int i=2;
    a[0]=0,a[1]=1;
    while(i<=n){
        a[i]=a[i-1]+a[i-2];
        i++;
    }
    return a[n];
}

//���Դ���
int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("Fibonacci series: ");
    for(int i=0;i<n;i++){
        printf("%d ",fib(i));
    }
    return 0;
}