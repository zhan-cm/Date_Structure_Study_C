/*
        ����Ԫ��
        ����һ����СΪ n ������ nums ���������еĶ���Ԫ�ء�
        ����Ԫ����ָ�������г��ִ��� ���� ? n/2 ? ��Ԫ�ء�
*/

#include <stdio.h>
#include <stdlib.h>

//����˼·
// 1. ������һ��flag��������ʼֵΪ����ĵ�һ��Ԫ��
// 2. �������飬�����ǰԪ����flag��ͬ����flagnum��1������flagnum��1
// 3. ���flagnumΪ0����flag����Ϊ��ǰԪ�أ�flagnum��1
// 4. ������ɺ�flag��Ϊ����Ԫ��

int majorityElement(int* nums, int numsSize) {
    int flag=nums[0];
    int flagnum=0;
    int i =0;
    while(i<numsSize){
        if(nums[i]==flag){
            flagnum++;
            i++;
        }else{
            if(flagnum==0){
                flag=nums[i];
                flagnum++;
                i++;
            }else{
                flagnum--;
                i++;
            }
        }
    }
    return flag;
}



//���Դ���
int main() {
    int nums[] = {3, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = majorityElement(nums, numsSize);
    printf("The majority element is: %d\n", result);    
    return 0;
}