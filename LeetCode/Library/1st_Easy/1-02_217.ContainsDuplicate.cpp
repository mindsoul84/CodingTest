/*
217. 중복 포함 여부

정수 배열 nums가 주어졌을 때, 어떤 값이든 배열에 두 번 이상 나타나면 true를, 모든 요소가 서로 다르면 false를 반환합니다.

예시 1:
입력: nums = [1,2,3,1]
출력: true
설명:
요소 1은 인덱스 0과 3에 나타납니다.

예시 2:
입력: nums = [1,2,3,4]
출력: false
설명:
모든 요소가 서로 다릅니다.

예시 3:
입력: nums = [1,1,1,3,3,4,3,2,4,2]
출력: true

제약 조건:
1 <= nums.length <= 105
-109 <= nums[i] <= 109

이 문제를 실제 면접에서 본 적이 있나요?

승인된 신청서 6,152,542건/960만 건, 승인율 64.1%
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

/*
아래처럼 이중 for문을 사용하면 시간복잡도가 O(n²)가 되어 TLE(Time Limit Exceed) 결과 나옴

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int chk_dup = 0;
        bool is_dup = false;        
        for (int i = 0; i < nums.size(); ++i)
        {
            chk_dup = nums[i];
            
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (chk_dup == nums[j])
                    is_dup = true;
            }
        }

        return is_dup;
    }
};
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> seen;                    // unordered_set 사용: O(n²) -> O(n)

        for (int num : nums) {            
            if (seen.find(num) != seen.end()) {     // 이미 본 숫자라면
                return true;                        // 중복 발견 즉시 종료
            }
            
            seen.insert(num);                       // 처음 보는 숫자라면 저장
        }

        return false;  // 끝까지 중복 없으면 false
    }
};

// ============================================================
// 🧪 Test Runner
// ============================================================

int main()
{
    auto start = chrono::high_resolution_clock::now();

    Solution sol;

    vector<int> nums = {1,2,3,4};
    
    auto result = sol.containsDuplicate(nums);

    dbg(result);

    return 0;
}