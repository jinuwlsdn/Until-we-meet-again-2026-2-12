#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
char op[10];
bool visited[10];
vector<string> results; // 조건을 만족하는 모든 문자열을 담을 벡터

// 현재 숫자(prev), 다음 숫자(curr)가 부등호(op)를 만족하는지 체크
bool check(int prev, int curr, char oper) {
    if (oper == '<') return prev < curr;
    if (oper == '>') return prev > curr;
    return false;
}

void dfs(int depth, string s) {
    if (depth == n + 1) {
        results.push_back(s); // 완성된 문자열 저장
        return;
    }

    for (int i = 0; i <= 9; i++) { // 0부터 9까지 모든 숫자 시도
        if (!visited[i]) {
            // 첫 번째 숫자는 그냥 넣고, 
            // 두 번째부터는 직전 숫자(s.back())와 부등호 조건을 검사
            if (depth == 0 || check(s.back() - '0', i, op[depth - 1])) {
                visited[i] = true;
                dfs(depth + 1, s + to_string(i));
                visited[i] = false;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> op[i];

    dfs(0, "");

    // 모든 가능한 답이 results에 들어있음
    // DFS는 0부터 순차적으로 탐색하므로 
    // 첫 번째 원소가 최소값, 마지막 원소가 최대값입니다.
    sort(results.begin(), results.end());

    cout << results.back() << "\n"; // 최대값
    cout << results.front() << "\n"; // 최소값

    return 0;
}