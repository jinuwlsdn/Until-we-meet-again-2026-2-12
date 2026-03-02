#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <math.h>

using namespace std;

int is_palin(string input_str,int start , int end){
  while(start < end){

    if(input_str[start] ==  input_str[end]){
      //같은 문자
      start++;
      end--;
    }
    else return 2;
  }

  return 1;
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  
  
  //17609
  //16234
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. 문자열받는다.

  int T;
  cin >> T;
  vector<string> str(T);

  for(int i =0 ; i  < T ; ++i){
    string s;
    cin >> s;
    int judge = 0;

    int start = 0;
    int end = s.length()-1;

    while(start < end){

      if(s[start] ==  s[end]){
        //같은 문자
        start++;
        end--;
      }
      else{
        //다른문자야
        //summuus 라면 
        //0123456
        // 234만 판단을 할텐데 u을 제거 했을때 판별하는 인덱스 에다가 end-1 한 값을 넣

        //

        int case1 = is_palin(s, start+1, end);
        int case2 = is_palin(s, start, end-1);
        if(case1 == 1 || case2 == 1){
          judge = 1;
        }
        else{
          judge =2;
        }
        break;

      }
    }

    cout << judge << '\n';

  }


  



  return 0;
}