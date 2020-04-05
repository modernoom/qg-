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
	printf("\t\t==            四则计算器系统           ==\n");
	printf("\t\t==========================================\n"); 
	printf("\t\t**********       1. 计算        **********\n");
}

void fun1(){
	
	printf("请输入中缀计算式:\n");
	char exp1[maxSize];//中缀 
	gets(exp1);
	while(isLegalExp(exp1)==0){
		printf("算术有误，请重新输入\n");
		gets(exp1);
	}
	if(!initLStack(&stack)){
		return;
	}
	ElemType exp2[maxSize];
	int i=0,j=0;
	int num=0;
	printf("逆波兰式：");
	//中缀转逆波兰 
	if(exp1[0]=='+'||exp1[0]=='-'){
		i++; //以符号开头 ，压栈时忽略符号 
	}
	while(exp1[i]!='\0'||isEmptyLStack(&stack)!=1){
		//是数字 
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
		//是左括号，入栈 
		if(isLeft(exp1[i])){
			pushLStack(&stack,exp1[i++]);
			continue;
		}
		//是右括号
		if(isRight(exp1[i])){
			ElemType b;
			ElemType topElem;
			getTopLStack(&stack,&topElem);//栈顶元素
			//循环到栈顶为左括号 
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
		 
		//是运算符 
		if(isAMMD(exp1[i])){
			//栈为空 直接入栈 
			if(isEmptyLStack(&stack)){
				pushLStack(&stack,exp1[i++]);
				continue;
			}
			ElemType topElem;
			getTopLStack(&stack,&topElem);
			//优先级大于栈顶元素 或栈顶为左括号 
			if(compare(exp1[i],topElem)>0||isLeft(topElem)==1){
				pushLStack(&stack,exp1[i++]);
				continue;
			}else{
				ElemType b;
				//循环到栈为空或者遇到左括号或者当前优先级大于栈顶优先级 
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
		//将剩下的全部抛出 
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
	//对逆波兰进行计算 
	printf("运算结果：");
	int k;
	ElemType num1,num2,num3;
	for(k=0;k<j;k++){
		//是 + - * / 运算符 
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
						printf("被除数为0，运算错误！！\n");
						return;
					}
					num3=num2/num1;
					break;
				}
			}
			pushLStack(&stack,num3);//结果压栈 
		}else{//是数字 ,直接压栈 
			pushLStack(&stack,exp2[k]);
		}
	}
	//输出结果  
	int result;
	popLStack(&stack,&result);
	printf("  %d\n",result);	
	
}

//是否数字 
int isDigit(char i){
	return (i>='0'&&i<='9');
}

//是否运算符 
int isSymbol(char i){
	return (i=='+'||i=='-'||i=='*'||i=='/'||i=='(');
}
//是否 + -
int isAM(char i){
	return (i=='+'||i=='-');
} 
//是否 * / 
int isMD(char i){
	return (i=='*'||i=='/');
}
//是否 + - * /
int isAMMD(char i){
	return (i=='+'||i=='-'||i=='*'||i=='/');
} 

//是否左括号
int isLeft(char i){
	return i=='(';
} 
//是否右括号
int isRight(char i){
	return i==')';
}
//是否是不和法字符
int isIllegal(char i){
	return !(isDigit(i)||isSymbol(i)||isRight(i));
} 

//运算符优先级 
int priority(char symbol){
	if(symbol=='+'||symbol=='-') return 1;
	if(symbol=='*'||symbol=='/') return 2;

}
//比较优先级  正数：a比b高  0：优先级相同  负数：a比b低 
int compare(char a,char b){
	return (priority(a)-priority(b));
}


//中缀表达式是否合法 
int isLegalExp(char exp[maxSize] ){
	int i=0;
	//表达式为空 
	if(exp[i]=='\0'){
		return 0;
	}
	//表达式不以 + - 数字 或 左括号开头 
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















