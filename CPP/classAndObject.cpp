#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here
class Student {
  public:
  void input();
  int calculateTotalScore(); 
  
  private:
    vector<int> scores;
};

void 
Student::input() {
    for(int i=0; i <5;++i) {
        int value;
        cin>>value;
        scores.push_back(value);
    }
}
int
Student::calculateTotalScore() {
 int sum=0;
 for(size_t i=0; i <scores.size();++i) {
    sum+=scores[i];
 }   
    return sum;
}

//this is the working code but didn't show that cpp has the
//access modifier property for the member field. member field of 
//the class should be designed to be private and the modification
//and access of the member field should be done through the function 