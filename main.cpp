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


  bool prime[MAX+1];


  void sieve(){
    prime[1] = false;

    for(int i =2 ; i <=MAX;++i) prime[i] = true;



    for(int i =2 ; i*i<=MAX; ++i){
      for(int k = 2; i*k<=MAX; ++k){
        if(!prime[i]) continue;
        prime[i*k] = false;
      }
    }
  }
  
 
  

  int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    
    sieve();


    for(long long i = 1; ; ++i){
      
      long long num = i*(i+1) / 2;
      long long result_num = num;

      int result = 1;
      for(int k = 2; k*k<=num; ++k){
        if(prime[k] ==  true){
          //k가 소수다.
          if(num % k == 0){
            
            int count = 0;
            while(num%k == 0){
              count++;
              num /= k;
            }

            result *= (count+1);
          }
        }
      }

      //ex) 만약 7이 num이라고 하자
      //k*k<=num이니까 2와 3은 나누지 못하고 그냥 for문이 끝나버린다.
      //이때 result가 그냥 1로 저장되는데 7의 약수는 1과 7 이므로 원하는 답과 다르다.
      //소수분해후 남은수가 있다면 그 자체도 소수다.
      if(num > 1) result *= 2;

      if(result >= 500){
        cout << result_num <<'\n';
        break;
      }
      //cout << result << '\n';
    }
    
    
   
    return 0;
  }









  

  //The reason why I miss you lies in your smile