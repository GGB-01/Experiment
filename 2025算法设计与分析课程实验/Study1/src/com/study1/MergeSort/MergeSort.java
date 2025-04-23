package com.study1.MergeSort;
//合并排序
public class MergeSort {
    public static void mergeSort(int[] a) {
        if (a == null || a.length <= 1) {
            return;
        }
        int[] temp = new int[a.length];
        mergeSort(a, 0, a.length - 1, temp);
    }

    private static void mergeSort(int[] a, int left, int right, int[] temp) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(a, left, mid, temp);
            mergeSort(a, mid + 1, right, temp);
            merge(a, left, mid, right, temp);
        }
    }

    private static void merge(int[] a, int left, int mid, int right, int[] temp) {
        int i = left;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= right) {
            if (a[i] <= a[j]) {
                temp[k++] = a[i++];
            } else {
                temp[k++] = a[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = a[i++];
        }
        while (j <= right) {
            temp[k++] = a[j++];
        }
        k = 0;
        while (left <= right) {
            a[left++] = temp[k++];
        }
    }

    public static void main(String[] args) {
        int[] a = {5, 3, 8, 4, 2, 7, 1, 6};
        mergeSort(a);
        for (int num : a) {
            System.out.print(num + " ");
        }
    }
}