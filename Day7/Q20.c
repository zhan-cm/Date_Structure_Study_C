/*
        BF�㷨
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//BF�㷨
//pΪ������qΪģʽ��
//BF(p,q)
//BF�㷨�Ļ���˼���ǣ�����������ʼλ�ÿ�ʼ�������ģʽ����ÿ���ַ�����ƥ�䣬���ƥ��ɹ��������ƥ����һ���ַ���ֱ��ģʽ����ĩβ�����ƥ��ʧ�ܣ�����������һ��λ�ÿ�ʼ����ƥ�䡣
//BF�㷨��ʱ�临�Ӷ�ΪO(nm)��nΪ�����ĳ��ȣ�mΪģʽ���ĳ��ȡ�

void BF(char* p,char* q){
	int plen=strlen(p);
	int qlen=strlen(q);
	if(qlen>plen){
		printf("������ַ�����������,����������");
		return;
	}

	for(int i=0;i<plen-qlen;i++){
		int k=i;
		int count=0;
		for(int j=0;j<qlen;j++){ 
			if(*(q+j)==p[k++]){
				count++;
			}
			if(count==qlen){
				printf("ƥ��ɹ�");
				return; 

			}
		}
	}
} 
int main(){
	char* p="aabaabaaf";
	char* q="aabaaf";
	BF(p,q);
	return 0;
}