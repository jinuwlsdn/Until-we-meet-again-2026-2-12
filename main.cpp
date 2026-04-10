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
  #include <deque>


  using namespace std;

  typedef long long ll;

  typedef pair<int, int> pii;

  const int INF = 1e9;


  
  int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);


    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

    //24511

    //1 스택이면 arr[i] 값을 이전 값으로 바꾸고
    //큐면 arr[i] 값을 냅둔다 <- x
    //덱을 사용해서 이해 해보자
    // 0 1 1 0
    // 1 2 3 4
    // 이 상황에서 2 3은 필요가 없다 어차피 들어오고 pop되면 그 전에 넘겨받았던 수니까
    //그렇게 되면 큐를 잘 봐야한다. 한 사이클을 돌았을 때 나가는 수는 마지막 큐에 있던 수다 
    //처음으로 4가 나가게 되고 그 다음 1 또 다음은 처음으로 들어온 수 2

   
    int n;
    cin >> n;

    vector<int> qs(n);
    for(int i = 0 ; i < n ; ++i) cin >> qs[i];

    deque<int> dq;

    for(int i = 0 ; i <n ; ++i){
      int x;
      cin >> x;

      //qs가 0 이면 큐니까 가져온다
      if(qs[i] == 0) dq.push_back(x);
    }

    //1과 4가 들어와있는 상태

    int m;
    cin >> m;

    while(m--){
      int value;
      cin >> value;

      dq.push_front(value);
      cout << dq.back() << " ";
      dq.pop_back();
    }
    

  }




















  

  //The reason why I miss you lies in your smile