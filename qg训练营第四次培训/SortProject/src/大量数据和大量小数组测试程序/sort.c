#include<math.h>
#include<stdlib.h> 
#include "../../inc/qgsort.h"
#include "../../inc/LinkStack.h"


/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int* a, int n) {
	int i, k, p, mid, temp;
	for (i = 1; i < n; i++) {
		temp = a[i];
		//���ֲ��Ҳ���λ�� 
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
		//kΪӦ����λ�� 
		if (temp >= a[mid]) {
			k = left;
		}
		else {
			k = mid;
		}
		//��k֮ǰ������ǰ�ƶ�һλ 
		for (p = i; p > k; p--) {
			a[p] = a[p - 1];
		}
		//�����ֲ���k 
		a[k] = temp;
	}
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int* a, int begin, int mid, int end, int* temp) {
	int l = begin;
	int r = mid + 1;
	int lend = mid;
	int rend = end;
	int i = begin;//tempָ�� 
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
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int* a, int begin, int end, int* temp) {
	if (begin < end) {
		int mid = (end + begin) / 2;
		//�ݹ�������� 
		MergeSort(a, begin, mid, temp);
		//�ݹ������ұ� 
		MergeSort(a, mid + 1, end, temp);
		//�鲢
		MergeArray(a, begin, mid, end, temp);
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int* a, int begin, int end) {
	//���� 
	int i;
	if (begin < end) {
		i = Partition(a, begin, end);
		//�ݹ�ִ�������������� 
		QuickSort_Recursion(a, begin, i - 1);
		QuickSort_Recursion(a, i + 1, end);
	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�������Сsize
 */
void QuickSort(int* a, int size) {
	//��ʼ��һ����ջ�����һЩ begin,end���� 
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(s);
	int i;
	//����ֻ��һ����û��Ԫ�أ��������� 
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
		//���ǵ���Ԫ�� 
		if (!(begin < end)) {
			continue;
		}
		//ִ�����ắ�� 
		i = Partition(a, begin, end);
		//���ָ������������ջ
		pushLStack(s, i - 1);
		pushLStack(s, begin);
		pushLStack(s, end);
		pushLStack(s, i + 1);
	}
	destroyLStack(s);
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a,�������gebin,�����յ�end
 */
int Partition(int* a, int begin, int end) {
	if (begin == end) {
		return begin;
	}
	//ȡ���һ��Ԫ��Ϊ���� 
	int prt = a[end];
	//��ָ�� 
	int i = begin - 1;
	//��ָ�� 
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
	//��������λ�� 
	return i;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int* a, int size, int max) {
	int i;
	//����Ͱ���� 
	int* bucket = (int*)malloc(sizeof(int) * max + 1);
	//��ʼ��Ϊ0 
	for (i = 0; i < max + 1; i++) {
		bucket[i] = 0;
	}
	//�ռ�
	for (i = 0; i < size; i++) {
		bucket[a[i]]++;
	}
	//ͳ��
	for (i = 1; i < max + 1; i++) {
		bucket[i] += bucket[i - 1];
	}
	//����
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
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int* a, int size) {
	//�����λ�� 
	int max;
	int i, j;
	for (i = 0, max = 0; i < size; i++) {
		if (a[i] > a[max])	max = i;
	}
	int maxNum = a[max];
	int maxDigit = 0;//���λ
	maxNum /= 10;
	while (maxNum > 0) {
		maxDigit++;
		maxNum /= 10;
	}

	//Ͱ 
	int* bucket = (int*)malloc(sizeof(int) * 10);
	//��ʼ��Ͱ
	for (i = 0; i < 10; i++) {
		bucket[i] = 0;
	}
	//��ʱ���� 
	int* temp = (int*)malloc(sizeof(int) * size);
	int dev;
	for (i = 0; i <= maxDigit; i++) {
		dev = pow(10, i);
		//��Ͱ 
		for (j = 0; j < size; j++) {
			//��iλ��С 
			int num = (a[j] / dev) % 10;
			bucket[num]++;
		}
		//ͳ��
		for (j = 1; j < 10; j++) {
			bucket[j] += bucket[j - 1];
		}
		//ȡ����ʱ����
		for (j = size - 1; j >= 0; j--) {
			int num = (a[j] / dev) % 10;
			temp[--bucket[num]] = a[j];
		}
		//������ԭ����
		for (j = 0; j < size; j++) a[j] = temp[j];
		//���Ͱ 
		for (j = 0; j < 10; j++) {
			bucket[j] = 0;
		}
	}
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
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
 *  @description : ��һ�������������ҵ���KС����
 *  @param       : ����ָ��a,��kС,�����Сsize
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
 *  @description : ��һ�������������ҵ���K�����
 *  @param       : ����ָ��a��k,�����Сsize
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
