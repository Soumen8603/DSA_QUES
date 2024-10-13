class node{
    public:
    int data,row,col;
    node(int d,int r,int c){
        data = d;
        row = r;
        col = c;
    }
};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};
class Solution {
public:

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node*,vector<node*>,compare> minHeap;
        int mini = INT_MAX,maxi = INT_MIN;
        int rowS = nums.size();
        for(int i = 0;i < rowS;i++){
            int element = nums[i][0];
            maxi = max(maxi,element);
            mini = min(mini,element);
            minHeap.push(new node(element,i,0));
        }
        int start = mini,end = maxi;
        while(!minHeap.empty()){
            node* temp = minHeap.top();
            minHeap.pop();
            mini = temp -> data;
            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }
            else if((maxi - mini == end - start) && (mini < start)){
                start = mini;
                end = maxi;
            }

            if(temp -> col + 1 < nums[temp->row].size()){
                maxi = max(maxi,nums[temp->row][temp->col + 1]);
                 minHeap.push(new node(nums[temp->row][temp->col + 1],temp->row,temp->col+1));
            }
            else{
                break;
            }
        }
        vector<int>ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};
