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


int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);


  //1946
  //10610
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점


  //찾은 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수

  //1. 30의 배수니까 무조건 입력값에 0이 있어야한다 
  //배수 판정법에서 세자릿수를 100a+10b+c라고 했을 때
  //99a + a + 9b + b + c로 표현할 수 있다. 9(11a+b)무조건 3의배수 9의배수이고 a+b+c가 남는다.
  //따라서 a+b+c 3의배수라면 전체 값이 3의 배수다.
  //3의 배수고 만약 마지막 자리에 0이 오게 되면 30의 배수

  //2. N은 10^5 개의 숫자로 구성되어 있다. 그러면 문자열로 받아야 하고, 
  //크게 돌았을 때 최대로 10^5 일일이 다 만들어보기엔 값이 너무 커진다.
  //(10^5)! <- 최악의 경우 따라서 단축하여 계산할 아이디어가 필요하다.

  string number;
  cin >> number;

  

  long long sum = 0;

  bool check = false;
  for(int i = 0 ; i < number.length() ; ++i){
    sum += (number[i] - '0');
    if(number[i] == '0') check = true;
    //0이 있다면 true 만약에 없으면 값은
    //false다.
  }

  if(!check || sum % 3 != 0){
    cout << -1 << '\n';
    return 0;
  }else{
    sort(number.begin(), number.end(), greater<char>());
    cout << number << '\n';
  }

  
  


  


  return 0;
}