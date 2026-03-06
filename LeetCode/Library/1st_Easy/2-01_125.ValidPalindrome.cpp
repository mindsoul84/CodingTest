/*
125. 유효한 회문

어떤 구문이 회문인지 여부는 모든 대문자를 소문자로 바꾸고 영숫자가 아닌 문자를 모두 제거했을 때 앞뒤로 읽었을 때 같은지 여부에 달려 있습니다. 영숫자에는 문자와 숫자가 포함됩니다.

주어진 문자열 s가 회문이면 true를, 그렇지 않으면 false를 반환합니다.

예시 1:
입력: s = "A man, a plan, a canal: Panama"
출력: true
설명: "amanaplanacanalpanama"는 회문입니다.

예시 2:
입력: s = "race a car"
출력: false
설명: "raceacar"는 회문이 아닙니다.

예시 3:
입력: s = " "
출력: true
설명: s는 영숫자가 아닌 문자를 제거한 후 빈 문자열 ""입니다.

빈 문자열은 앞뒤로 읽어도 똑같으므로 회문입니다.

제약 조건:
1 <= s.length <= 2 * 10⁵
s는 출력 가능한 ASCII 문자만으로 구성되어야 합니다.

승인됨 5,222,331/9.9M  승인율 52.8%
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

    bool isPalindrome(string s) {        

        string filter;        

        for (char c : s)
        {
            if (isalnum(c))
            {
                filter += tolower(c);
            }
        }
        
        string reverse = filter;
        std::reverse(reverse.begin(), reverse.end());

        if (reverse == filter)
            return true;

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

    string str = "race a car";
    
    auto result = sol.isPalindrome(str);

    dbg(result);

    return 0;
}