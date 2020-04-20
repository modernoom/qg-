#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#include<time.h>
#include "../../inc/qgsort.h"

#define MAX 999 
#define BIG_LEVEL1 10000
#define BIG_LEVEL2 50000
#define BIG_LEVEL3 200000
#define SMALLSIZE 100
#define COUNT1 1000
#define COUNT2 10000
#define COUNT3 100000
	
	
void menu();
void dataGenerate(int *a,int size);
void bigTester(int size);
void smallTester(int count);


int main(){
		while(1){
		menu();
		int a;
		fflush(stdin);
		char code=getch();
		switch(code){
			case '1':bigTester(BIG_LEVEL1);break;
			case '2':bigTester(BIG_LEVEL2);break;
			case '3':bigTester(BIG_LEVEL3);break;
			case '4':smallTester(COUNT1);break;
			case '5':smallTester(COUNT2);break;
			case '6':smallTester(COUNT3);break;
		}
		system("pause");
		system("cls");
	} 
	return 0;	
}

void menu(){
	printf("\t\t==========================================\n");
	printf("\t\t==      大数据量和大量小数组测试程序    ==\n");
	printf("\t\t==========================================\n"); 
	printf("\t\t**********     1. 10000    **********\n");
	printf("\t\t**********     2. 50000    **********\n");
	printf("\t\t**********     3. 200000   **********\n");
	printf("\t\t**********     4. 100*1k   **********\n");
	printf("\t\t**********     5. 100*10k  **********\n");
	printf("\t\t**********     6. 100*100k **********\n");
	printf("\t\t==========================================\n");
}
void bigTester(int size){
	int result[5];
	int *a=(int*)malloc(sizeof(int)*size);
	int *temp=(int*)malloc(sizeof(int)*size);
	//test insertSort 
	dataGenerate(a,size);
    clock_t insertStart=clock();
    insertSort(a,size);
    result[0]=clock()-insertStart;
    //test MergeSort
    dataGenerate(a,size);
    clock_t mergeStart=clock();
    MergeSort(a,0,size-1,temp);
    result[1]=clock()-mergeStart;
    //test QuickSort
    dataGenerate(a,size);
    clock_t quickStart=clock();
    QuickSort_Recursion(a,0,size-1);
    result[2]=clock()-quickStart;
    //test CountSort
    dataGenerate(a,size);
    clock_t countStart=clock();
    CountSort(a,size,999);
    result[3]=clock()-countStart;
    //test RadixCountSort(a,5);
    dataGenerate(a,size);
    clock_t radixStart=clock();
    RadixCountSort(a,size);
    result[4]=clock()-radixStart;
	//test done
	printf("test %d level data done\n",size);
	printf("result:\n");
	printf("insertSort time consuming:%dms\n",result[0]);
	printf("MergeSort time consuming:%dms\n",result[1]);
	printf("QuickSort time consuming:%dms\n",result[2]);
	printf("CountSort time consuming:%dms\n",result[3]);
	printf("RadixCountSort time consuming:%dms\n",result[4]);
	free(a);
	free(temp);
}
void smallTester(int count){
	 	int result[5];
        int *a=(int *)malloc(sizeof(int)*SMALLSIZE*count);
      	int* temp=(int*)malloc(sizeof(int)*SMALLSIZE*count);
 		int i;
		dataGenerate(a,SMALLSIZE*count);
        clock_t insertStart=clock();
        for(i=0;i<count;i++){
        insertSort(a+(i*SMALLSIZE),SMALLSIZE);
        }
        result[0]=clock()-insertStart;
        //test MergeSort
        dataGenerate(a,SMALLSIZE*count);
        clock_t mergeStart=clock();
        for(i=0;i<count;i++){
        MergeSort(a+(i*SMALLSIZE),0,SMALLSIZE-1,temp+(i*SMALLSIZE));
        }
        result[1]=clock()-mergeStart;
        //test QuickSort
        dataGenerate(a,SMALLSIZE*count);
        clock_t quickStart=clock();
        for(i=0;i<count;i++){
        QuickSort_Recursion(a+(i*SMALLSIZE),0,SMALLSIZE-1);
        }
        result[2]=clock()-quickStart;
        //test CountSort
        dataGenerate(a,SMALLSIZE);
        clock_t countStart=clock();
        for(i=0;i<count;i++){
        CountSort(a+(i*SMALLSIZE),SMALLSIZE,MAX);
        }
        result[3]=clock()-countStart;
        //test RadixCountSort(a,5);
        dataGenerate(a,SMALLSIZE);
        clock_t radixStart=clock();
        for(i=0;i<count;i++){
        RadixCountSort(a+(i*SMALLSIZE),SMALLSIZE);
        }
        result[4]=clock()-radixStart;
 		//test done
        printf("test %d*%d level data done\n",SMALLSIZE,COUNT1);
        printf("result:\n");
        printf("insertSort time consuming:%dms\n",result[0]);
        printf("MergeSort time consuming:%dms\n",result[1]);
        printf("QuickSort time consuming:%dms\n",result[2]);
        printf("CountSort time consuming:%dms\n",result[3]);
        printf("RadixCountSort time consuming:%dms\n",result[4]);
        free(a);
        free(temp);
}
void dataGenerate(int *a,int size){
	int i;
	for(i=0;i<size;i++){
		//统一生成的数大小范围 0-999
		int num=rand();
		if(num>MAX){
			num%=MAX;
		}
		a[i]=num;
	}
} 
