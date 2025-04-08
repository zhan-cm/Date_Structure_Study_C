/*
        ���ظ��ַ�����Ӵ�
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//����˼·
//������ָ��left��right��leftָ��ǰ�Ӵ�����߽磬rightָ��ǰ�Ӵ����ұ߽�
//�����ǰ�ַ�s[right]���ڵ�ǰ�Ӵ��У���right���ƣ�������max
//�����ǰ�ַ�s[right]�ڵ�ǰ�Ӵ��У���left���ƣ�ֱ��s[left]���ٵ���s[right]��Ȼ��right����
//ֱ��right�����ַ���ĩβ����ʱmax��Ϊ����ظ��Ӵ��ĳ���

int lengthOfLongestSubstring(char* s) {
    int left=0,right=0,max=0;
    int len = strlen(s);
    for(int i=0;i<len;i++){
        if(left<=right){
            for(int j=left;j<right;j++){
                if(s[j]==s[right]){
                    left=j+1;
                    break;
                }
            }
        }
        max=max<(right-left+1)?(right-left+1):max;
        right++;
    }
    
    return max;
}



int main(){
    char s[]="abcabcbb";
    printf("%d\n",lengthOfLongestSubstring(s));
    return 0;
}