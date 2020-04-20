#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#include<time.h>

#include "../../inc/qgsort.h"

 
#define LEVEL1 10
#define LEVEL2 10000
#define LEVEL3 50000
#define LEVEL4 200000

int * a;
int *temp;	
void menu();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
char choose();
void dataGetter(FILE* fp,int size,int max);
void tester(int size,int max);
void testMenu(int size,int max);
void dataCopy(int *p,int size);
void printData();
void printResult(int *p);
int main(){
		while(1){
		menu();
		char code=getch();
		switch(code){
			case '1':test1();break;
			case '2':test2();break;
			case '3':test3();break;
			case '4':test4();break;
			case '5':test5();break;
			case '6':test6();break;
			case '7':test7();break;
		}
		system("pause");
		system("cls");
	} 
	return 0;	
}

void menu(){
	printf("\t\t==========================================\n");
	printf("\t\t==      ��ȡ�������ݲ���������        ==\n");
	printf("\t\t==============ѡ�����ݹ�ģ================\n"); 
	printf("\t\t**********     1. 10(���ݿɼ�) **********\n");
	printf("\t\t**********     2. 10000        **********\n");
	printf("\t\t**********     3. 50000        **********\n");
	printf("\t\t**********     4. 200000       **********\n");
	printf("\t\t=========================================\n");
	
	printf("\t\t==========================================\n");
	printf("\t\t==          ����Ӧ�������              ==\n");
	printf("\t\t==========================================\n"); 
	printf("\t\t**********     5. ��ɫ����      **********\n");
	printf("\t\t**********     6. ѡ����kС���� **********\n");
	printf("\t\t**********     7. ѡ����k����� **********\n");
	printf("\t\t=========================================\n");
}

void test1(){
	temp=(int*)malloc(sizeof(int)*LEVEL1);
	printf("��ѡ�����ݷ�Χ:\n1.0-9  2.0-99  3.0-999 4.0-9999\n");
	char code=choose();
	FILE *fp;
	switch(code){
		case '1':{
			fp = fopen("../src/testData/1-1.txt", "r");
			if(fp==NULL){
				printf("�ļ������ڣ��㻹δ���ɴ�������\n");
				return;
			}else{
				dataGetter(fp,LEVEL1,9);
				tester(LEVEL1,9);
			}
			break;
		}
		case '2':{
			fp=fopen("../src/testData/1-2.txt","r");
			if(fp==NULL){
				printf("�ļ������ڣ��㻹δ���ɴ�������\n");
				return;
			}else{
				dataGetter(fp,LEVEL1,99);
				tester(LEVEL1,99);
			}
			break;
		}
		case '3':{
			fp=fopen("../src/testData/1-3.txt","r");
			if(fp==NULL){
				printf("�ļ������ڣ��㻹δ���ɴ�������\n");
				return;
			}else{
				dataGetter(fp,LEVEL1,999);
				tester(LEVEL1,999);
			}
			break;
		}
		case '4':{
			fp=fopen("../src/testData/1-4.txt","r");
			if(fp==NULL){
				printf("�ļ������ڣ��㻹δ���ɴ�������\n");
				return;
			}else{
				dataGetter(fp,LEVEL1,9999);
				tester(LEVEL1,9999);
			}
			break;
		}
	}	
}
void test2(){
	temp=(int*)malloc(sizeof(int)*LEVEL2);
	printf("��ѡ�����ݷ�Χ:\n1.0-9  2.0-99  3.0-999 4.0-9999\n");
	char code=choose();
	FILE *fp;
	switch(code){
		case '1':{
			fp=fopen("../src/testData/2-1.txt","r");
			if(fp==NULL){
				printf("�ļ������ڣ��㻹δ���ɴ�������\n");
				return;
			}else{
				dataGetter(fp,LEVEL2,9);
				tester(LEVEL2,9);
			}
			break;
		}
		case '2':{
			fp=fopen("../src/testData/2-2.txt","r");
			if(fp==NULL){
				printf("�ļ������ڣ��㻹δ���ɴ�������\n");
				return;
			}else{
				dataGetter(fp,LEVEL2,99);
				tester(LEVEL2,99);
			}
			break;
		}
		case '3':{
			fp=fopen("../src/testData/2-3.txt","r");
			if(fp==NULL){
				printf("�ļ������ڣ��㻹δ���ɴ�������\n");
				return;
			}else{
				dataGetter(fp,LEVEL2,999);
				tester(LEVEL2,999);
			}
			break;
		}
		case '4':{
		fp=fopen("../src/testData/2-4.txt","r");
			if(fp==NULL){
				printf("�ļ������ڣ��㻹δ���ɴ�������\n");
				return;
			}else{
				dataGetter(fp,LEVEL2,9999);
				tester(LEVEL2,9999);
			}
			break;
		}
	}	
}
void test3(){
	temp=(int*)malloc(sizeof(int)*LEVEL3);
	printf("��ѡ�����ݷ�Χ:\n1.0-9  2.0-99  3.0-999 4.0-9999\n");
	char code=choose();
	FILE *fp;
	switch(code){
		case '1':{
			fp=fopen("../src/testData/3-1.txt","r");
			if(fp==NULL){
				printf("�ļ������ڣ��㻹δ���ɴ�������\n");
				return;
			}else{
				dataGetter(fp,LEVEL3,9);
				tester(LEVEL3,9);
			}
			break;
		}
		case '2':{
			fp=fopen("../src/testData/3-2.txt","r");
			if(fp==NULL){
				printf("�ļ������ڣ��㻹δ���ɴ�������\n");
				return;
			}else{
				dataGetter(fp,LEVEL3,99);
				tester(LEVEL3,99);
			}
			break;
		}
		case '3':{
			fp=fopen("../src/testData/3-3.txt","r");
			if(fp==NULL){
				printf("�ļ������ڣ��㻹δ���ɴ�������\n");
				return;
			}else{
				dataGetter(fp,LEVEL3,999);
				tester(LEVEL3,999);
			}
			break;
		}
		case '4':{
			fp=fopen("../src/testData/3-4.txt","r");
			if(fp==NULL){
				printf("�ļ������ڣ��㻹δ���ɴ�������\n");
				return;
			}else{
				dataGetter(fp,LEVEL3,9999);
				tester(LEVEL3,9999);
			}
			break;
		}
	}	
}
void test4(){
	temp=(int*)malloc(sizeof(int)*LEVEL4);
	printf("��ѡ�����ݷ�Χ:\n1.0-9  2.0-99  3.0-999 4.0-9999\n");
	char code=choose();
	FILE *fp;
	switch(code){
		case '1':{
			fp=fopen("../src/testData/4-1.txt","r");
			if(fp==NULL){
				printf("�ļ������ڣ��㻹δ���ɴ�������\n");
				return;
			}else{
				dataGetter(fp,LEVEL4,9);
				tester(LEVEL4,9);
			}
			break;
		}
		case '2':{
			fp=fopen("../src/testData/4-2.txt","r");
			if(fp==NULL){
				printf("�ļ������ڣ��㻹δ���ɴ�������\n");
				return;
			}else{
				dataGetter(fp,LEVEL4,99);
				tester(LEVEL4,99);
			}
			break;
		}
		case '3':{
			fp=fopen("../src/testData/4-3.txt","r");
			if(fp==NULL){
				printf("�ļ������ڣ��㻹δ���ɴ�������\n");
				return;
			}else{
				dataGetter(fp,LEVEL4,999);
				tester(LEVEL4,999);
			}
			break;
		}
		case '4':{
			fp=fopen("../src/testData/4-1.txt","r");
			if(fp==NULL){
				printf("�ļ������ڣ��㻹δ���ɴ�������\n");
				return;
			}else{
				dataGetter(fp,LEVEL4,9999);
				tester(LEVEL4,9999);
			}
			break;
		}
	}	
}

void test5(){
	printf("���������������\n");
	int i;
	int b[10];
	for(i=0;i<10;i++){
		int num=rand();
		if(num>2){
			num%=3;
		}
		b[i]=num;
	}
	printf("���ݳɹ�����,ԭʼ����Ϊ:\n");
	for(i=0;i<10;i++){
		printf("%d ",b[i]);
	}
	printf("\n");
	ColorSort(b,10);
	printf("�������: ");
	for(i=0;i<10;i++){
		printf("%d ",b[i]);
	}
	printf("\n");
}
void test6(){
	printf("���������������\n");
	int i;
	int b[10];
	for(i=0;i<10;i++){
		int num=rand();
		if(num>50){
			num%=51;
		}
		b[i]=num;
	}
	printf("���ݳɹ�����,ԭʼ����Ϊ:\n");
	for(i=0;i<10;i++){
		printf("%d ",b[i]);
	}
	printf("\n������Kֵ(1-10)\n");
	int k;
	fflush(stdin);
	while(scanf("%d",&k)==0){
		printf("��������ȷkֵ\n");
		fflush(stdin);
	}
	printf("��%dС����Ϊ:%d",k,findMinK(b,10,k));
	printf("\n");
}
void test7(){
	printf("���������������\n");
	int i;
	int b[10];
	for(i=0;i<10;i++){
		int num=rand();
		if(num>50){
			num%=51;
		}
		b[i]=num;
	}
	printf("���ݳɹ�����,ԭʼ����Ϊ:\n");
	for(i=0;i<10;i++){
		printf("%d ",b[i]);
	}
	printf("\n������Kֵ(1-10)\n");
	int k;
	fflush(stdin);
	while(scanf("%d",&k)==0){
		printf("��������ȷkֵ\n");
		fflush(stdin);
	}
	printf("��%d�����Ϊ:%d",k,findMaxK(b,10,k));
	printf("\n");
}

char choose(){
	char code;
	scanf("%c",&code);
	while(code!='1'&&code!='2'&&code!='3'&&code!='4'){
		printf("��������ȷָ��\n");
		scanf("%c",&code);
	}
	return code;
}
void dataGetter(FILE* fp,int size,int max){
	a=(int *)malloc(sizeof(int)*size);
	int i=0;
	while(!feof(fp)&&i<size){
		fscanf(fp,"%d",&a[i++]);
	}
}
void tester(int size,int max){
	while(1){
		testMenu(size,max);
		char code=getch();
		if(code=='6'){
			free(a);
			free(temp); 
			break;
		}
		switch(code){
			case '1':{
				//copyȡ�������ݣ�ʼȡ�������ݿɶ��ʹ�� 
				int *p=(int*)malloc(sizeof(int)*size);
				dataCopy(p,size);
				if(size==LEVEL1){
					printData(p);
					insertSort(p,size);
					printf("��������ִ�гɹ�\n");
					printResult(p);
				}else{
					
					clock_t insertStart=clock();
            		insertSort(p,size);
            		int result=clock()-insertStart;
					printf("ִ�в�������ɹ� ��ʱ:%dms\n",result);	
				}
				free(p);
            	break;
			}
			case '2':{
				//copyȡ�������ݣ�ʼȡ�������ݿɶ��ʹ�� 
				int *p=(int*)malloc(sizeof(int)*size);
				dataCopy(p,size);
				if(size==LEVEL1){
					printData(p);
					MergeSort(p,0,size-1,temp);
					printf("�鲢����ִ�гɹ�\n");
					printResult(p);
				}else{
					clock_t mergeStart=clock();
            		MergeSort(p,0,size-1,temp);
            		int result=clock()-mergeStart;
					printf("ִ�й鲢����ɹ� ��ʱ:%dms\n",result);	
				}
				free(p);
            	break;
			}
			case '3':{
				//copyȡ�������ݣ�ʼȡ�������ݿɶ��ʹ�� 
				int *p=(int*)malloc(sizeof(int)*size);
				dataCopy(p,size);
				if(size==LEVEL1){
					printData(p);
					QuickSort_Recursion(p,0,size-1);
					printf("��������ִ�гɹ�\n");
					printResult(p);
				}else{
					clock_t quickStart=clock();
            		QuickSort_Recursion(p,0,size-1);
            		int result=clock()-quickStart;
					printf("ִ�п�������ɹ� ��ʱ:%dms\n",result);	
				}
				free(p);
            	break;
			}
			case '4':{
				//copyȡ�������ݣ�ʼȡ�������ݿɶ��ʹ�� 
				int *p=(int*)malloc(sizeof(int)*size);
				dataCopy(p,size);
				if(size==LEVEL1){
					printData(p);
					CountSort(p,size,max);
					printf("��������ִ�гɹ�\n");
					printResult(p);
				}else{
					clock_t countStart=clock();
            		CountSort(p,size,max);
            		int result=clock()-countStart;
					printf("ִ�м�������ɹ� ��ʱ:%dms\n",result);	
				}
				free(p);
				break;
			}
			case '5':{
				//copyȡ�������ݣ�ʼȡ�������ݿɶ��ʹ�� 
				int *p=(int*)malloc(sizeof(int)*size);
				dataCopy(p,size);
				if(size==LEVEL1){
					printData(p);
					RadixCountSort(p,size);
					printf("��������ִ�гɹ�\n");
					printResult(p);
				}else{
					clock_t radixStart=clock();
            		RadixCountSort(p,size);
            		int result=clock()-radixStart;
					printf("ִ�л�������ɹ� ��ʱ:%dms\n",result);	
				}
				free(p);
				break;
			}
		}
		system("pause");
		system("cls");
	}
}	
void testMenu(int size,int max){
	system("cls");
	printf("���ݶ�ȡ���,��ѡ�������Ŀ:\n");
	printf("��ǰ���ݹ�ģ:%d ��ǰ�������ֵ:%d\n",size,max);
	printf("\t\t==========================================\n");
	printf("\t\t==              ѡ�������Ŀ            ==\n");
	printf("\t\t==========================================\n"); 
	printf("\t\t**********     1. ��������      **********\n");
	printf("\t\t**********     2. �鲢����      **********\n");
	printf("\t\t**********     3. ��������      **********\n");
	printf("\t\t**********     4. ��������      **********\n");
	printf("\t\t**********     5. ��������      **********\n");
	printf("\t\t**********     6.�������˵�     **********\n");
	printf("\t\t=========================================\n");
}
void dataCopy(int *p,int size){
	int i;
	for(i=0;i<size;i++){
		p[i]=a[i];
	}
}
void printData(int *p){
	printf("����ǰ:");
	int i;
	for(i=0;i<LEVEL1;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
}
void printResult(int *p){
	int i;
	printf("�����:\n");
	for(i=0;i<LEVEL1;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
}
