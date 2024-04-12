#include <iostream>

using namespace std;
long long sumSubstrings(string s)
{
    long sum = 0;
    long current = 0;
    long long previous = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < s.size(); i++)
    {
        current = (previous * 10) % mod + (s[i] - '0') * (i + 1) % mod;
        sum = (sum + current) % mod;
        previous = current;
    }
    return sum;
    // your code here
}
int main()
{
    string s = "1234";
    cout << "Sum of all possible substrings are " << sumSubstrings(s);
    return 0;
}
