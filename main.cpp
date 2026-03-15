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


//값  k가 <= 0 이면 1 그니까 0이거나 음수면 1로 고정 
//20보다 크면 20 20 20 으로 고정
//결국 어떤 값 w(a,b,c)는 무수히 많은 1을 더하는 것이니까
//초기값은 0으로 설정하고 만약 0이 아니면 한번 다녀왔다는것이다
int arr[21][21][21]; 

int w(int a, int b , int c){
  if(a <= 0 || b <= 0 || c <= 0) return 1;
  if(a > 20 || b > 20 || c> 20) return w(20,20,20);


  //다녀왔다.
  if(arr[a][b][c] != 0) return arr[a][b][c];


  //안 다녀옴
  if(a<b && b<c){
    arr[a][b][c] = w(a,b,c-1) + w(a, b-1 ,c-1) - w(a,b-1,c);
  }
  else{
    arr[a][b][c] =  w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
  }

  return arr[a][b][c];


}

int main(){

  // ios::sync_with_stdio(false);
  // cin.tie(0);


  //1912
  
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  int a,b,c;
  while(1){
    

    cin >> a >> b >> c;

    if(a == -1 && b == -1 && c == -1) break;

    //실행
    printf("w(%d, %d, %d) = %d\n", a,b,c, w(a,b,c));
  }
  
  


  return 0;
}