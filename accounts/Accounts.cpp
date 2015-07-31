#include <string>
#include <iostream>
#include <stdlib.h> 
#include <time.h> 
using namespace std;

class Account {
  int  balance = 0;
  string firstName, lastName, accountNo;
  struct tm *dob;
public:
  static int serial;
  Account (string fN, string lN, struct tm date);
  void addBalance(int);
  bool subBalance(int);
  void details();
private:
  void genAccNo();
};

int Account::serial=0;

void Account::addBalance(int amount) {
  balance += amount;
}

bool Account::subBalance(int amount) {
  if(balance >= amount) {
    balance -= amount;
    return true;
  }else{
    return false;
  }
}

void Account::genAccNo() {
  for(int n = 0; n < 6; n++) {
    accountNo += (char) (rand() % 26 + 65);
  }
  accountNo += to_string(serial);
  for(int n = accountNo.size(); n < 10; n++) {
    accountNo += (char) (rand() % 26 + 65);
  }
}

string getDate(struct tm *time) {
  return to_string(time->tm_mday) + "/" + to_string(time->tm_mon)
    + "/" + to_string(time->tm_year+1900);
}

void setRandDate(struct tm *time){
  time->tm_mday = rand()%30;
  time->tm_mon = rand()%12;
  time->tm_year = rand()%40+60;
}

void Account::details() {
  cout << "Name:       " + firstName + " " + lastName << endl;
  cout << "DOB:        " + getDate(dob) << endl;
  cout << "Account No: " + accountNo << endl;
  cout << "Balance:    " + to_string(balance) << endl;
}

Account::Account(string fN, string lN, struct tm date) {
  genAccNo();
  firstName = fN;
  lastName = lN;
  *dob = date;
}

int main() {
  srand(time(NULL));
  struct tm *date;
  setRandDate(date);
  Account account ("Joe", "Bloggs", *date);
  account.details();
  return 0;
}
