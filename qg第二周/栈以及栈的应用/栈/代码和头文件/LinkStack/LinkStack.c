#include<stdio.h>
#include<stdlib.h>
#include "../head/LinkStack.h"


 
//��ʼ��ջ
Status initLStack(LinkStack *s){
	s->count=0;
	s->top=NULL;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	return (s->count==0);
}
//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->count==0){
		printf("ջΪ��\n");
		return ERROR;
	}
	
	*e=s->top->data;
	return SUCCESS;		
}

//���ջ
Status clearLStack(LinkStack *s){
	
	LinkStackPtr p=s->top;
	while(p){
		s->top=p->next;
		free(p);
		p=s->top;	
	}
	s->top=NULL;
	s->count=0;
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s){
	Status status=clearLStack(s);	
	if(status==ERROR){
		return ERROR;
	}
	free(s);
	return SUCCESS;
}
//���ջ����
Status LStackLength(LinkStack *s,int *length){
	*length=s->count;
	return SUCCESS;
}
//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
	if(p==NULL){
		printf("pushʧ�ܣ��ռ䲻��\n");
		return ERROR;
	}
	p->data=data;
	p->next=s->top;
	s->top=p;
	s->count++;
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	if(s->top==NULL){
		printf("popʧ�ܣ�ջΪ��\n");
		return ERROR;
	}
	*data=s->top->data;
	LinkStackPtr p=s->top;
	s->top=s->top->next;
	s->count--;
	free(p);
	return SUCCESS;
}
