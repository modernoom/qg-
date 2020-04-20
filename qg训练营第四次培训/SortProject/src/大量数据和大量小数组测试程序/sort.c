#include<math.h>
#include<stdlib.h> 
#include "../../inc/qgsort.h"
#include "../../inc/LinkStack.h"


/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int* a, int n) {
	int i, k, p, mid, temp;
	for (i = 1; i < n; i++) {
		temp = a[i];
		//二分查找插入位置 
		int left = 0;
		int right = i - 1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (temp >= a[mid]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		//k为应插入位置 
		if (temp >= a[mid]) {
			k = left;
		}
		else {
			k = mid;
		}
		//将k之前的数向前移动一位 
		for (p = i; p > k; p--) {
			a[p] = a[p - 1];
		}
		//将数字插入k 
		a[k] = temp;
	}
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int* a, int begin, int mid, int end, int* temp) {
	int l = begin;
	int r = mid + 1;
	int lend = mid;
	int rend = end;
	int i = begin;//temp指针 
	while (l <= lend && r <= rend) {
		if (a[l] <= a[r]) {
			temp[i++] = a[l++];
		}
		else {
			temp[i++] = a[r++];
		}
	}
	while (l <= lend) {
		temp[i++] = a[l++];
	}
	while (r <= rend) {
		temp[i++] = a[r++];
	}
	int j = begin;
	for (; j <= end; j++) {
		a[j] = temp[j];
	}
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int* a, int begin, int end, int* temp) {
	if (begin < end) {
		int mid = (end + begin) / 2;
		//递归排序左边 
		MergeSort(a, begin, mid, temp);
		//递归排序右边 
		MergeSort(a, mid + 1, end, temp);
		//归并
		MergeArray(a, begin, mid, end, temp);
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int* a, int begin, int end) {
	//枢轴 
	int i;
	if (begin < end) {
		i = Partition(a, begin, end);
		//递归执行枢轴左右两边 
		QuickSort_Recursion(a, begin, i - 1);
		QuickSort_Recursion(a, i + 1, end);
	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组大小size
 */
void QuickSort(int* a, int size) {
	//初始化一个空栈，存放一些 begin,end区域 
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(s);
	int i;
	//数组只有一个或没有元素，无需排序 
	if (size <= 1) {
		return;
	}
	int begin = 0;
	int end = size - 1;
	pushLStack(s, end);
	pushLStack(s, begin);
	while (!(isEmptyLStack(s))) {
		popLStack(s, &begin);
		popLStack(s, &end);
		//已是单个元素 
		if (!(begin < end)) {
			continue;
		}
		//执行枢轴函数 
		i = Partition(a, begin, end);
		//将分割的两个区域入栈
		pushLStack(s, i - 1);
		pushLStack(s, begin);
		pushLStack(s, end);
		pushLStack(s, i + 1);
	}
	destroyLStack(s);
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a,数组起点gebin,数组终点end
 */
int Partition(int* a, int begin, int end) {
	if (begin == end) {
		return begin;
	}
	//取最后一个元素为枢轴 
	int prt = a[end];
	//慢指针 
	int i = begin - 1;
	//快指针 
	int j = begin;
	int temp;
	for (; j < end; j++) {
		if (a[j] < prt) {
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	i++;
	temp = a[end];
	a[end] = a[i];
	a[i] = temp;
	//返回枢轴位置 
	return i;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int* a, int size, int max) {
	int i;
	//创建桶数组 
	int* bucket = (int*)malloc(sizeof(int) * max + 1);
	//初始化为0 
	for (i = 0; i < max + 1; i++) {
		bucket[i] = 0;
	}
	//收集
	for (i = 0; i < size; i++) {
		bucket[a[i]]++;
	}
	//统计
	for (i = 1; i < max + 1; i++) {
		bucket[i] += bucket[i - 1];
	}
	//分配
	int* temp = (int*)malloc(sizeof(int) * size);
	for (i = size - 1; i >= 0; i--) {
		temp[--bucket[a[i]]] = a[i];
	}
	for (i = 0; i < size; i++) {
		a[i] = temp[i];
	}
	free(bucket);
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int* a, int size) {
	//找最高位数 
	int max;
	int i, j;
	for (i = 0, max = 0; i < size; i++) {
		if (a[i] > a[max])	max = i;
	}
	int maxNum = a[max];
	int maxDigit = 0;//最高位
	maxNum /= 10;
	while (maxNum > 0) {
		maxDigit++;
		maxNum /= 10;
	}

	//桶 
	int* bucket = (int*)malloc(sizeof(int) * 10);
	//初始化桶
	for (i = 0; i < 10; i++) {
		bucket[i] = 0;
	}
	//临时数组 
	int* temp = (int*)malloc(sizeof(int) * size);
	int dev;
	for (i = 0; i <= maxDigit; i++) {
		dev = pow(10, i);
		//入桶 
		for (j = 0; j < size; j++) {
			//第i位大小 
			int num = (a[j] / dev) % 10;
			bucket[num]++;
		}
		//统计
		for (j = 1; j < 10; j++) {
			bucket[j] += bucket[j - 1];
		}
		//取到临时数组
		for (j = size - 1; j >= 0; j--) {
			int num = (a[j] / dev) % 10;
			temp[--bucket[num]] = a[j];
		}
		//拷贝回原数组
		for (j = 0; j < size; j++) a[j] = temp[j];
		//清空桶 
		for (j = 0; j < 10; j++) {
			bucket[j] = 0;
		}
	}
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int* a, int size) {
	int p0 = -1;
	int p1;
	int p2 = size;
	while (a[p0 + 1] == 0) p0++;
	while (a[p2 - 1] == 2) p2--;
	p1 = p0 + 1;
	int temp;
	while (p1 < p2) {
		if (a[p1] == 2) {
			temp = a[p1];
			a[p1] = a[--p2];
			a[p2] = temp;
		}
		if (a[p1] == 0) {
			temp = a[p1];
			a[p1] = a[++p0];
			a[p0] = temp;
		}
		p1++;
	}
}


/**
 *  @name        : findMinK
 *  @description : 在一个无序序列中找到第K小的数
 *  @param       : 数组指针a,第k小,数组大小size
 */
int findMinK(int* a, int size, int k) {
	int begin = 0;
	int end = size - 1;
	int i = Partition(a, begin, end);
	while (i != k - 1) {
		if (i > k - 1) {
			end = i - 1;
			i = Partition(a, begin, end);
		}
		else {
			begin = i + 1;
			i = Partition(a, begin, end);
		}
	}
	return a[i];
}

/**
 *  @name        : findMaxK
 *  @description : 在一个无序序列中找到第K大的数
 *  @param       : 数组指针a，k,数组大小size
 */
int findMaxK(int* a, int size, int k) {
	int begin = 0;
	int end = size - 1;
	int i = Partition(a, begin, end);
	while (i != size - k) {
		if (i > size - k) {
			end = i - 1;
			i = Partition(a, begin, end);
		}
		else {
			begin = i + 1;
			i = Partition(a, begin, end);
		}
	}
	return a[i];
}
