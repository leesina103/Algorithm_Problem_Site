// https://programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(vector<int> numbers, int target, int index, int result) {
    int count = 0;    
    if(numbers.size()==index){
        if(result==target)
            return 1;
        else
            return 0;
    }

    count += solution(numbers, target, index+1, result+numbers.at(index));
    count += solution(numbers, target, index+1, result-numbers.at(index));
    return count;
}

int main(){
    vector<int> v;
    v.assign(5,1);   
    cout<< solution(v, 3, 0, 0);
}

// java를 이용한 풀이
// class Solution {
//     public int binaryTreeSearch(int[] nums, int idx, int target,int value){
//         if(idx == nums.length){
//             if(value == target)
//                 return 1;
//             else
//                 return 0;
//         }
//         return binaryTreeSearch(nums, idx+1, target, value+nums[idx]) + 
//             binaryTreeSearch(nums, idx+1, target, value-nums[idx]);
//     }
    
//     public int solution(int[] numbers, int target) {
//         return binaryTreeSearch(numbers, 0,target, 0);
//     }
// }