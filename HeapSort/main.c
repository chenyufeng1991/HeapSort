//
//  main.c
//  HeapSort
//
//  Created by chenyufeng on 16/1/28.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

#include <stdio.h>

//调整堆
void HeapAdjust(int *a,int i,int size);

//建立堆
void BuildHeap(int *a,int size);

//堆排序
void HeapSort(int *a,int size);

//数据交换
void swap(int *first,int *second);

void HeapAdjust(int *a,int i,int size){  //调整堆

    int lchild = 2 * i;       //i的左孩子节点序号
    int rchild = 2 * i + 1;     //i的右孩子节点序号
    int max = i;            //临时变量，存储下标值
    /**
     *  改为size
     */
    if(i <= size){          //如果i不是叶节点就不用进行调整，从非叶子节点开始；
        if(lchild <= size && a[lchild] > a[max]){
            max = lchild;//把较大值放到max中；
        }
        if(rchild <= size && a[rchild] > a[max]){
            max = rchild;
        }
        if(max != i){
            swap(&a[i],&a[max]);
            HeapAdjust(a,max,size);    //避免调整之后以max为父节点的子树不是堆
        }
    }
}

void BuildHeap(int *a,int size){    //建立堆
    /**
     *  改为size
     */
    for(int i = size;i >= 1;i--){    //非叶节点最大序号值为size/2
        HeapAdjust(a,i,size);
    }
}

void HeapSort(int *a,int size){    //堆排序
    //首先要建立一个堆
    BuildHeap(a,size);
    for(int i = size;i >= 1;i--){

        swap(&a[1],&a[i]);           //交换堆顶和最后一个元素，即每次将剩余元素中的最大者放到最后面
        HeapAdjust(a,1,i - 1);      //重新调整堆顶节点成为大顶堆
    }
}

void swap(int *first,int *second){
    int temp;

    temp = *first;
    *first = *second;
    *second = temp;
}

int main(int argc, const char * argv[]) {

    int a[] = {0,16,1,25,9,22,2,10};
    HeapSort(a,8);
    for(int i = 0;i <= 7;i++){
        printf("%d ",a[i]);
    }
    return 0;
}



