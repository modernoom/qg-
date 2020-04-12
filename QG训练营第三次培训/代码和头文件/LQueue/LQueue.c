#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"../head/LQueue.h"

#define dataSize 17 
#define INTEGER 'i'
#define FLOAT 'f'
#define STRING 's'
char type;
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
  *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Q->front=Q->rear=NULL;
	Q->length=0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	Node*p=Q->front;
	Node*tem=p;
	while(p){
		p=p->next;
		free(tem);
		tem=p;
	}
	free(Q);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->length==0){
		return TRUE;
	}
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	if(IsEmptyLQueue(Q)){
		printf("获取失败，队列为空\n");
		return FALSE;
	}
	memcpy(e,Q->front->data,dataSize);
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
	Node*p=(Node*)malloc(sizeof(Node));
	p->data=malloc(dataSize); 
	p->next=NULL;
	memcpy(p->data,data,dataSize);
	if(IsEmptyLQueue(Q)){
		Q->rear=p;
		Q->front=p;
	}else{
		Q->rear->next=p;
		Q->rear=p;
	}
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if(IsEmptyLQueue(Q)){
		printf("出队失败，队列为空\n");
		return FALSE;
	}
	if(Q->front==Q->rear){
		free(Q->front);
		Q->front=Q->rear=NULL;
	}else{
		Node*p=Q->front;
		Q->front=Q->front->next;
		free(p->data);
		free(p);
	}
	Q->length--;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	Node*p=Q->front;
	Node*tem=p;
	while(p){
		p=p->next;
		free(tem);
		tem=p;
	}
	Q->length=0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	if(IsEmptyLQueue(Q)){
		printf("遍历失败，队列为空\n");
		return FALSE;
	}
	Node*p=Q->front;
	while(p){
		foo(p->data);
		p=p->next;
	}
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q){
	//判断用户存储的数据类型   1.整数   2.小数   3. 字符串 
	if(type==INTEGER){
		int *temp=(int*)q;
		printf("%d ",*temp);
	}
	if(type==FLOAT){
		double *temp=(double*)q;
		printf("%f ",*temp);
	}
	if(type==STRING){
		char **temp=(char**)q;
		printf("%s ",*temp);
	}

}
