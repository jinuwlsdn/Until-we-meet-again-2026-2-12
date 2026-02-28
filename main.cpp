#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <math.h>

using namespace std;


vector<char> input_value;
//bool visited[16];
vector<string> result;
int l,c;

void recurse(int depth, int next ,string words){

  if(depth == l){
    //모음과 자음이 알맞게 들어갔는지 확인을해야한다.

    int mo = 0;
    int ja = 0;
    //모는 1이상 자는 2이상이 되었을때 만족하는 words라서 그때 
    //push_back하고 아니면 return한다.
    for(int i = 0 ; i<words.length(); ++i){
      if(words[i] == 'a' || words[i] == 'e' || 
        words[i] == 'i' || words[i] == 'o' || words[i] == 'u' ){
          mo++;
        }
      else{
        ja++;
      }
    }

    if(mo >= 1 && ja >= 2){
      //result.push_back(words);
      cout << words << '\n';
    }
    else return;
    

    
  }


  for(int i = next ; i<c; ++i){
    recurse(depth+1, i+1, words + input_value[i]);
  }


}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  
  
  //1759
  //16234
  
  //1 아이디어 2 시간복잡도 3 자료구조 4 유의해야할 점

  //1. 중복 X 서로다른 소문자  길이는 L 결과값에 넣을때 확인


  

  cin >> l >> c;

  input_value.resize(c);
  for(int i = 0 ; i < c ; ++i){
    cin >> input_value[i];
  }

  sort(input_value.begin(), input_value.end());
  

  recurse(0,0,"");




  // sort(result.begin(), result.end());

  // for(string ans : result){
  //   cout << ans << '\n';
  // }

  return 0;
}