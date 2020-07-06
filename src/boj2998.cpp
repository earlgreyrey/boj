#include <iostream>
#include <string.h>

using namespace std;

string B;
string ans = "";
string H[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> B;

    int len = B.length();
    if(len % 3){
       if((len % 3)==1){
           B.insert(0, "00");
       } else{
           B.insert(0, "0");
       }
    }

    // cout << B;
    for(int i = 0; i < len; i+=3){
      string tmp;
      tmp.assign(B, i, 3);
      // tmp.substr(B, i, i+3);
      // cout << "tmp now: " << tmp <<"\n";
      for(int j = 0; j < 8; j++){
        // cout << "H[j] now: " << H[j] <<"\n";
        if(!(tmp.compare(H[j]))){
          cout << j;
          break;
        }
      }
      // cout << tmp;
    }
}