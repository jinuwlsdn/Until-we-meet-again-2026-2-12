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
  #include <stack>


  using namespace std;

  typedef long long ll;

  typedef pair<int, int> pii;

  const int INF = 1e9;

  bool prime[1100001];

  void sieve(){
    for(int i = 2 ; i <= 1100000; ++i){
      prime[i] = true;
    }
    for(int i = 2 ; i * i <= 1100000; ++i){
      if(prime[i]){
        for(int j = i * i ; j<=1100000; j+=i){
          prime[j] = false;
        }
      }
    }
  }

  int main(){

    // ios::sync_with_stdio(false);
    // cin.tie(0);


    
    //1747
    //9370
    
    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

    // n 부터 백만까지 탐색하는데 소수이면 팰린드롬인지 아닌지 판단하고
    //팰린드롬이면 출력

    int n;
    cin >> n;

    sieve();

    for(int i = n ; i<=1100000; ++i){
      
      if(prime[i]){
        string str = to_string(i);

        //79197
        //1빼고 79만 보면된다
        //01234
        //324423
        //012345
        stack<int> s;
        
        int len = str.size();

        //절반만 넣기
        for(int k = 0 ; k < len/2; ++k){
          s.push(str[k]);
        }
        int start = (len % 2  == 0) ? len /2 : len / 2 + 1;
        
        bool ispalin = true;

        for(int k = start; k<len; ++k){
          if(str[k] != s.top()){
            ispalin = false;
            break;
          }
          s.pop();
        }

        if(ispalin && s.empty()){
          cout << i << '\n';
          break;
        }
      }
    }
    
    return 0;
  }