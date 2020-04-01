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
	printf("\t\t==                ����ϵͳ              ==\n");
	printf("\t\t==========================================\n"); 
	printf("\t\t**********     1. ��ʼ������    **********\n");
	printf("\t\t**********     2. ����һ������  **********\n");
	printf("\t\t**********     3. ɾ��һ����¼  **********\n");
	printf("\t\t**********     4. ��������      **********\n");
	printf("\t\t**********     5. ���ҽڵ�      **********\n");
	printf("\t\t**********     6. ��ת����      **********\n");
	printf("\t\t**********     7. �ж��Ƿ�ɻ�  **********\n");
	printf("\t\t**********     8. ��ż��㷴ת  **********\n");
	printf("\t\t**********     9. �����м�ڵ�  **********\n");
	printf("\t\t**********     0. ��������      **********\n");
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
		printf("�����Ѿ���ʼ������������������\n");
		return ;
	}
	InitList(&head);
}

void fun2(){
	if(head==NULL){
		printf("������δ��ʼ��\n");
		return;
	}
	LNode* p=head;
	printf("������Ҫ���������\n");
	ElemType e;
	int flag=isLegal(&e);
	while(flag==0){
		printf("��������ȷ��ʽ����Ҫ������-32768��32767��Χ��int����\n");
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
		printf("������δ��ʼ��\n");
		return;
	}
	LNode* p=head;
	if(p->next==NULL){
		printf("����Ϊ��");
	}
	while(p->next->next!=NULL){
		p=p->next;
	}
	ElemType e;
	Status s=DeleteList(p,&e);
	if(s){
		printf("ɾ���ɹ������Ƴ��ڵ㱣���ֵΪ %d\n",e);
	}
}

void fun4(){
	TraverseList(head,printLink);
}

void fun5(){
	if(head==NULL){
		printf("������δ��ʼ��\n");
		return;
	}
	printf("������Ҫ���ҵĽڵ��ֵ:\n");
	ElemType e;
	int flag=isLegal(&e);
	while(flag==0){
		printf("��������ȷ��ʽ����Ҫ������-32768��32767��Χ��int����\n");
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
		printf("�ɹ���ѯ�м�ڵ㣬ֵΪ:%d\n",min->data);
	}
}

void fun0(){
	DestroyList(&head);
}
