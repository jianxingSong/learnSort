//
// Created by joey on 2024/6/12.
//
/*
 * 快速排序
 * 时间复杂度：O(log2n)
 * 快速排序是所有内排序方法中时间复杂度最好的一个
 * 快速排序不是原地算法，因为用了递归，需要调用栈的支持
 * 平均空间复杂度：O(logn)
 * 是不稳定的排序方法---相同元素的相对位置会在排序后发生改变
 * 不适用于对原本有序或者基本有序的记录序列进行排序
 */

#include "iostream"
#include "vector"

using namespace std;

int partition(vector<int>& nums, int low, int high){
    int temp = nums[low];
    while(low < high){
        while(low < high && nums[high] >= temp)
            --high;
        nums[low] = nums[high];
        while(low < high && nums[low] <= temp)
            ++low;
        nums[high] = nums[low];
    }
    nums[low] = temp;
    return low;
}

void quickSort(vector<int>& nums, int low, int high){
    if(low >= high)
        return;

    int pivot = partition(nums, low, high);
    quickSort(nums, low, pivot - 1);
    quickSort(nums, pivot + 1, high);
}

int main(){
    vector<int> nums{5, 3, 4, 2, 1, 6, 7, 0};
    quickSort(nums, 0, nums.size() - 1);
    for(int& i : nums){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
