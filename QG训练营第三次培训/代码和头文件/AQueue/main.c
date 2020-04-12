#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<limits.h>
#include"../head/AQueue.h"

#define dataSize 17
#define stringSize 100
#define INTEGER 'i'
#define FLOAT 'f'
#define STRING 's'
extern char type;

AQueue queue;
int isInit=0;
void menu();
int isLegal(int*i);
void fun1();
void fun2();
void fun3();
void fun4();
void fun5();
void fun6();
void fun7();
void fun8();
void fun9();

int main(){
		while(1){
		menu();
		int a;
		fflush(stdin);
		char code=getch();
		switch(code){
			case '1':fun1();break;
			case '2':fun2();break;
			case '3':fun3();break;
			case '4':fun4();break;
			case '5':fun5();break;
			case '6':fun6();break;
			case '7':fun7();break;
			case '8':fun8();break;
			case '9':fun9();break;
		}
		system("pause");
		system("cls");
	} 
	return 0;	
}

void menu(){
	printf("\t\t==========================================\n");
	printf("\t\t==                ����ϵͳ              ==\n");
	printf("\t\t==========================================\n"); 
	printf("\t\t**********     1. ��ʼ������    **********\n");
	printf("\t\t**********     2. �Ƿ�ն�      **********\n");
	printf("\t\t**********     3. ���          **********\n");
	printf("\t\t**********     4. ����          **********\n");
	printf("\t\t**********     5. ���д�С      **********\n");
	printf("\t\t**********     6. ��ȡ��ͷԪ��  **********\n");
	printf("\t\t**********     7. ��������      **********\n");
	printf("\t\t**********     8. ��ն���      **********\n");
	printf("\t\t**********     9. ���ٶ���      **********\n");
	printf("\t\t==========================================\n");
}

void fun1(){
	if(isInit){
		printf("�ѳ�ʼ�������ظ���ʼ����������\n");
		return;
	}
	printf("��ѡ��ö��д洢����������: i .������   f.С����   s.�ַ�����\n");
	fflush(stdin);
	char code;
	code=getch(); 
	while(code!='i'&&code!='f'&&code!='s'){
		printf("��������ȷ���\n");
		code=getch();
		fflush(stdin);
	}
	type=code;
	InitAQueue(&queue);
	printf("���г�ʼ���ɹ�\n");
	isInit=1;
}
void fun2(){
	if(isInit==0){
		printf("������δ��ʼ��\n");
		return;
	}
	Status s=IsEmptyAQueue(&queue);
	if(s){
		printf("����Ϊ��\n");
		return;
	}
	printf("���в�Ϊ��\n");
}
void fun3(){
	fflush(stdin);
	if(isInit==0){
		printf("������δ��ʼ��\n");
		return;
	}
	//������  
	if(type==INTEGER){
		int i;
		printf("��������������:\n");
		while(!isLegal(&i)){
			printf("����������ֵ����\n");
			fflush(stdin);
		}
		if(EnAQueue(&queue,&i)){
			printf("��ӳɹ�\n");
		}
		fflush(stdin);
	}
	//С���� 
	if(type==FLOAT){
		double d;
		printf("������С������:\n");
		while(scanf("%lf",&d)==0){
			fflush(stdin);
			printf("��������ȷС��\n"); 
		}
		if(EnAQueue(&queue,&d)){
			printf("��ӳɹ�\n");
		}
		fflush(stdin);
	}
	//�ַ�����
	if(type==STRING){
		char* str=(char*)malloc(stringSize+1);
		char** strPtr=&str;
		char c;
		printf("�������ַ���:\n");
		//��ֹ����Խ�磬һ�����ַ���ȡ 
		c=getchar();
		int i=0;
		for(;c!='\n';c=getchar()){
			str[i++]=c;
		}
		//û������ ���߳������� 
		while(i==0||i>stringSize){
			if(i==0){
				printf("����Ϊ��\n");
			}else{
				printf("�ַ�����С���ó���100\n");
			}
			fflush(stdin);
			c=getchar();
			i=0;
			for(;c!='\n';c=getchar()){
			str[i++]=c;
			}
		}
		str[i]='\0';
		if(EnAQueue(&queue,strPtr)){
			printf("��ӳɹ�\n");
		}
		fflush(stdin);
	} 
}
void fun4(){
	if(isInit==0){
		printf("δ��ʼ������\n");
		return;
	}
	Status s= DeAQueue(&queue);
	if(s==TRUE){
		printf("���ӳɹ�\n");
	}else{
		printf("����Ϊ��\n");
	}
}
void fun5(){
	if(isInit==0){
		printf("δ��ʼ������\n");
		return;
	}
	int len=LengthAQueue(&queue);
	printf("���г���Ϊ%d\n",len);
}
void fun6(){
	if(isInit==0){
		printf("δ��ʼ������\n");
		return;
	}
	if(IsEmptyAQueue(&queue)){
		printf("��ȡʧ��,����Ϊ��\n");
		return;
	}
	if(type==INTEGER){
		void* data=malloc(dataSize);
		if(GetHeadAQueue(&queue,data)){
			printf("��ͷԪ��Ϊ:%d\n",*(int*)data);
		}
	}
	if(type==FLOAT){
		void* data=malloc(dataSize);
		if(GetHeadAQueue(&queue,data)){
			printf("��ͷԪ��Ϊ:%f\n",*(double*)data);
		}
	}
	if(type==STRING){
		void* data=malloc(sizeof(int));
		if(GetHeadAQueue(&queue,data)){
			printf("��ͷԪ��Ϊ:%s\n",*(char**)data);
		}
	}
}
void fun7(){
	if(isInit==0){
		printf("����δ��ʼ��\n");
		return;
	}
	TraverseAQueue(&queue,APrint);
}
void fun8(){
	if(isInit==0){
		printf("����δ��ʼ��\n");
		return;
	}
	ClearAQueue(&queue);
	printf("��ճɹ�\n");
	
}
void fun9(){
	if(isInit==0){
		printf("δ��ʼ������\n");
		return;
	}
	DestoryAQueue(&queue);
	printf("���ٳɹ�\n");
	isInit=0;
} 

//�ж������Ƿ�Ϸ� 
int isLegal(int* e){
	double d=0;
	char a[500];
	gets(a);
	int len=0;
	while(a[len]!='\0'){
		len++;
	}
	if(len==0){
		return 0;
	}
	int symbol=1;
	if(a[0]=='-') symbol=-1;
	int i=0;
	if(a[0]=='+'||a[0]=='-'){
		i++;
		len--;
	}
	if(a[i]=='0'){
		return 0;
	}
	for(;a[i]!='\0';i++){
		if(a[i]<'0'||a[i]>'9'){
			return 0;
		}
		d+=pow(10,--len)*(a[i]-'0');
	}
	long long val=symbol*(long long)d;
	if(val<INT_MIN||val>INT_MAX){
		return 0;
	}
	*e=(int)val;
	return 1;
}
