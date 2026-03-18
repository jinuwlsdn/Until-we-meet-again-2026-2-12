#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <math.h>
#include <map>


using namespace std;

typedef long long ll;



int consult_value[16];


int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);


  
  
  //14501
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. 끝에서 부터 1일로 오면서 각 일수를 택했을 때 최댓값들을 구해본다.
  //ex) 1일에서 ti가 3이라고 했을 때 4일을 택할수있고 5일을 택할수 있고 6일을 택할수있다.
  //이때 무엇을 선택하는게 가장 좋은지 골라야하니까
  //역으로 가야한다. 예제입력1 에서 예를 들어보면 7일 이익 0 6일도 0 5일은 15가되고 
  //4일은 ti가 1이므로 5일 6일 7일 중에 최댓값을 선택하고 그것에다가 본인 pi를 더하면된다.
  //만약 ti가 2였으면 6일부터 선택했을것이다. 
  //그래서 1 2 3 4 5 6 7중에 pi의 최댓값을 구하면된다.
  //문제를 작게 쪼개고 DP, 각 일수 마다 하나하나 최댓값을 찾기 때문에 브루트포스

  //2. ti가 1일이라고 가정했을때 1+2+3+ ... 15(계산) + 1(출력)


  //3 pair pi최댓값  

  

  int n;

  cin >> n;


  int max_value = 0;

  vector<pair<int , int>> v(n);

  for(int i = 0 ; i < n ; ++i){
    cin >> v[i].first >> v[i].second;
  }


  for(int i = n-1; i >= 0 ; i--){
    int value = 0;

    int ti = v[i].first;
    int pi = v[i].second;
    if(i + ti > n){
      consult_value[i] = 0;
    } 
    else{
      //i + ti <= n
      for(int k = i+ti; k<n; ++k){
        //5일 이라고 치면 6 7을 탐색
        value = max(value, consult_value[k]);
      }

      consult_value[i] = pi+value;

    }

    
    
  }



  for(int i = 0 ; i <n ;++i){
    max_value = max(max_value, consult_value[i]);
  }

  cout << max_value << '\n';



  return 0;
}