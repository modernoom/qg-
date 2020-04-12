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
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
  *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Q->front=Q->rear=NULL;
	Q->length=0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	if(IsEmptyLQueue(Q)){
		printf("��ȡʧ�ܣ�����Ϊ��\n");
		return FALSE;
	}
	memcpy(e,Q->front->data,dataSize);
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if(IsEmptyLQueue(Q)){
		printf("����ʧ�ܣ�����Ϊ��\n");
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	if(IsEmptyLQueue(Q)){
		printf("����ʧ�ܣ�����Ϊ��\n");
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
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q){
	//�ж��û��洢����������   1.����   2.С��   3. �ַ��� 
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
