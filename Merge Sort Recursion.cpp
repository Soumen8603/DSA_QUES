#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &vec, int low, int mid, int high)
{
    int l = low, r = mid + 1;
    vector<int> temp;
    while (l <= mid && r <= high)
    {

        if (vec[l] <= vec[r])
        {
            temp.push_back(vec[l]);
            l++;
        }
        else
        {
            temp.push_back(vec[r]);
            r++;
        }
    }
    while (l <= mid)
    {
        temp.push_back(vec[l]);
        l++;
    }
    while (r <= high)
    {
        temp.push_back(vec[r]);
        r++;
    }
    for(int i = low;i <= high;i++){
        vec[i] = temp[i - low];
    }
}
void mergeSort(vector<int> &vec, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(vec, low, mid);
    mergeSort(vec, mid + 1, high);
    merge(vec, low, mid, high);
}
int main()
{
    vector<int> vec = {8, 7, 2, 9, 1, 4, 7};
    int n = vec.size();
    int low = 0;
    int high = n - 1;
    mergeSort(vec, low, high);
    for(int i = 0;i < vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}
