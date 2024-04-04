#include <iostream>
#include <string>
using namespace std;
int maxDepth(string s)
{
  int openbrackets = 0;
  int ans = 0;

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(')
    {
      openbrackets++;
      ans = max(ans, openbrackets);
    }
    if (s[i] == ')')
    {
      openbrackets--;
    }
  }
  return ans;
}
int main()
{
  string s = "(1+(2*3)+((8)/4))+1";
  cout << "Maximum nesting depth is " << maxDepth(s);
  return 0;
}
