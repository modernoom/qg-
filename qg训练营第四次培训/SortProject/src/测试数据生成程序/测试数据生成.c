#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define LEVEL1 10
#define LEVEL2 10000 
#define LEVEL3 50000
#define LEVEL4 200000

void menu();
char chooseSize();
void dataSave(FILE * fp,int size,int max);
void fun1();
void fun2();
void fun3();
void fun4();

int main(){
		while(1){
		menu();
		printf("请选择生成的数据规模:\n");
		int a;
		fflush(stdin);
		char code=getch();
		switch(code){
			case '1':fun1();break;
			case '2':fun2();break;
			case '3':fun3();break;
			case '4':fun4();break;
		}
		system("pause");
		system("cls");
	} 
	return 0;	
}

void menu(){
	printf("\t\t==========================================\n");
	printf("\t\t==          测试数据生成程序            ==\n");
	printf("\t\t==========================================\n"); 
	printf("\t\t**********     1. 10            **********\n");
	printf("\t\t**********     2. 10000         **********\n");
	printf("\t\t**********     3. 50000         *********\n");
	printf("\t\t**********     3. 200000        **********\n");
	printf("\t\t==========================================\n");
}

void fun1(){
	FILE *fp;
	char code=chooseSize();
	switch(code){
		case '1':{
			fp=fopen("../src/testData/1-1.txt","w");
			dataSave(fp,LEVEL1,9);
			break;
		}
		case '2':{
			fp=fopen("../src/testData/1-2.txt","w");
			dataSave(fp,LEVEL1,99);
			break;
		}
		case '3':{
			fp=fopen("../src/testData/1-3.txt","w");
			dataSave(fp,LEVEL1,999);
			break;
		}
		case '4':{
			fp=fopen("../src/testData/1-4.txt","w");
			dataSave(fp,LEVEL1,9999);
			break;
		}
	}
	fclose(fp);
}
void fun2(){
	FILE *fp;
	char code=chooseSize();
	switch(code){
		case '1':{
			fp=fopen("../src/testData/2-1.txt","w");
			dataSave(fp,LEVEL2,9);
			break;
		}
		case '2':{
			fp=fopen("../src/testData/2-2.txt","w");
			dataSave(fp,LEVEL2,99);
			break;
		}
		case '3':{
			fp=fopen("../src/testData/2-3.txt","w");
			dataSave(fp,LEVEL2,999);
			break;
		}
		case '4':{
			fp=fopen("../src/testData/2-4.txt","w");
			dataSave(fp,LEVEL2,9999);
			break;
		}
	}
	fclose(fp);
}
void fun3(){
	FILE *fp;
	char code=chooseSize();
	switch(code){
		case '1':{
			fp=fopen("../src/testData/3-1.txt","w");
			dataSave(fp,LEVEL3,9);
			break;
		}
		case '2':{
			fp=fopen("../src/testData/3-2.txt","w");
			dataSave(fp,LEVEL3,99);
			break;
		}
		case '3':{
			fp=fopen("../src/testData/3-3.txt","w");
			dataSave(fp,LEVEL3,999);
			break;
		}
		case '4':{
			fp=fopen("../src/testData/3-4.txt","w");
			dataSave(fp,LEVEL3,9999);
			break;
		}
	}
	fclose(fp);
}
void fun4(){
	FILE *fp;
	char code=chooseSize();
	switch(code){
		case '1':{
			fp=fopen("../src/testData/4-1.txt","w");
			dataSave(fp,LEVEL4,9);
			break;
		}
		case '2':{
			fp=fopen("../src/testData/4-2.txt","w");
			dataSave(fp,LEVEL4,99);
			break;
		}
		case '3':{
			fp=fopen("../src/testData/4-3.txt","w");
			dataSave(fp,LEVEL4,999);
			break;
		}
		case '4':{
			fp=fopen("../src/testData/4-4.txt","w");
			dataSave(fp,LEVEL4,9999);
			break;
		}
	}
	fclose(fp);
}

void dataSave(FILE* fp,int size,int max){
	int i;
	for(i=0;i<size;i++){
		int num=rand();
		if(num>max){
			num%=max;
		}
		fprintf(fp,"%d ",num);
	}
	printf("数据生成成功,已成功保存至文件夹src/testData目录下\n");
}


char chooseSize(){
	printf("请选择数据范围:\n1.0-9 2.0-99 3.0-999 4.0-9999\n");
	char code;
	scanf("%c",&code);
	while(code!='1'&&code!='2'&&code!='3'&&code!='4'){
		printf("请输入正确数字!\n");
		scanf("%c",&code);
	}
	return code;
}
