#include <iostream>
using namespace std;

// 二分查找（迭代）
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // 避免溢出
        
        if (arr[mid] == target) {
            return mid;  // 找到目标值，返回索引
        } else if (arr[mid] < target) {
            left = mid + 1;  // 目标在右半部分
        } else {
            right = mid - 1;  // 目标在左半部分
        }
    }
    
    return -1;  // 未找到目标值
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;
    
    int result = binarySearch(arr, n, target);
    
    if (result != -1) {
        cout << "元素在索引 " << result << " 处找到" << endl;
    } else {
        cout << "元素未找到" << endl;
    }
    
    return 0;
}