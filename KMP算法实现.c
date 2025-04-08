
//花了好久才学会，woc


#include<stdlib.h>
#include<string.h>
#include<stdio.h>
void GetNext(char* p,int* next){
    int j=-1;
    next[0]=-1;// 初始值设为-1，方便处理
    for(int i=1;p[i]!='\0';i++){
        while(j>=0 && p[i]!=p[j+1]){
            j=next[j];//回退
        }
        if(p[i]==p[j+1]){
            j++;//相同字符，往后移进行匹配
        }
        next[i]=j;
    }
}
int KMP(char* text,char* pattern){
    int n = strlen(text);
    int m = strlen(pattern);
    int next[m+1];
    GetNext(pattern,next);
    int j=0;
    for(int i=0;i<n;i++){
        while(j>0&&text[i]!=pattern[j])
            j=next[j];
        if(text[i]==pattern[j])
            j++;
        if(j==m){
            return i-m+1;
        }
    }
    return -1;
}



//test
int main() {
    const char *text = "ABABDABACDABABCABAB";
    const char *pattern = "ABABCABAB";
    
    int pos = kmpSearch(text, pattern);
    
    if (pos != -1) {
        printf("Pattern found at index: %d\n", pos);
        printf("Matched substring: %.*s\n", (int)strlen(pattern), text + pos);
    } else {
        printf("Pattern not found.\n");
    }
    
    return 0;
}