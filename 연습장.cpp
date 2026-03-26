  #include <cstdlib>
  #include <queue>
  #include <iostream>
  #include <algorithm>
  #include <vector>
  #include <cstring>
  #include <set>
  #include <cmath>
  #include <map>
  #include <iomanip> 


  using namespace std;

  typedef long long ll;

  typedef pair<int, int> pii;

  const int INF = 1e9;

  struct Edge{
    int u,v;
    double dist;
    bool operator<(const Edge& other) const {
      return dist < other.dist;
    }
  };

  int parent[1001];

  int find_parent(int x){
    if(parent[x] == x) return x;
    return parent[x] = find_parent(parent[x]);
  }

  void union_parent(int a , int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
  }

  // void union_p

  int main(){

    // ios::sync_with_stdio(false);
    // cin.tie(0);


    
    //1774
    //9370
    
    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

    //1. 좌표들을 서로 이어서 간선을 만들고 그 간선과 정점들 사이에서 mst를 만들면 된다.

    //2. M^2 log M 1000000 * 10  천만 
    // 가능하다.

    int n,m;

    cin >> n >> m;

    vector<pair<long long, long long>> coord(n+1);

    for(int i = 1;  i<=n ; ++i){
      cin >> coord[i].first >> coord[i].second;
      parent[i] = i;
    }

    for(int i = 0 ; i < m ;++i){
      int u,v;
      cin >> u >> v;
      union_parent(u,v);
    }

    vector<Edge> edges;
    for(int i = 1 ; i <= n; ++i){
      for(int j = i+1 ; j <= n; ++j){
        long long dx = coord[i].first - coord[j].first;
        long long dy = coord[i].second - coord[j].second;

        double d = sqrt(dx*dx + dy*dy);
        edges.push_back({i,j,d});
      }
    }

    sort(edges.begin(), edges.end());

    double result = 0;

    for(int i = 0 ; i < edges.size(); ++i){
      if(find_parent(edges[i].u) != find_parent(edges[i].v)){
        union_parent(edges[i].u , edges[i].v);
        result += edges[i].dist;
      }
    }

    cout << fixed << setprecision(2) << result << '\n';

    
    return 0;
  }