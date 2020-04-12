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
	printf("\t\t==                链队系统              ==\n");
	printf("\t\t==========================================\n"); 
	printf("\t\t**********     1. 初始化队列    **********\n");
	printf("\t\t**********     2. 是否空队      **********\n");
	printf("\t\t**********     3. 入队          **********\n");
	printf("\t\t**********     4. 出队          **********\n");
	printf("\t\t**********     5. 队列大小      **********\n");
	printf("\t\t**********     6. 获取队头元素  **********\n");
	printf("\t\t**********     7. 遍历队列      **********\n");
	printf("\t\t**********     8. 清空队列      **********\n");
	printf("\t\t**********     9. 销毁队列      **********\n");
	printf("\t\t==========================================\n");
}

void fun1(){
	if(isInit){
		printf("已初始化过，重复初始化请先销毁\n");
		return;
	}
	printf("请选择该队列存储的数据类型: i .整数型   f.小数型   s.字符串型\n");
	fflush(stdin);
	char code;
	code=getch(); 
	while(code!='i'&&code!='f'&&code!='s'){
		printf("请输入正确序号\n");
		code=getch();
		fflush(stdin);
	}
	type=code;
	InitAQueue(&queue);
	printf("队列初始化成功\n");
	isInit=1;
}
void fun2(){
	if(isInit==0){
		printf("队列尚未初始化\n");
		return;
	}
	Status s=IsEmptyAQueue(&queue);
	if(s){
		printf("队列为空\n");
		return;
	}
	printf("队列不为空\n");
}
void fun3(){
	fflush(stdin);
	if(isInit==0){
		printf("队列尚未初始化\n");
		return;
	}
	//整数型  
	if(type==INTEGER){
		int i;
		printf("请输入整数数据:\n");
		while(!isLegal(&i)){
			printf("输入错误或数值过大\n");
			fflush(stdin);
		}
		if(EnAQueue(&queue,&i)){
			printf("入队成功\n");
		}
		fflush(stdin);
	}
	//小数型 
	if(type==FLOAT){
		double d;
		printf("请输入小数数据:\n");
		while(scanf("%lf",&d)==0){
			fflush(stdin);
			printf("请输入正确小数\n"); 
		}
		if(EnAQueue(&queue,&d)){
			printf("入队成功\n");
		}
		fflush(stdin);
	}
	//字符串型
	if(type==STRING){
		char* str=(char*)malloc(stringSize+1);
		char** strPtr=&str;
		char c;
		printf("请输入字符串:\n");
		//防止输入越界，一个个字符读取 
		c=getchar();
		int i=0;
		for(;c!='\n';c=getchar()){
			str[i++]=c;
		}
		//没有输入 或者超出容量 
		while(i==0||i>stringSize){
			if(i==0){
				printf("内容为空\n");
			}else{
				printf("字符串大小不得超过100\n");
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
			printf("入队成功\n");
		}
		fflush(stdin);
	} 
}
void fun4(){
	if(isInit==0){
		printf("未初始化队列\n");
		return;
	}
	Status s= DeAQueue(&queue);
	if(s==TRUE){
		printf("出队成功\n");
	}else{
		printf("队列为空\n");
	}
}
void fun5(){
	if(isInit==0){
		printf("未初始化队列\n");
		return;
	}
	int len=LengthAQueue(&queue);
	printf("队列长度为%d\n",len);
}
void fun6(){
	if(isInit==0){
		printf("未初始化队列\n");
		return;
	}
	if(IsEmptyAQueue(&queue)){
		printf("获取失败,队列为空\n");
		return;
	}
	if(type==INTEGER){
		void* data=malloc(dataSize);
		if(GetHeadAQueue(&queue,data)){
			printf("队头元素为:%d\n",*(int*)data);
		}
	}
	if(type==FLOAT){
		void* data=malloc(dataSize);
		if(GetHeadAQueue(&queue,data)){
			printf("队头元素为:%f\n",*(double*)data);
		}
	}
	if(type==STRING){
		void* data=malloc(sizeof(int));
		if(GetHeadAQueue(&queue,data)){
			printf("队头元素为:%s\n",*(char**)data);
		}
	}
}
void fun7(){
	if(isInit==0){
		printf("队列未初始化\n");
		return;
	}
	TraverseAQueue(&queue,APrint);
}
void fun8(){
	if(isInit==0){
		printf("队列未初始化\n");
		return;
	}
	ClearAQueue(&queue);
	printf("清空成功\n");
	
}
void fun9(){
	if(isInit==0){
		printf("未初始化队列\n");
		return;
	}
	DestoryAQueue(&queue);
	printf("销毁成功\n");
	isInit=0;
} 

//判断整数是否合法 
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
