#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "../head/linkedList.h"
LinkedList head=NULL;
void menu();
int isLegal();
void printLink();
void fun1();
void fun2();
void fun3();
void fun4();
void fun4(); 
void fun5();
void fun6();
void fun7();
void fun8();
void fun9();
void fun0();

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
			case '0':fun0();break;
		}
		system("pause");
		system("cls");
	} 
	return 0;	
}

void menu(){
	printf("\t\t==========================================\n");
	printf("\t\t==                链表系统              ==\n");
	printf("\t\t==========================================\n"); 
	printf("\t\t**********     1. 初始化链表    **********\n");
	printf("\t\t**********     2. 插入一条数据  **********\n");
	printf("\t\t**********     3. 删除一条记录  **********\n");
	printf("\t\t**********     4. 遍历链表      **********\n");
	printf("\t\t**********     5. 查找节点      **********\n");
	printf("\t\t**********     6. 反转链表      **********\n");
	printf("\t\t**********     7. 判断是否成环  **********\n");
	printf("\t\t**********     8. 奇偶结点反转  **********\n");
	printf("\t\t**********     9. 查找中间节点  **********\n");
	printf("\t\t**********     0. 销毁链表      **********\n");
	printf("\t\t==========================================\n");
}

int isLegal(ElemType* e){
	double d=0;
	char a[500];
	gets(a);
	int len=0;
	while(a[len]!='\0'){
		len++;
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

void printLink(ElemType e){
	printf("%d",e);
}

void fun1(){
	if(head!=NULL){
		printf("链表已经初始化过，请先销毁链表\n");
		return ;
	}
	InitList(&head);
}

void fun2(){
	if(head==NULL){
		printf("链表尚未初始化\n");
		return;
	}
	LNode* p=head;
	printf("请输入要插入的数据\n");
	ElemType e;
	int flag=isLegal(&e);
	while(flag==0){
		printf("请输入正确格式，需要您输入-32768～32767范围的int整数\n");
		flag=isLegal(&e);
	}
	LNode* q=(LNode*)malloc(sizeof(LNode));
	q->data=e;
	while(p->next){
		p=p->next;
	}
	InsertList(p,q);
}

void fun3(){
	if(head==NULL){
		printf("链表尚未初始化\n");
		return;
	}
	LNode* p=head;
	if(p->next==NULL){
		printf("链表为空");
	}
	while(p->next->next!=NULL){
		p=p->next;
	}
	ElemType e;
	Status s=DeleteList(p,&e);
	if(s){
		printf("删除成功，被移除节点保存的值为 %d\n",e);
	}
}

void fun4(){
	TraverseList(head,printLink);
}

void fun5(){
	if(head==NULL){
		printf("链表尚未初始化\n");
		return;
	}
	printf("请输入要查找的节点的值:\n");
	ElemType e;
	int flag=isLegal(&e);
	while(flag==0){
		printf("请输入正确格式，需要您输入-32768～32767范围的int整数\n");
		flag=isLegal(&e);
	}
	SearchList(head,e); 
}

void fun6(){
	ReverseList(&head);
}

void fun7(){
	IsLoopList(head);
}

void fun8(){
	ReverseEvenList(&head);
}

void fun9(){
	LNode*min=FindMidNode(&head);
	if(min!=NULL){
		printf("成功查询中间节点，值为:%d\n",min->data);
	}
}

void fun0(){
	DestroyList(&head);
}
