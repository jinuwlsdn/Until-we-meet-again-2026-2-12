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
 
  int n,m;

  int min_total_dist = INF;
  vector<pair<int,int>> house, chicken, selected;

  void get_dist(){
    int total_dist =0;
    for(auto& h : house){
      int dist =INF;

      for(auto& c : selected){
        dist = min(dist, abs(h.first - c.first) + abs(h.second - c.second));
      }
      total_dist += dist;
    }
    min_total_dist = min(min_total_dist , total_dist);
  }

  void recurse(int start_idx, int count){
    if(count == m){
      //거리계산
      get_dist();

      return;
    }

    //전체 치킨집 chicken.size() 중에서 M개를 뽑는다.
    for(int i = start_idx; i<chicken.size(); ++i){
      selected.push_back(chicken[i]);
      recurse(i+1, count+1);
      selected.pop_back();
    }
  }

  int main(){

    // ios::sync_with_stdio(false);
    // cin.tie(0);

     

    
    //15686

    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

    //도시에 있는 치킨집 중에서 M개를 선택하고 나머지는 제거한다
    //이렇게 수많은 경우의수를 만들어보고 치킨 거리를 계산하여 
    //최솟값을 구하면 될 것 같다.

    

    cin >> n >> m;

    for(int i = 0; i <n ; ++i){
      for(int j =0 ; j <n ; ++j){
        int temp;
        cin >> temp;
        //집의 좌표와 치킨집의 좌표를 넣는다.
        if(temp == 1) house.push_back({i,j});
        else if(temp == 2) chicken.push_back({i,j});
      }
    }

    recurse(0,0);

    cout << min_total_dist << '\n';
    
    return 0;
  }











  //The reason why I miss you lies in your smile