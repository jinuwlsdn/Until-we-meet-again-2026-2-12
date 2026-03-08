#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 기준 거리(mid)를 가지고 C개 이상의 공유기를 설치할 수 있는지 확인하는 함수
bool canInstall(const vector<int>& houses, int n, int c, int dist) {
    int count = 1; // 첫 번째 집에는 무조건 설치
    int lastInstalled = houses[0];

    for (int i = 1; i < n; i++) {
        // 현재 집과 마지막 설치된 집 사이의 거리가 기준 거리(dist) 이상이면 설치
        if (houses[i] - lastInstalled >= dist) {
            count++;
            lastInstalled = houses[i];
        }
    }

    // 설치된 개수가 목표(c)보다 크거나 같으면 true 반환
    return count >= c;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    vector<int> houses(n);
    for (int i = 0; i < n; i++) {
        cin >> houses[i];
    }

    // 1. 이분 탐색을 위한 정렬
    sort(houses.begin(), houses.end());

    // 2. 이분 탐색 범위 설정
    int start = 1; // 최소 거리
    int end = houses[n - 1] - houses[0]; // 최대 거리
    int result = 0;

    while (start <= end) {
        int mid = (start + end) / 2;

        // 3. 결정 함수 호출
        if (canInstall(houses, n, c, mid)) {
            // 성공했다면, 거리를 더 늘려본다 (최댓값을 찾기 위해)
            result = mid;
            start = mid + 1;
        } else {
            // 실패했다면, 거리를 좁힌다
            end = mid - 1;
        }
    }

    cout << result << "\n";

    return 0;
}