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
  
  int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);


    //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

    //1715

    //2490

    for(int i = 0 ; i<3 ; ++i){
      
      int one = 0;
      int zero = 0;
      for(int k = 0 ; k<4; ++k){
        int num ;
        cin >> num;

        if(num == 1) one++;
        else zero++;
      }

      if(zero == 4) cout << 'D' << '\n';
      else if(zero == 1) cout << 'A' << '\n';
      else if(zero == 2) cout << 'B' << '\n';
      else if(zero ==  3) cout << 'C' << '\n';
      else if(zero == 0) cout << 'E' << '\n'; 
    }
    



    return 0;
  }









  

  //The reason why I miss you lies in your smile