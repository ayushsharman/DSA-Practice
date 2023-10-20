#include <bits/stdc++.h>
using namespace std;

vector<int> ninjaAndLessMaxElement(int n, vector<int> &a) {
  vector<int> ans;
  ans.push_back(-1);

  for (int i = 1; i < a.size(); i++) {
    int maxNum = INT_MIN;

    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) {
        ans.push_back(max(maxNum, a[i - 1]));
        maxNum = a[i - 1];
      } else {
        ans.push_back(-1);
      }
    }
  }

  return ans;
}


vector<int> ninjaAndLessMaxElement(int n, vector<int> &a) {
  // Write your code here.
  vector<int> ans;
  ans.push_back(-1);

  for (int i = 1; i < a.size(); i++) {
    int maxNum = INT_MIN;
    if (a[i - 1] < a[i]) {
      ans.push_back(max(maxNum, a[i - 1]));
      maxNum = a[i - 1];
    } else {
      ans.push_back(-1);
    }
  }

  return ans;
}


int main()
{
    
    return 0;
}