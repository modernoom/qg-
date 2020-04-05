#include<stdio.h>
#include<stdlib.h>
#include "../head/SqStack.h"

//���������˳��ջ
int maxSize;
//��ʼ��ջ
Status initStack(SqStack *s,int sizes){
	maxSize=sizes;
	s->elem=(int *)malloc(sizeof(int)*sizes);
	if(s->elem==NULL){
		printf("��ʼ��ʧ�ܣ��ռ䲻��\n");
		return ERROR;
	}
	s->top=-1;
	s->size=0;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack *s){
	return (s->size==0);
}

//�õ�ջ��Ԫ��
Status getTopStack(SqStack *s,ElemType *e){
	if(s->size==0){
		printf("ջΪ��\n");
		return ERROR;
	}
	*e=*(s->elem+s->top);
	return SUCCESS;
}

//���ջ
Status clearStack(SqStack *s){
	s->top=-1;
	s->size=0;
	return SUCCESS;
}

//����ջ
Status destroyStack(SqStack *s){
	free(s->elem);
	free(s);
	return SUCCESS;
}

//���ջ����
Status stackLength(SqStack *s,int *length){
	*length=s->size;
}

//��ջ
Status pushStack(SqStack *s,ElemType data){
	int p=s->top+1;
	if(p>=maxSize){
		printf("ջ����\n");
		return ERROR;
	}
	*(s->elem+p)=data;
	s->top++;
	s->size++;
	return SUCCESS;
}

//��ջ
Status popStack(SqStack *s,ElemType *data){
	if(s->size==0){
		printf("ջΪ��\n");
		return ERROR;
	}
	*data=*(s->elem+s->top);
	s->top--;
	s->size--;	
}

