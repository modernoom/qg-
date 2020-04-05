#include<stdio.h>
#include "../head/SqStack.h"
#include<math.h>
#include<conio.h>

SqStack stack;
int isInit=0;
void menu();
int isLegal();
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
	printf("\t\t==               顺序栈系统             ==\n");
	printf("\t\t==========================================\n"); 
	printf("\t\t**********     1. 初始化链栈    **********\n");
	printf("\t\t**********     2. 是否空栈      **********\n");
	printf("\t\t**********     3. 入栈          **********\n");
	printf("\t\t**********     4. 出栈          **********\n");
	printf("\t\t**********     5. 遍历栈        **********\n");
	printf("\t\t**********     6. 栈长度        **********\n");
	printf("\t\t**********     7. 查找栈顶元素  **********\n");
	printf("\t\t**********     8. 清空栈        **********\n");
	printf("\t\t**********     9. 销毁栈        **********\n");
	printf("\t\t==========================================\n");
}

void fun1(){
	printf("请输入栈的最大容量\n");
	ElemType e;
	int flag=isLegal(&e);
	while(!flag){
		printf("请输入正确格式，需要您输入-32768～32767范围的int整数\n");
		flag=isLegal(&e);
	}
	if(initStack(&stack,e)){
		printf("初始化成功\n");
		isInit=1;
		return;
	}
	printf("初始化失败\n");
}

void fun2(){
	if(!isInit){
		printf("栈未初始化!\n");
		return;
	}
	if(isEmptyStack(&stack)){
		printf("是空栈\n");
		return;
	}
	printf("不是空栈\n");
}

void fun3(){
	if(!isInit){
		printf("栈未初始化!\n");
		return;
	}
	printf("请输入入栈数据\n");
	ElemType e;
	int flag=isLegal(&e);
	while(!flag){
		printf("请输入正确格式，需要您输入-32768～32767范围的int整数\n");
		flag=isLegal(&e);
	}
	Status status=pushStack(&stack,e);
	if(status){
		printf("入栈成功\n");
	}
}

void fun4(){
	if(!isInit){
		printf("栈未初始化!\n");
		return;
	}
	ElemType e;
	Status status=popStack(&stack,&e);
	if(status){
		printf("出栈成功，出栈数据为%d\n",e);
	}
}

void fun5(){
	if(!isInit){
		printf("栈未初始化!\n");
		return;
	}
	int p=stack.top;
	if(p<0){
		printf("链栈为空\n");
		return;
	}
	while(p>=0){
		printf("%d  ",*(stack.elem+p));
		p--;
	}
	printf("\n");
}

void fun6(){
	if(!isInit){
		printf("栈未初始化!\n");
		return;
	}
	int length;
	if(stackLength(&stack,&length)){
		printf("栈长度为%d\n",length);
	}
}

void fun7(){
	if(!isInit){
		printf("栈未初始化!\n");
		return;
	}
	ElemType e;
	if(getTopStack(&stack,&e)){
		printf("栈顶元素:%d\n",e);
	}
}

void fun8(){
	if(!isInit){
		printf("栈未初始化!\n");
		return;
	}
	if(clearStack(&stack)){
		printf("成功清空\n");
	}
	
}

void fun9(){
	if(!isInit){
		printf("栈未初始化!\n");
		return;
	}
	if(destroyStack(&stack)){
		printf("销毁成功\n");
		isInit=0;
	}
}

int isLegal(ElemType* e){
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
	if(val>32767||val<-32768){
		return 0;
	} 
	*e=(int)val;
	return 1;
}

