//
// Created by joey on 2024/6/14.
//

/*
 *
 *
 */

#include "iostream"
#include "vector"
#include "queue"

using namespace std;

void radixSort(vector<int>& nums){
    vector<queue<int>> bucket(10, queue<int>());
    int count = 1;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < nums.size();j++){
            bucket[(nums[j] / count) % 10].push(nums[j]);
        }

        // queue pop
        int temp = 0;
        for(int j = 0;j < 10;j++){
            while(!bucket[j].empty()) {
                nums[temp++] = bucket[j].front();
                bucket[j].pop();
            }
        }

        count = count * 10;
    }
}

int main(){
    srand(time(nullptr));
    vector<int> nums;
    for(int i = 0;i < 10;i++){
        nums.push_back(rand() % 100);
    }

    for(int& i : nums)
        cout << i << " ";
    cout << endl;
    radixSort(nums);
    for(int& i : nums)
        cout << i << " ";


    return 0;
}