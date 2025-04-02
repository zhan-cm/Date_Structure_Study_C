/*
        �Ƴ���Ч����
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

//˼·��
// 1. �����ַ�����������������ջ�����������ų�ջ�����ջΪ�գ���˵����Ч����
// 2. �����ַ�����������������ջ�����������ų�ջ�����ջ��Ϊ�գ���˵����Ч����
// 3. �����ַ�����������Ч���ţ���������������Ч���ţ����滻Ϊ�ո�  
// 4. ��󷵻��ַ���

char *minRemoveToMakeValid(char * s)
{
    int stack_left = 0;
    int stack_right = 0;
    int right_count = 0;
    int s_len = 0;
    int size = 0;
    char *str = s;

    while (*str != '\0') {
        right_count += (*str == ')');
        s_len++;
        str++;
    }

    for (int i = 0; i < s_len; i++) {
		if (s[i] == '(') {
			if (stack_left + 1 > stack_right + right_count) {
                continue;
            }
            stack_left++;
        } else if (s[i] == ')') {
            right_count--;
            if (stack_left <= stack_right) {
                continue;
            } 
            stack_right++;
        }
        s[size++] = s[i];
    }
    s[size] = '\0';
    return s;
}



int main()
{
    char s[] = "())()((()";
    char *result = minRemoveToMakeValid(s);
    printf("%s\n", result);
    return 0;
}