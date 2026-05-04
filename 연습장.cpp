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


  // void union_p

  int main(){

   int number;
    cin >> number;
    
    int answer = 0;
    
    for(int i=0; i<2; i++){
        answer += number % 100;
        number /= 100;
    }
    cout << answer << endl;
    
    return 0;

    
    
  }