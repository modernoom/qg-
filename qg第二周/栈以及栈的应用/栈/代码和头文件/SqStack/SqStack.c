#include<stdio.h>
#include<stdlib.h>
#include "../head/SqStack.h"

//基于数组的顺序栈
int maxSize;
//初始化栈
Status initStack(SqStack *s,int sizes){
	maxSize=sizes;
	s->elem=(int *)malloc(sizeof(int)*sizes);
	if(s->elem==NULL){
		printf("初始化失败，空间不足\n");
		return ERROR;
	}
	s->top=-1;
	s->size=0;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyStack(SqStack *s){
	return (s->size==0);
}

//得到栈顶元素
Status getTopStack(SqStack *s,ElemType *e){
	if(s->size==0){
		printf("栈为空\n");
		return ERROR;
	}
	*e=*(s->elem+s->top);
	return SUCCESS;
}

//清空栈
Status clearStack(SqStack *s){
	s->top=-1;
	s->size=0;
	return SUCCESS;
}

//销毁栈
Status destroyStack(SqStack *s){
	free(s->elem);
	free(s);
	return SUCCESS;
}

//检测栈长度
Status stackLength(SqStack *s,int *length){
	*length=s->size;
}

//入栈
Status pushStack(SqStack *s,ElemType data){
	int p=s->top+1;
	if(p>=maxSize){
		printf("栈已满\n");
		return ERROR;
	}
	*(s->elem+p)=data;
	s->top++;
	s->size++;
	return SUCCESS;
}

//出栈
Status popStack(SqStack *s,ElemType *data){
	if(s->size==0){
		printf("栈为空\n");
		return ERROR;
	}
	*data=*(s->elem+s->top);
	s->top--;
	s->size--;	
}

