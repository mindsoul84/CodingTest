/*
268. 누락된 숫자 찾기

0부터 n까지의 범위에 있는 서로 다른 숫자 n개가 저장된 배열 nums가 주어졌을 때, 배열에 없는 유일한 숫자를 반환합니다.

예시 1:
입력: nums = [3,0,1]
출력: 2

설명:
숫자가 3개이므로 모든 숫자는 [0, 3] 범위에 있습니다. 따라서 nums 배열에 없는 숫자 2가 누락된 숫자입니다.

예시 2:
입력: nums = [0,1]
출력: 2

설명:
숫자가 2개이므로 모든 숫자는 [0, 2] 범위에 있습니다. 따라서 nums 배열에 없는 숫자 2가 누락된 숫자입니다.

예제 3:
입력: nums = [9,6,4,2,3,5,7,0,1]
출력: 8

설명:
숫자가 9개이므로 모든 숫자는 [0,9] 범위에 속합니다. nums에 8이 없으므로 8이 해당 범위에서 빠져 있습니다.

제약 조건:
n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
nums의 모든 숫자는 고유해야 합니다.

추가 질문: 추가 공간 복잡도 O(1)과 ​​실행 시간 복잡도 O(n)만 사용하여 솔루션을 구현할 수 있습니까?

승인됨 3,762,340/5.2M 승인율 71.7%
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

    // sum solution (1ms)
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        
        // 1. 0부터 n까지 다 있었을 때의 '원래 총합'을 구합니다. 등차수열의 합 공식: n * (n + 1) / 2        
        int expectedSum = n * (n + 1) / 2;
        
        // 2. 현재 배열에 들어있는 숫자들의 '실제 총합'을 구합니다.
        int actualSum = 0;
        for (int i = 0; i < n; i++) {
            actualSum = actualSum + nums[i]; 
        }
        
        // 3. 원래 총합에서 실제 총합을 빼면, 빠진 숫자가 튀어나옵니다!
        return expectedSum - actualSum;
    }

    // self solution (181ms)
    /*
    int missingNumber(vector<int>& nums) {
        
        int cnt = 0;
        
        sort(nums.begin(), nums.end());

        for (int i = 0; nums.size(); ++i)
        {
            if (std::find(nums.begin(), nums.end(), i) == nums.end())
                return i;
        }

        return 0;
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

    //vector<int> nums = { 0, 1 } ;
    vector<int> nums = { 9, 6, 4, 2, 3, 5, 7, 0, 1 } ;
    
    auto result = sol.missingNumber(nums);

    dbg(result);

    return 0;
}