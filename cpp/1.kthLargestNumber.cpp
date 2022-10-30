#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  vector<string> msg{"Hello", "World", "from", "VS Code", "and the C++ extension!"};

  for (const string &word : msg)
  {
    cout << word << " ";
  }
  cout << endl;
}
// #include <headers.h>

// int findKthLargestNumber(vector<int> &nums, int k)
// {
//   priority_queue<int, vector<int>, greater<int>> pq;
//   int count = 0;
//   for (int i = 0; i < nums.size(); i++)
//   {
//     if (count < k)
//     {
//       pq.push(nums[i]);
//       count++;
//     }
//     else
//     {
//       if (nums[i] > pq.top())
//       {
//         pq.pop();
//         pq.push(nums[i]);
//       }
//     }
//   }
//   return pq.top();
// }