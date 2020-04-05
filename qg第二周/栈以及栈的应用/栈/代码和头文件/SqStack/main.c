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
	printf("\t\t==               ˳��ջϵͳ             ==\n");
	printf("\t\t==========================================\n"); 
	printf("\t\t**********     1. ��ʼ����ջ    **********\n");
	printf("\t\t**********     2. �Ƿ��ջ      **********\n");
	printf("\t\t**********     3. ��ջ          **********\n");
	printf("\t\t**********     4. ��ջ          **********\n");
	printf("\t\t**********     5. ����ջ        **********\n");
	printf("\t\t**********     6. ջ����        **********\n");
	printf("\t\t**********     7. ����ջ��Ԫ��  **********\n");
	printf("\t\t**********     8. ���ջ        **********\n");
	printf("\t\t**********     9. ����ջ        **********\n");
	printf("\t\t==========================================\n");
}

void fun1(){
	printf("������ջ���������\n");
	ElemType e;
	int flag=isLegal(&e);
	while(!flag){
		printf("��������ȷ��ʽ����Ҫ������-32768��32767��Χ��int����\n");
		flag=isLegal(&e);
	}
	if(initStack(&stack,e)){
		printf("��ʼ���ɹ�\n");
		isInit=1;
		return;
	}
	printf("��ʼ��ʧ��\n");
}

void fun2(){
	if(!isInit){
		printf("ջδ��ʼ��!\n");
		return;
	}
	if(isEmptyStack(&stack)){
		printf("�ǿ�ջ\n");
		return;
	}
	printf("���ǿ�ջ\n");
}

void fun3(){
	if(!isInit){
		printf("ջδ��ʼ��!\n");
		return;
	}
	printf("��������ջ����\n");
	ElemType e;
	int flag=isLegal(&e);
	while(!flag){
		printf("��������ȷ��ʽ����Ҫ������-32768��32767��Χ��int����\n");
		flag=isLegal(&e);
	}
	Status status=pushStack(&stack,e);
	if(status){
		printf("��ջ�ɹ�\n");
	}
}

void fun4(){
	if(!isInit){
		printf("ջδ��ʼ��!\n");
		return;
	}
	ElemType e;
	Status status=popStack(&stack,&e);
	if(status){
		printf("��ջ�ɹ�����ջ����Ϊ%d\n",e);
	}
}

void fun5(){
	if(!isInit){
		printf("ջδ��ʼ��!\n");
		return;
	}
	int p=stack.top;
	if(p<0){
		printf("��ջΪ��\n");
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
		printf("ջδ��ʼ��!\n");
		return;
	}
	int length;
	if(stackLength(&stack,&length)){
		printf("ջ����Ϊ%d\n",length);
	}
}

void fun7(){
	if(!isInit){
		printf("ջδ��ʼ��!\n");
		return;
	}
	ElemType e;
	if(getTopStack(&stack,&e)){
		printf("ջ��Ԫ��:%d\n",e);
	}
}

void fun8(){
	if(!isInit){
		printf("ջδ��ʼ��!\n");
		return;
	}
	if(clearStack(&stack)){
		printf("�ɹ����\n");
	}
	
}

void fun9(){
	if(!isInit){
		printf("ջδ��ʼ��!\n");
		return;
	}
	if(destroyStack(&stack)){
		printf("���ٳɹ�\n");
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

