#include<stdio.h>
#include<stdlib.h>
#include "../head/LinkStack.h"


 
//³õÊ¼»¯Õ»
Status initLStack(LinkStack *s){
	s->count=0;
	s->top=NULL;
	return SUCCESS;
}

//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
Status isEmptyLStack(LinkStack *s){
	return (s->count==0);
}
//µÃµ½Õ»¶¥ÔªËØ
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->count==0){
		printf("Õ»Îª¿Õ\n");
		return ERROR;
	}
	
	*e=s->top->data;
	return SUCCESS;		
}

//Çå¿ÕÕ»
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

//Ïú»ÙÕ»
Status destroyLStack(LinkStack *s){
	Status status=clearLStack(s);	
	if(status==ERROR){
		return ERROR;
	}
	free(s);
	return SUCCESS;
}
//¼ì²âÕ»³¤¶È
Status LStackLength(LinkStack *s,int *length){
	*length=s->count;
	return SUCCESS;
}
//ÈëÕ»
Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
	if(p==NULL){
		printf("pushÊ§°Ü£¬¿Õ¼ä²»×ã\n");
		return ERROR;
	}
	p->data=data;
	p->next=s->top;
	s->top=p;
	s->count++;
	return SUCCESS;
}

//³öÕ»
Status popLStack(LinkStack *s,ElemType *data){
	if(s->top==NULL){
		printf("popÊ§°Ü£¬Õ»Îª¿Õ\n");
		return ERROR;
	}
	*data=s->top->data;
	LinkStackPtr p=s->top;
	s->top=s->top->next;
	s->count--;
	free(p);
	return SUCCESS;
}
