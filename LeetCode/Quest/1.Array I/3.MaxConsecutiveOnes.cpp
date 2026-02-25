/*
Q3. 연속된 1의 최대 개수

이진 배열 nums가 주어졌을 때, 배열에서 연속된 1의 최대 개수를 반환합니다.

예시 1:
입력: nums = [1,1,0,1,1,1]
출력: 3
설명: 처음 두 자리 숫자 또는 마지막 세 자리 숫자가 연속된 1입니다. 연속된 1의 최대 개수는 3개입니다.

예시 2:
입력: nums = [1,0,1,1,0,1]
출력: 2

제약 조건:
1 <= nums.length <= 105
nums[i]는 0 또는 1입니다.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {

    int cur_cnt = 0;
    int max_cnt = 0;
    
    for (int num : nums)
    {
        if (num == 1)
        {
            cur_cnt++;
            max_cnt = max(max_cnt, cur_cnt);
        }
        else
        {
            cur_cnt = 0;
        }
    }

    cout << "max_cnt: " << max_cnt << endl;

    return max_cnt;
}


int main()
{
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);

    findMaxConsecutiveOnes(nums);
}