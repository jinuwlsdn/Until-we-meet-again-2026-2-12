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
  
  
  //100 * 100 = 10000
  //999 * 999 = 998001  


  const int MAX = 2000000;


  
 
  

  int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    
    int max_count =0;
    int answer = 0;

    for(long long i = 1 ; i <= 1000000; ++i){
      int count = 0;


      long long num = i;

      while(num != 1){
        if(num % 2 == 0) num /= 2;
        else num = 3*num + 1;
        count++;
      }


      if(count > max_count){
        max_count = count;
        answer = i;
      }
    }
    
    
    cout << answer << '\n';
   
    return 0;
  }









  

  //The reason why I miss you lies in your smile