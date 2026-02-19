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

void recurse(int num){

  if(num == m){
    for(int i = 0 ; i < m; ++i){
      cout << arr[i] << " ";
    }
    cout << '\n';
    return;
  }

  for(int i = 1 ; i <= n ; ++i){

    if(!visited[i]){
      //방문 X
      arr[num] = i;
      visited[i] = true;
      recurse(num+1);

      visited[i] =  false;
    }
  }
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  //15649

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1 재귀함수를 사용해서 문제를 푼다

  //2 시간복잡도 중복을 허용하지 않기 때문에 O(N!) n은 8이므로 8! 10!보다 작으면 OK

  //3 1차원배열 사용

  //4 visited 잘 체크하기

  

  cin >> n >> m;

  recurse(0);

 
  

 
  
  return 0;
}