#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  cout << "Enter string to reverse: " << endl;
  cin >> input;
  string output;
  for(int n = input.size(); n>=0; --n){
    output += input[n];
  }
  cout << output << endl;
  return 0;
}
