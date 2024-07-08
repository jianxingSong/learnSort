//
// Created by joey on 2024/6/13.
//
/*
 * 简单选择排序
 * 基本思想：在数据中选出最大（小）的元素放在最终的位置
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1）
 * 简单选择排序是不稳定排序
 */

#include "iostream"
#include "vector"

using namespace std;

void simpleSelectSort(vector<int>& nums){
    for(int i = 0;i < nums.size() - 1;i++){
        int minIdx = i;
        for(int j = i + 1;j < nums.size();j++){
            minIdx = nums[j] < nums[minIdx] ? j : minIdx;
        }
        if(i != minIdx)
            swap(nums[i], nums[minIdx]);
    }
}

int main(){
    vector<int> nums{1, 4, 3, 2, 5};
    simpleSelectSort(nums);
    for(int& i : nums)
        cout << i << " ";
    cout << endl;

    return 0;
}
