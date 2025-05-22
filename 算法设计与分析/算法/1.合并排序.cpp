//合并排序
#include <iostream>
using namespace std;

void MergeSort(int a[], int leftside, int rightside) {
	if (leftside >= rightside) { // 修正终止条件，处理空数组或单元素数组
		return;
	}
	int mid = (leftside + rightside) / 2;
	MergeSort(a, leftside, mid);    // 左子集排序
	MergeSort(a, mid + 1, rightside); // 右子集排序
	Merge(a, leftside, mid, mid + 1, rightside); // 修正合并函数调用
}

void Merge(int a[], int leftStart, int leftEnd, int rightStart, int rightEnd) {
    int size = rightEnd - leftStart + 1;
    int* temp = new int[size]; // 临时数组存储合并结果
    int left = leftStart;      // 左半部分当前索引
    int right = rightStart;    // 右半部分当前索引
    int tempIndex = 0;         // 临时数组当前索引

    // 比较左右两部分元素，按顺序存入临时数组
    while (left <= leftEnd && right <= rightEnd) {
        if (a[left] <= a[right]) {
            temp[tempIndex++] = a[left++];
        } else {
            temp[tempIndex++] = a[right++];
        }
    }

    // 将左半部分剩余元素复制到临时数组
    while (left <= leftEnd) {
        temp[tempIndex++] = a[left++];
    }

    // 将右半部分剩余元素复制到临时数组
    while (right <= rightEnd) {
        temp[tempIndex++] = a[right++];
    }

    // 将临时数组的内容复制回原数组
    for (int i = 0; i < size; i++) {
        a[leftStart + i] = temp[i];
    }

    delete[] temp; // 释放临时数组内存
}

int main() {   //0 1 2 3 4 5 6 7 8 9
	int a[10] = {1,4,7,2,5,8,3,6,9,0};
	MergeSort(a,0,9);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " "; // 修改为输出到同一行，更美观
	}
	return 0;
}