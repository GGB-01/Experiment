#include <iostream>
using namespace std;

// 合并两个有序子数组
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];

    // 复制数据到临时数组
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 归并临时数组到原数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 复制剩余元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// 无递归合并排序
void mergeSort(int arr[], int n) {
    // 子数组大小从1开始，每次翻倍
    for (int curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        // 遍历所有子数组
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            // 找到中间点
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);

            // 合并子数组
            merge(arr, left_start, mid, right_end);
        }
    }
}

// 辅助函数：打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "排序前的数组: \n";
    printArray(arr, n);

    mergeSort(arr, n);

    cout << "\n排序后的数组: \n";
    printArray(arr, n);

    return 0;
}