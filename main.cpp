#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 10;

int n;
char op[MAX+1];
long long max_value = -1;
long long min_value = 1e10; //모든 입력에 답은 항상 존재하며 
//출력 정수는 하나의 문자열이 되도록 해야 한다.
bool visited[MAX+1];
string answer_dif[2];
int answer[MAX+1];



void dfs(int depth){
  
  if(depth == n+1){

    //cout << "hello";

    string line = "";
    
    //만족을 하는 넘인지 확인
    for(int i = 0 ; i<n ; ++i){

      //여기서 return 주면 끝나나?
      if(op[i] == '<' && (answer[i] > answer[i+1] )) return;
      else if(op[i] == '>' && (answer[i] < answer[i+1])) return;

      line += to_string(answer[i]);

    
    }

    line += to_string(answer[n]);

    //만족을 시키는 수를 찾음?
    if(max_value < stoll(line)){
      max_value = stoll(line);
      answer_dif[0] = line;
    }
    if(min_value > stoll(line)){
      min_value = stoll(line);
      answer_dif[1] = line;
    }
    return;

    //구현


    
  }

  for(int i = 0;  i<=9; ++i){
    if(!visited[i]){
      
      visited[i] = true;
      answer[depth] = i;
      dfs(depth + 1);
      visited[i] = false;
    }
  }
  
}


int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  //2529

  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. 연산자를 입력받았으면 그 입력값 순서대로 정수들을 넣어서
  //부등호 관계를 만족하는 정수를 찾고(recurse) max , min 계산해주면 될 것 같다.
  //이때는 recurse재귀함수를 써서 가지치기를 해야한다. 

  //2. 중복 X 이므로 O(N!)인데 N의 최댓값이 9이므로 가능하다.

  //3. 자료구조는 연산을 하는건 정수로 해야하는데 들어가는 값은 char로 
  //들어가기 때문에 여기서 검색을 좀 해야할 것 같다

  //4. 중복을 허용하지 않기때문에 visited 함수 및 연산자를 받기위해 char를
  //사용해야 할 것 같다.

  cin >> n;

  for(int i = 0 ; i < n ; ++i){
    cin >> op[i];
  }

 
  dfs(0);

  //answer_dif[0] = "Hello";

  cout << answer_dif[0] << '\n' << answer_dif[1];

  
  return 0;
}