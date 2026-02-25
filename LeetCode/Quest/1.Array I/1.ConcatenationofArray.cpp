/*
Q1. 배열 연결

길이가 n인 정수 배열 nums가 주어졌을 때, 0부터 시작하는 인덱스를 사용하여 ans[i] == nums[i]이고 ans[i + n] == nums[i]인 길이 2n의 배열 ans를 생성하려고 합니다.
구체적으로, ans는 두 개의 nums 배열을 연결한 것입니다.
생성된 배열 ans를 반환하세요.

예시 1:
입력: nums = [1,2,1]
출력: [1,2,1,1,2,1]
설명: 배열 ans는 다음과 같이 구성됩니다.
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]

예시 2:
입력: nums = [1,3,2,1]
출력: [1,3,2,1,1,3,2,1]
설명: 배열 ans는 다음과 같이 구성됩니다.
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]

제약 조건:
n == nums.length
1 <= n <= 1000
1 <= nums[i] <= 1000

합격 1,350,689/1.5M 합격률 90.5%
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

    vector<int> getConcatenation(vector<int>& nums) {
        int before_size = nums.size();

        for (int i = 0; i < before_size; i++)
        {
            nums.push_back(nums[i]);
        }

        for (auto a : nums)
        {
            cout << a << endl;
        }

        return nums;
    }

int main()
{
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);

    getConcatenation(nums);
}