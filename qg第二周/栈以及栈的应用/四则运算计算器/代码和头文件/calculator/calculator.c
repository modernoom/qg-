#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include "../head/LinkStack.h"

#define maxSize 100
LinkStack stack;
void menu();
int isLeft(char i);
int isDigit(char i);
int isSymbol(char i);
int isRight(char i );
int isIllegal(char i);
int compare(char a,char b);
int isAMMD(char i);
int isAM(char i);
int isMD(char i);
int priority(char i);
int isLegalExp(char exp[maxSize]);
void fun1();

int main(){
		while(1){
		menu();
		char code=getch();
		switch(code){
			case '1':{
				fun1();
				break;
			}
		}
		system("pause");
		system("cls");
	} 
}

void menu(){
	printf("\t\t==========================================\n");
	printf("\t\t==            ���������ϵͳ           ==\n");
	printf("\t\t==========================================\n"); 
	printf("\t\t**********       1. ����        **********\n");
}

void fun1(){
	
	printf("��������׺����ʽ:\n");
	char exp1[maxSize];//��׺ 
	gets(exp1);
	while(isLegalExp(exp1)==0){
		printf("������������������\n");
		gets(exp1);
	}
	if(!initLStack(&stack)){
		return;
	}
	ElemType exp2[maxSize];
	int i=0,j=0;
	int num=0;
	printf("�沨��ʽ��");
	//��׺ת�沨�� 
	if(exp1[0]=='+'||exp1[0]=='-'){
		i++; //�Է��ſ�ͷ ��ѹջʱ���Է��� 
	}
	while(exp1[i]!='\0'||isEmptyLStack(&stack)!=1){
		//������ 
		if(isDigit(exp1[i])){
			num=10*num+(exp1[i]-48);
			printf("%c",exp1[i++]);
			if(!isDigit(exp1[i])){
				exp2[j++]=num;
				num=0;
				printf(" ");
			}
			continue;
		}
		//�������ţ���ջ 
		if(isLeft(exp1[i])){
			pushLStack(&stack,exp1[i++]);
			continue;
		}
		//��������
		if(isRight(exp1[i])){
			ElemType b;
			ElemType topElem;
			getTopLStack(&stack,&topElem);//ջ��Ԫ��
			//ѭ����ջ��Ϊ������ 
			while(!isLeft(topElem)){
				popLStack(&stack,&b);
				exp2[j++]=b;
				printf("%c",b);
				getTopLStack(&stack,&topElem);
			}
			popLStack(&stack,&topElem);
			i++;
			continue;
		}
		 
		//������� 
		if(isAMMD(exp1[i])){
			//ջΪ�� ֱ����ջ 
			if(isEmptyLStack(&stack)){
				pushLStack(&stack,exp1[i++]);
				continue;
			}
			ElemType topElem;
			getTopLStack(&stack,&topElem);
			//���ȼ�����ջ��Ԫ�� ��ջ��Ϊ������ 
			if(compare(exp1[i],topElem)>0||isLeft(topElem)==1){
				pushLStack(&stack,exp1[i++]);
				continue;
			}else{
				ElemType b;
				//ѭ����ջΪ�ջ������������Ż��ߵ�ǰ���ȼ�����ջ�����ȼ� 
				while(isEmptyLStack(&stack)==0&&isLeft(topElem)==0&&compare(exp1[i],topElem)<=0){
					popLStack(&stack,&b);
					exp2[j++]=b;
					printf("%c",b);
					getTopLStack(&stack,&topElem);
				}
				pushLStack(&stack,exp1[i++]);
				continue;
			}
			
		}
		ElemType b;
		//��ʣ�µ�ȫ���׳� 
		while(!isEmptyLStack(&stack)){
			popLStack(&stack,&b);
			exp2[j++]=b;
			printf("%c",b);
		}
		printf("\n");
	}
	if(exp1[0]=='-'){
		exp2[0]*=-1;
	}
	clearLStack(&stack);
	//���沨�����м��� 
	printf("��������");
	int k;
	ElemType num1,num2,num3;
	for(k=0;k<j;k++){
		//�� + - * / ����� 
		if(isAMMD(exp2[k])){
			popLStack(&stack,&num1);
			popLStack(&stack,&num2);
			switch(exp2[k]){
				case '+':{
					num3=num2+num1;
					break;
				}
				case '-':{
					num3=num2-num1;
					break;
				}
				case '*':{
					num3=num2*num1;
					break;
				}
				case '/':{
					if(num1==0){
						printf("������Ϊ0��������󣡣�\n");
						return;
					}
					num3=num2/num1;
					break;
				}
			}
			pushLStack(&stack,num3);//���ѹջ 
		}else{//������ ,ֱ��ѹջ 
			pushLStack(&stack,exp2[k]);
		}
	}
	//������  
	int result;
	popLStack(&stack,&result);
	printf("  %d\n",result);	
	
}

//�Ƿ����� 
int isDigit(char i){
	return (i>='0'&&i<='9');
}

//�Ƿ������ 
int isSymbol(char i){
	return (i=='+'||i=='-'||i=='*'||i=='/'||i=='(');
}
//�Ƿ� + -
int isAM(char i){
	return (i=='+'||i=='-');
} 
//�Ƿ� * / 
int isMD(char i){
	return (i=='*'||i=='/');
}
//�Ƿ� + - * /
int isAMMD(char i){
	return (i=='+'||i=='-'||i=='*'||i=='/');
} 

//�Ƿ�������
int isLeft(char i){
	return i=='(';
} 
//�Ƿ�������
int isRight(char i){
	return i==')';
}
//�Ƿ��ǲ��ͷ��ַ�
int isIllegal(char i){
	return !(isDigit(i)||isSymbol(i)||isRight(i));
} 

//��������ȼ� 
int priority(char symbol){
	if(symbol=='+'||symbol=='-') return 1;
	if(symbol=='*'||symbol=='/') return 2;

}
//�Ƚ����ȼ�  ������a��b��  0�����ȼ���ͬ  ������a��b�� 
int compare(char a,char b){
	return (priority(a)-priority(b));
}


//��׺���ʽ�Ƿ�Ϸ� 
int isLegalExp(char exp[maxSize] ){
	int i=0;
	//���ʽΪ�� 
	if(exp[i]=='\0'){
		return 0;
	}
	//���ʽ���� + - ���� �� �����ſ�ͷ 
	if(!(isDigit(exp[i])||isAM(exp[i])||isLeft(exp[i]))){
		return 0;
	}
	int len=0;
	int isnewdigit=0;
	for(;exp[i]!='\0';i++){
		if(isIllegal(exp[i])){
			return 0;
		}
		if(isLeft(exp[i])){
			if(i==0){
				if(isDigit(exp[i+1])==0&&isLeft(exp[i+1])==0&&isAM(exp[i+1])==0){
						return 0;
				}
			}else if(exp[i+1]=='\0'){
				return 0;
			}else if(isDigit(exp[i-1])==1||isRight(exp[i+1])==1||isMD(exp[i+1])==1||isRight(exp[i-1])==1){
				return 0;
			}
			len++;
			continue;
		}
		if(isRight(exp[i])){
			if(exp[i+1]=='\0'){
				if(isAMMD(exp[i-1])==1||isLeft(exp[i-1])==1){
						return 0;
				}
			}else if(isDigit(exp[i+1])==1||isLeft(exp[i+1])==1||isAMMD(exp[i-1])==1||isLeft(exp[i-1])==1){
				return 0;
			}
			len--;
			continue;
		}
		if(isDigit(exp[i])){
			if(isDigit(exp[i+1])){
				continue;
			}else if(i==0){
				if(isLeft(exp[i+1])==1){
					return 0;
				}
			}else if(exp[i+1]=='\0'){
				if(isRight(exp[i-1])){
					return 0;
				}
			}else if(isLeft(exp[i+1])==1||isRight(exp[i-1])==1){
				return 0;
			}
			continue;
		}
		
		if(isAM(exp[i])){
			if(i==0){
				if(isRight(exp[i+1])==1||isAMMD(i+1)==1){
					return 0;
				}
			}else if(exp[i+1]=='\0'){
					return 0;
			}else if(isRight(exp[i+1])==1||isAMMD(exp[i-1])==1||isAMMD(exp[i+1])==1){
				return 0;
			}
			continue;
		}
		
		if(isMD(exp[i])){
			if(i==0||exp[i+1]=='\0'){
				return 0;
			}else if(isAMMD(exp[i-1])==1||isAMMD(exp[i+1])==1||isRight(exp[i+1])==1||isLeft(exp[i-1])==1){
				return 0;
			}
			continue;
		}
		
	}
	
	return (len==0);
}















