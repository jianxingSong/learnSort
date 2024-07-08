//
// Created by joey on 2024/6/12.
//
/*
 *
 * 冒泡排序：基于交换的思想
 * 时间复杂度：O(n^2)
*/

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

void bubbleSort(vector<int>& nums){
    bool isChanged = true;
    for(int i = 1; i < nums.size() && isChanged;i++){  //冒泡排序总共需要nums.size() - 1趟
        isChanged = false;
        for(int j = 0;j < nums.size() - i;j++){
            if(nums[j] > nums[j + 1]){
                swap(nums[j], nums[j + 1]);
                isChanged = true;
            }
        }
    }
}

int main(){
    vector<int> nums{5, 4, 3, 2, 1};
    bubbleSort(nums);
    for(int& i : nums)
        cout << i << " ";
    cout << endl;

    return 0;
}
