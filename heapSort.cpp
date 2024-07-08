//
// Created by joey on 2024/6/13.
//
/*
 * 堆排序：堆一定是一个完全二叉树，并且父节点一定要大于（小于）等于子节点
 * 编号为i的节点的两个子节点为2i + 1和2i + 2，父节点为(i - 1) / 2
 * 那么如何使用堆来排序？---堆的顶部就是最大值或最小值，每次将堆顶弹出，然后重新构建堆
 */



#include "iostream"
#include "vector"

using namespace std;

//! heapSize代表要heapify的范围，idx代表要对哪个节点进行heapify
void heapify(vector<int>& tree, int heapSize, int idx){
    //找到两个子节点
    int c1 = 2 * idx + 1;
    int c2 = 2 * idx + 2;
    int minIdx = idx;
    if(c1 < heapSize && tree[c1] < tree[minIdx])
        minIdx = c1;
    if(c2 < heapSize && tree[c2] < tree[minIdx])
        minIdx = c2;
    if(minIdx != idx){
        swap(tree[minIdx], tree[idx]);
        heapify(tree, heapSize, minIdx);
    }
}

//! 从最后一个不是最小堆的节点开始从下到上进行heapify
void buildHeap(vector<int>& tree, int heapSize){
    int lastNode = heapSize - 1;
    int lastNodeParent = (lastNode - 1) / 2;
    for(int i = lastNodeParent;i >= 0;i--){
        heapify(tree, heapSize, i);
    }
}

//! 每次交换堆顶的最小元素和最后一个元素，然后将新换的堆顶元素进行heapify，注意每次循环的tree的大小是要减小的，因为每次排好序的元素会放在最后
void heapSort(vector<int>& tree){
    buildHeap(tree, tree.size());
    for(int i = tree.size() - 1;i >= 0;i--){
        swap(tree[i], tree[0]);
        heapify(tree, i, 0);
    }
}

int main(){
    vector<int> nums{49, 38, 65, 97, 76, 13, 27, 49};
    heapSort(nums);

    for(int& i : nums){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
