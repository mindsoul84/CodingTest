/*
136. 단일 숫자 찾기

정수 배열 nums가 주어졌습니다. 모든 요소가 두 번씩 나타나지만, 한 요소만 예외적으로 나타납니다. 그 예외적인 요소를 찾으세요.
실행 시간은 선형이어야 하며, 추가 공간은 상수만큼만 사용해야 합니다.

예시 1:
입력: nums = [2,2,1]
출력: 1

예시 2:
입력: nums = [4,1,2,1,2]
출력: 4

예시 3:
입력: nums = [1]
출력: 1

제약 조건:
1 <= nums.length <= 3 * 10⁴
-3 * 10⁴ <= nums[i] <= 3 * 10⁴

배열의 모든 요소는 한 번만 나타나고, 나머지 요소는 두 번씩 나타납니다.

응답률: 4,417,863/5.7M
수락률: 77.4%
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

// bool
void debug(const bool& value) {
    cout << (value ? "true" : "false") << "\n";
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

    int singleNumber(vector<int>& nums) {

        unordered_map<int, int> un_map;
        
        for (int num : nums)
        {
            un_map[num]++;
        }

        for (auto chk : un_map)
        {
            if (chk.second == 1)
            {
                return chk.first;
            }
        }

       return 0;
    }
};

// ============================================================
// 🧪 Test Runner
// ============================================================

int main()
{
    auto start = chrono::high_resolution_clock::now();

    Solution sol;

    vector<int> nums = { 4, 1, 2, 1, 2 } ;
    
    auto result = sol.singleNumber(nums);

    dbg(result);

    return 0;
}