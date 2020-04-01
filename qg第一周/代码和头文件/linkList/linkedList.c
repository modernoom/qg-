#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#include<string.h>
#include "../head/linkedList.h"


/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	LNode* head=(LNode*)malloc(sizeof(LNode));
	if(head==NULL){
		printf("初始化失败，空间不足\n");
		return 0;
	}
	head->next=NULL;
	*L=head;
	printf("链表初始化成功\n");
	return 1;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
		LNode* head=*L;
		if(head==NULL){
			printf("链表尚未初始化\n");
			return; 
		}
		LNode* p=NULL;
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
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if(p!=NULL&&q!=NULL){
		q->next=p->next;
		p->next=q;
		printf("插入成功\n");
		return 1;
	}
	printf("插入节点为空\n");
	return 0;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	if(p==NULL){
		printf("链表为空");
		return 0;
	}
	LNode* temp=p->next;
	*e=temp->data;
	p->next=temp->next;
	free(temp);
	return 1;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	if(L==NULL){
		printf("链表尚未初始化！\n");
		return;
	}
	LNode* p=L->next;
	if(p==NULL){
		printf("当前链表为空\n");
	}
	while(p){
		visit(p->data);
		if(p->next!=NULL){
			printf("-->");
		}else{
			printf("-->null");
		}
		p=p->next;
	}
	printf("\n");
	
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	if(L==NULL){
		printf("链表为空\n");
		return 0;
	}
	
	LNode* p=L->next;
	int index=1;
	while(p!=NULL&&p->data!=e){
		p=p->next;
		index++;
	}
	if(p==NULL){
		printf("链表中不存在该节点\n");
		return 0;
	}
	printf("已找到该节点，该节点是链表的第%d个节点\n",index);
	return 1;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	if(*L==NULL){
		printf("链表尚未初始化!\n");
		return 0;
	}
	LNode* head=*L;
	if(head->next==NULL){
		printf("链表为空\n");
		return 1;
	}
	if(head->next->next==NULL){
		printf("链表反转成功\n");
		return 1;
	}
	LNode*p1=head->next;
	LNode*p2=p1->next;
	LNode*p3=p2->next;
	p1->next=NULL;
	while(p2){
		p2->next=p1;
		p1=p2;
		p2=p3;
		if(p2==NULL){
			head->next=p1;
			printf("链表反转成功\n");
			return 1;
		}
		p3=p2->next;
	}
	
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	if(!L){
		printf("链表尚未初始化！\n");
		return 0;
	}
	if(L->next==NULL||L->next->next==NULL){
		printf("链表未成环\n");
		return 1;
	}
	LNode* fast=L;
	LNode* slow=L;
	int flag=0;
	while(fast!=NULL&&fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow){
			flag=1;
			break;
		}
	}
	if(flag){
		printf("链表成环了\n");
	}else{
		printf("链表未成环\n");
	}
	return flag;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	if(*L==NULL){
		printf("链表尚未初始化！\n");
		return NULL;
	}
	LNode* head=*L;
	if(head->next==NULL){
		printf("链表为空\n");
		return head;
	}
	if(head->next->next==NULL){
		printf("操作成功\n");
		return head;
	}
	LNode* p1=(*L)->next;
	LNode* p2=p1->next;
	LNode* t=p1;
	head->next=p2;
	while(p1!=NULL&&p1->next!=NULL){
		p1->next=p2->next;
		p2->next=p1;
		p1=p1->next;
		if(p1==NULL||p1->next==NULL){
			printf("操作成功\n");
			return head;
		}
		t->next=p1->next;
		t=p1;
		p2=p1->next;
	}
	printf("操作成功\n");
	return head;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	if(*L==NULL){
		printf("链表尚未初始化！\n");
		return NULL;
	}
	LNode* head=*L;
	if(head->next==NULL){
		printf("该链表暂时没有数据");
		return NULL;
	}
	LNode* fast=head;
	LNode* slow=head;
	while(fast!=NULL&&fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}







