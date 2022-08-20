#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int

int main()
{
  ll first, second;
  cin >> first >> second;

  ll mult = first * second;
  ll neg1 = first - second;
  ll neg2 = second - first;
  ll sum = first + second;

  ll max_num = std::max(mult, neg1, neg2, sum);
  if (max_num == mult)
  {
    cout << "*";
  }

  if (max_num == sum)
  {
    cout << "+";
  }
  if (max_num == neg1 || max_num == neg2)
  {
    cout
        << "-";
  }
}