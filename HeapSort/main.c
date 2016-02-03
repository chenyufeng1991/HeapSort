//
//  main.c
//  Train
//
//  Created by chenyufeng on 16/1/30.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

#include <stdio.h>

void BuildHeap(int *a,int size);
void swap(int *a,int *b);
void HeapSort(int *a,int size);
void HeapAdjust(int *a,int i,int size);

int main(int argc,const char *argv[]){

    int a[] = {3,25,9,30,2};
    HeapSort(a, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ",a[i]);
    }

    return 0;
}

//建立堆
void BuildHeap(int *a,int size){

    for (int i = size - 1; i >= 0; i--) {
        HeapAdjust(a, i, size);
    }

}

//交换两个数
void swap(int *a,int *b){

    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//堆排序
void HeapSort(int *a,int size){

    BuildHeap(a, size);
    for (int i = size - 1; i >= 0; i--) {
        //交换堆顶和最后一个元素，即每次将剩余元素中的最大者放到后面；
        swap(&a[0], &a[i+1]);
        //重新调整堆为大顶堆；
        HeapAdjust(a, 0, i );
    }
}

void HeapAdjust(int *a,int i,int size){

    int lchild = 2 * i;
    int rchild = 2 * i + 1;
    int max = i;

    if (i <= size) {
        if (lchild <= size && a[lchild] > a[max]) {
            max = lchild;
        }

        if (rchild <= size && a[rchild] > a[max]) {
            max = rchild;
        }

        if (i != max) {
            swap(&a[i], &a[max]);
            HeapAdjust(a, max, size);
        }
    }
}
