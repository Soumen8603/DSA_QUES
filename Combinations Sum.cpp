#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>&vec){
    for(int i = 0;i < vec.size();i++){
        cout<<vec[i] << " ";
    }
    cout<<endl;
}

void  print_combination(vector<int>&vec,int target,int n,int index,vector<int>&temp){
    if(index == n){
        if(target == 0){
            print(temp);
        }
        return;
    }
    
   
    if(target >= vec[index]){
    temp.push_back(vec[index]);
    print_combination(vec,target-vec[index],n,index,temp);
    temp.pop_back();
    }
    
    
    print_combination(vec,target,n,index+1,temp);
}
int main(){
    vector<int>vec = {2,3,5,7};
    
    int target = 7;
    int n = vec.size();
    vector<int>temp;
    print_combination(vec,target,n,0,temp);
}
