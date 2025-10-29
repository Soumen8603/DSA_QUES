#include <iostream>
#include <vector>
using namespace std;
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
int findPartition(vector<int>&vec,int low,int high){
    int pivot = vec[low];
    
    int i = low;
    int j= high;
    while(i < j){
        while(vec[i] <= pivot && i <= high-1){
            i++;
        }
        while(vec[j] > pivot && j >= low+1){
            j--;
        }
        if(i < j){
        swap(vec[i],vec[j]);
        }
    }
   
    swap(vec[j],vec[low]);
    return j;
}
void quickSort(vector<int> &vec, int low, int high)
{
    if(low < high){
    
    int partition = findPartition(vec,low,high);
    quickSort(vec,low,partition-1);
    quickSort(vec,partition+1,high);
    }
}
int main()
{
    vector<int> vec = {8, 7, 2, 9, 1, 4, 7};
    int n = vec.size();
    int low = 0;
    int high = n - 1;
    quickSort(vec, low, high);
    for(int i = 0;i < vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}
