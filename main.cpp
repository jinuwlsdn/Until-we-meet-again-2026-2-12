#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int arr[9];
bool visited[9];
int n,m;

void recurse(int k, int num){

  if(num == m){
    for(int i = 0 ; i < m; ++i){
      cout << arr[i] << " ";
    }
    cout << '\n';
    return;
  }

  for(int i = k ; i <= n ; ++i){

    if(!visited[i]){
      //방문 X
      arr[num] = i;
      //visited[i] = true;

      //자기보다 큰 수를 인자로 넘겨주면 그 전의 recurse에선 그 큰 수 보다 작은
      //값을 쓴 적이 없다.
      recurse(i+1,num+1);

      //visited[i] =  false;
    }
  }
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  //15650

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점


  //1 recurse함수에서 인자값을 추가로 전달 해야할 것 같다. 오름차순이니까 for문을
  //돌릴때 전 recurse함수에서 썼던 값보다 높게 설정해야 함. 
  

  //2 중복없이니까 15649처럼 N!인데 N이 8이므로 가능

  //3 1차원배열 필요.

  

  cin >> n >> m;

  recurse(1,0);

 
  

 
  
  return 0;
}