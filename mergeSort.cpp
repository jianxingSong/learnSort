//
// Created by joey on 2024/6/14.
//

/*
 * 归并排序
 * 每次将两个有序数组合并成一个有序数组
*/

#include "iostream"
#include "vector"

using namespace std;

vector<int> merge2vec(vector<int> vec1, vector<int> vec2){
    vector<int> res(vec1.size() + vec2.size(), 0);
    int count = 0, i, j;
    for(i = 0, j = 0;i < vec1.size() && j < vec2.size();){
        if(vec1[i] <= vec2[j]){
            res[count++] = vec1[i++];
        } else {
            res[count++] = vec2[j++];
        }
    }

        while(i < vec1.size())
            res[count++] = vec1[i++];
        while(j < vec2.size())
            res[count++] = vec2[j++];

    return res;
}

vector<int> mergeSort(vector<int>& nums, int begin, int end){
    if(begin > end)
        return {};
    if(begin == end)
        return  {nums[begin]};
    int half = (end + begin) / 2;
    return merge2vec(mergeSort(nums, begin, half), mergeSort(nums, half + 1, end));
}

int main(){
    vector<int> nums{5, 1, 2, 3, 7, 4};
    vector<int> temp = merge2vec({1, 3}, {2, 4});
    vector<int> res = mergeSort(nums, 0, nums.size() - 1);
    for(int i : res)
        cout << i << " ";

    return 0;
}