/*
1. 두 수의 합 찾기
정수 배열 nums와 정수 target이 주어졌을 때, 두 수의 합이 target이 되는 두 수의 인덱스를 반환하세요.

각 입력에는 정확히 하나의 해답만 존재하며, 동일한 요소를 두 번 사용할 수 없습니다.
반환 순서는 상관없습니다.

예시 1:
입력: nums = [2, 7, 11, 15], target = 9
출력: [0, 1]
설명: nums[0] + nums[1] == 9이므로 [0, 1]을 반환합니다.

예제 2:
입력: nums = [3,2,4], 목표값 = 6
출력: [1,2]

예제 3:
입력: nums = [3,3], 목표값 = 6
출력: [0,1]

제약 조건:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
유효한 답은 하나뿐입니다.

추가 질문: 시간 복잡도가 O(n²)보다 작은 알고리즘을 제시할 수 있습니까?
채택됨
20,818,420/36.5M
채택률
57.1%
*/
// ============================================================
// Competitive Programming Template (MSVC / cl.exe 전용)
// ============================================================

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <chrono>
#include <queue>
#include <stack>

using namespace std;

#define dbg(x) debug(x)

// 기본 타입
template<typename T>
void debug(const T& value) {
    cout << value << "\n";
}

// pair
template<typename T, typename U>
void debug(const pair<T,U>& p) {
    cout << "{ " << p.first << ", " << p.second << " }\n";
}

// vector
template<typename T>
void debug(const vector<T>& v) {
    cout << "[ ";
    for (const auto& e : v)
        cout << e << " ";
    cout << "]\n";
}

// set
template<typename T>
void debug(const set<T>& s) {
    cout << "[ ";
    for (const auto& e : s)
        cout << e << " ";
    cout << "]\n";
}

// unordered_map
template<typename K, typename V>
void debug(const unordered_map<K,V>& m) {
    cout << "{ ";
    for (const auto& [k,v] : m)
        cout << k << ":" << v << " ";
    cout << "}\n";
}

// ============================================================
// 🧠 Solution 영역
// ============================================================

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    return { i, j };
                }
            }
        }

        return {};
    }

    // O(n2)
    /*
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int> m;

        for (int i = 0; i < nums.size(); ++i)
        {
            int need = target - nums[i];

            if (m.count(need))
                return { m[need], i };

            m[nums[i]] = i;
        }

        return {};
    }
    */
};

// ============================================================
// 🧪 Test Runner
// ============================================================

int main()
{
    auto start = chrono::high_resolution_clock::now();

    Solution sol;

    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    dbg(result);

    return 0;
}