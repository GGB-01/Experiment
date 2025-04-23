package com.study1.BinarySearch;
//二分搜索
public class BinarySearch {
    public static int binarySearch(int[] a, int x) {
        int left = 0;
        int right = a.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] a = {1,1,2,3,4,5,6,7,7,8,9,10};
        int x = 3;
        int result = binarySearch(a, x);
        if (result != -1) {
            System.out.println("元素 " + x + " 在数组中的索引是: " + result);
        } else {
            System.out.println("元素 " + x + " 不在数组中");
        }
    }
}