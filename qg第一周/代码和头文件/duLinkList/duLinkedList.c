#include<stdio.h>
#include<stdlib.h>
#include "../head/duLinkedList.h"

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	DuLNode* head=(DuLNode*)malloc(sizeof(DuLNode));
	if(head==NULL){
		printf("初始化失败，空间不足\n");
		return 0;
	}
	head->next=NULL;
	head->prior=NULL;
	*L=head;
	printf("链表初始化成功\n");
	return 1;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLNode* head=*L;
		if(head==NULL){
			printf("链表尚未初始化\n");
			return; 
		}
		DuLNode* p=NULL;
		while(head->next!=NULL){
			p=head->next;
			head->next=head->next->next;
			free(p);
		}
		free(head);
		*L=NULL;
		printf("链表销毁成功\n");
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if(p==NULL||q==NULL){
		return 0;
	}
	if(p->prior==NULL){
		p->prior=q;
		q->next=p;
		q->prior=NULL;
		printf("插入成功\n");
		return 1;
	}
	DuLNode*t=p->prior;
	q->next=p;
	p->prior=q;
	q->prior=t;
	t->next=q;
	printf("插入成功\n");
	return 1;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if(p==NULL||q==NULL){
		return 0;
	}
	if(p->next==NULL){
		q->next=NULL;
		q->prior=NULL;
		p->next=q;
		printf("插入成功\n");
		return 1;
	}
	DuLNode* t=p->next;
	p->next=q;
	q->prior=p;
	q->next=t;
	t->prior=q;
	printf("插入成功\n");
	return 1;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	 if(p==NULL||p->next==NULL){
	 	printf("链表为空\n");
		return 0;
	 }
	 if(p->next==NULL){
		printf("节点后面为空\n");	 	
	 	return 0;
	 }
	 DuLNode*temp=p->next;
	 if(p->next->next==NULL){
	 		p->next=NULL;
	 		*e=temp->data;
			
			free(temp);
	 		return 1; 
	 }
	 p->next=temp->next;
	 temp->next->prior=p;
   	 free(temp);
   	 return 1;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	if(L==NULL){
		printf("链表尚未初始化\n");
		return;
	}
	if(L->next==NULL){
		printf("链表为空\n");
	}
	DuLNode* p=L->next;
	while(p){
		visit(p->data);
		if(p->next==NULL){
			printf("-->null\n");
		}else{
			printf("-->");
		}
		p=p->next;
	}
}
