/*
219. 중복 포함 여부 확인 II

정수 배열 nums와 정수 k가 주어졌을 때, 배열에서 서로 다른 인덱스 i와 j가 존재하여 nums[i] == nums[j]이고 abs(i - j) <= k이면 true를 반환합니다.

예시 1:
입력: nums = [1,2,3,1], k = 3
출력: true

예시 2:
입력: nums = [1,0,1,1], k = 1
출력: true

예시 3:
입력: nums = [1,2,3,1,2,3], k = 2
출력: false

제약 조건:
1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105

승인된 요청 수: 1,698,370/3.3M 승인율: 50.8%
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
    // unordered_map
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {   
        // ※ unordered_map<key, value> key:value, value:index
        unordered_map<int, int> seen;   // value, index 저장
        
        for (int i = 0; i < nums.size(); ++i)
        {
            int value = nums[i];
            int index = i;            

            if (seen.find(value) != seen.end())
            {
                if (abs(index - seen[value]) <= k)
                    return true;
            }

            seen[value] = index;
        }

        return false;
    }
    
};

// ============================================================
// 🧪 Test Runner
// ============================================================

int main()
{
    auto start = chrono::high_resolution_clock::now();

    Solution sol;

    vector<int> nums = {1,2,3,1,2,3};
    int k = 2;
    
    auto result = sol.containsNearbyDuplicate(nums, k);

    dbg(result);

    return 0;
}