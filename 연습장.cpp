#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// {가중치, 정점 번호} 순서로 저장 (priority_queue 정렬 기준 때문)
typedef pair<int, int> Edge;

void prim(int startNode, int V, vector<Edge> adj[]) {
    // 1. 초기화
    vector<bool> visited(V + 1, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq; // 최소 힙

    // 시작 정점 설정 (비용 0으로 시작)
    pq.push({0, startNode});
    
    int mstWeight = 0;
    int edgesCount = 0;

    cout << "선택된 간선 순서:\n";

    while (!pq.empty()) {
        int w = pq.top().first;  // 현재 가장 작은 가중치
        int u = pq.top().second; // 해당 간선이 가리키는 정점
        pq.pop();

        // 2. 이미 트리에 포함된 정점이면 무시 (중요!)
        if (visited[u]) continue;

        // 3. 정점 방문 처리 및 결과 합산
        visited[u] = true;
        mstWeight += w;
        
        if (w != 0) cout << "정점 연결 비용: " << w << endl;

        // 4. 새로 추가된 정점 u와 연결된 간선들을 큐에 삽입
        for (auto& next : adj[u]) {
            int nextWeight = next.first;
            int v = next.second;
            
            if (!visited[v]) {
                pq.push({nextWeight, v});
            }
        }
    }

    cout << "최종 MST 가중치 합: " << mstWeight << endl;
}

int main() {
    int V = 5; // 정점 개수
    vector<Edge> adj[6];

    // 그래프 데이터 (u, v, weight)
    // 예: 1번과 2번이 가중치 2로 연결됨
    adj[1].push_back({2, 2}); adj[2].push_back({2, 1});
    adj[1].push_back({3, 3}); adj[3].push_back({3, 1});
    adj[2].push_back({8, 3}); adj[3].push_back({8, 2});
    adj[2].push_back({5, 4}); adj[4].push_back({5, 2});
    adj[3].push_back({1, 4}); adj[4].push_back({1, 3});

    prim(1, V, adj);

    return 0;
}