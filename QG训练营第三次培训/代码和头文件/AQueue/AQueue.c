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
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
	//���rear����һ��λ��Ϊ�����ж�Ϊ����������һ������ 
	if((Q->rear+1)%MAXQUEUE==Q->front){
		return TRUE;
	}
	return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e){
	if(IsEmptyAQueue(Q)){
		printf("��ȡʧ�ܣ�����Ϊ��\n");
		return FALSE;
	}
	memcpy(e,Q->data[Q->front],dataSize);
	return TRUE;
}	



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
	return Q->length;
} 



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data){
	if(IsFullAQueue(Q)){
		printf("���ʧ�ܣ�����Ϊ��\n");
		return FALSE;
	}
	memcpy(Q->data[Q->rear],data,dataSize);
	Q->rear=(Q->rear+1)%MAXQUEUE;
	Q->length++;
	return TRUE;
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
	if(IsEmptyAQueue(Q)){
		printf("����ʧ�ܣ�����Ϊ��\n");
		return FALSE;
	}
	Q->front=(Q->front+1)%MAXQUEUE;
	Q->length--;
	return TRUE;
}	



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
	if(IsEmptyAQueue(Q)){
		printf("����ʧ�ܣ�����Ϊ��\n");
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
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q){
	//�ж��û��洢����������   1.����   2.С��   3. �ַ��� 
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
