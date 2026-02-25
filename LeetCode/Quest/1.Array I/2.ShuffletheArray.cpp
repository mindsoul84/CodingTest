/*
Q2. 배열 섞기

[x1, x2, ..., xn, y1, y2, ..., yn] 형태의 2n개 요소로 구성된 배열 nums가 주어집니다.
배열을 [x1, y1, x2, y2, ..., xn, yn] 형태로 반환하세요.

예시 1:
입력: nums = [2, 5, 1, 3, 4, 7], n = 3
출력: [2, 3, 5, 4, 1, 7]
설명: x1=2, x2=5, x3=1, y1=3, y2=4, y3=7이므로 답은 [2, 3, 5, 4, 1, 7]입니다.

예시 2:
입력: nums = [1,2,3,4,4,3,2,1], n = 4
출력: [1,4,2,3,3,2,4,1]

예시 3:
입력: nums = [1,1,2,2], n = 2
출력: [1,2,1,2]

제약 조건:
1 <= n <= 500
nums.length == 2n
1 <= nums[i] <= 10^3

채택됨 1,016,725/1.1M 채택률 89.0%
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {

    vector<int> result;

    for (int i = 0; i < n; ++i)
    {
        result.push_back(nums[i]);      // 2, 5, 1
        result.push_back(nums[i + n]);  // 3, 4, 7
    }

    for (auto a : result)
    {
        cout << a << endl;
    }

    return result;
}


int main()
{
    vector<int> nums;

    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(7);

    shuffle(nums, 3);
}