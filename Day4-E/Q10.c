/*
        2����
*/
#include <stdio.h>
#include <stdbool.h>

//����˼·��
// 1. ���ж�n�Ƿ�С�ڵ���0�����С�ڵ���0���򷵻�false
// 2. ���n����1���򷵻�true
// 3. ���n���������򷵻�false
// 4. ���n��ż������ݹ����isPowerOfTwo(n/2)�����ж�n����2�����Ƿ�Ϊ2����
// 5. ���n����2������2���ݣ��򷵻�true�����򷵻�false
bool isPowerOfTwo(int n) {
    if(n<=0){
        return false;
    }else if(n==1){
        return true;
    }else if(n%2==1){
        return false;
    }else{
        return isPowerOfTwo(n/2);
    }
}



//���Դ���
int main() 
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    if(isPowerOfTwo(n)){
        printf("%d is a power of 2\n",n);
    }else{
        printf("%d is not a power of 2\n",n);
    }
    return 0;
}