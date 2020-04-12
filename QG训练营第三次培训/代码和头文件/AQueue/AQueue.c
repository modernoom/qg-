#include<stdlib.h>
#include<string.h> 
#include<stdio.h>
#include"../head/AQueue.h"


#define dataSize 17
#define stringSize 100
#define INTEGER 'i'
#define FLOAT 'f'
#define STRING 's'
char type;

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q){
	int i;
	for(i=0;i<MAXQUEUE;i++){
		*(Q->data+i)=malloc(dataSize);
	}
	Q->length=0;
	Q->front=0;
	Q->rear=0;
} 


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q){
	int i;
	for(i=0;i<MAXQUEUE;i++){
		free(Q->data[i]);
	}
	free(Q);
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
	//如果rear的下一个位置为空则判断为满，牺牲了一个容量 
	if((Q->rear+1)%MAXQUEUE==Q->front){
		return TRUE;
	}
	return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
	if(Q->front==Q->rear){
		return TRUE;
	}
	return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e){
	if(IsEmptyAQueue(Q)){
		printf("获取失败，队列为空\n");
		return FALSE;
	}
	memcpy(e,Q->data[Q->front],dataSize);
	return TRUE;
}	



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
	return Q->length;
} 



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data){
	if(IsFullAQueue(Q)){
		printf("入队失败，队列为满\n");
		return FALSE;
	}
	memcpy(Q->data[Q->rear],data,dataSize);
	Q->rear=(Q->rear+1)%MAXQUEUE;
	Q->length++;
	return TRUE;
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
	if(IsEmptyAQueue(Q)){
		printf("出队失败，队列为空\n");
		return FALSE;
	}
	Q->front=(Q->front+1)%MAXQUEUE;
	Q->length--;
	return TRUE;
}	



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
	if(IsEmptyAQueue(Q)){
		return;
	}
	Q->front=Q->rear;
	Q->length=0;
}	



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
	if(IsEmptyAQueue(Q)){
		printf("遍历失败，队列为空\n");
		return FALSE;
	}
	int i=Q->front;
	for(;i!=Q->rear;i=(i+1)%MAXQUEUE){
		foo(Q->data[i]);
	}
	return TRUE;
}



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q){
	//判断用户存储的数据类型   1.整数   2.小数   3. 字符串 
	if(type==INTEGER){
		long long *temp=(long long*)q;
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
