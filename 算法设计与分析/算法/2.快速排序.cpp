#include <iostream>
using namespace std;

// 交换两个元素的值
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 分区函数，选择最后一个元素作为基准
int partition(int a[], int leftside, int rightside) {
    int pivot = a[rightside];  // 选择最后一个元素作为基准
    int i = leftside - 1;      // 小于基准的元素的右边界

    // 遍历数组，将小于等于基准的元素交换到左边
    for (int j = leftside; j < rightside; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    // 将基准元素放到正确的位置
    swap(a[i + 1], a[rightside]);
    return i + 1;  // 返回基准元素的索引
}

// 快速排序主函数
void QuickSort(int a[], int leftside, int rightside) {
    if (leftside >= rightside) {
        return;  // 终止条件：子数组长度小于等于1
    }

    // 分区操作，获取基准元素的位置
    int pivotIndex = partition(a, leftside, rightside);

    // 递归排序基准元素左右两侧的子数组
    QuickSort(a, leftside, pivotIndex - 1);    // 左侧子数组
    QuickSort(a, pivotIndex + 1, rightside);   // 右侧子数组
}

int main() {
    int a[10] = {1,4,7,2,5,8,3,6,9,0};
    QuickSort(a, 0, 9);
    
    // 输出排序结果
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}