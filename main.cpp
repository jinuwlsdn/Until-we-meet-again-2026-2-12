#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;


int ope[4];
int min_value = 10e8;
int max_value = -10e8;

int num[11];

int n;

void recurse(int depth, int result){


  //인자 2개  전의 계산한 값과 depth 

  if(depth == n-1){
    max_value = max(max_value , result);
    min_value = min(min_value , result);
    return;
  }

  for(int i = 0 ;  i < 4 ; ++i){

    //+ - x / 
    if(ope[i] > 0){
      
      if(i == 0){

        //덧셈 
        //전의 값과 더한다
        ope[i]--;
        int k = (result + num[depth+1]);
        recurse(depth+1, k);
        ope[i]++;
      }
      else if(i == 1){
        ope[i]--;
        int k = (result - num[depth+1]);
        recurse(depth+1, k);
        ope[i]++;
      }
      else if(i == 2){
        ope[i]--;
        int k = (result * num[depth+1]);
        recurse(depth+1, k);
        ope[i]++;
      }
      else if(i == 3){
        ope[i]--;
        int k = (result / num[depth+1]);
        recurse(depth+1, k);
        ope[i]++;
      }
    }
    

  }



}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  //14888

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. 백트래킹을 통해서 만들어진 식을 구하고 그 식에서 값을 계산해서 max, min 값을 비교하면 될 것 같다.
  //식의 결과를 R이라 했을 때 -10억 <= R <= 10억 . 어떤 경우에서도 이 범위를 벗어나지 않는다.
  //또한 N의 최댓값이 그렇게 크지 않아서 백트래킹 문제로 생각할 수 있다.

  //2. 중복을 허용하지 않기 때문에 O(N!) N의 최댓값이 11이기 때문에 충분히 가능하다.

  //3. 1차원배열 

  //4. 


  

  cin >> n;

  for(int i =0 ; i  < n ; ++i){
    cin >> num[i];
  }

  for(int i =0 ;  i < 4; ++i){
    cin >> ope[i];
  }

  recurse(0, num[0]);




  cout << max_value << '\n' << min_value ;
 
  

 
  
  return 0;
}