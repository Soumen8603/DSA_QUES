class Solution {
    #define pic pair<int,char>
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        priority_queue<pic>maxheap;
        if(a>0)maxheap.push({a,'a'});
        if(b>0)maxheap.push({b,'b'});
        if(c>0)maxheap.push({c,'c'});
        while(!maxheap.empty()){
            auto[count,character] = maxheap.top();
            maxheap.pop();
            int n = res.size();
            if(n >= 2 && res[n-1] == character && res[n-2] == character){
                if(maxheap.empty())break;
                auto[nextcount,nextchar] = maxheap.top();
                maxheap.pop();
                res.push_back(nextchar);
                nextcount--;
                if(nextcount > 0)maxheap.push({nextcount,nextchar});
            }
            else{
                 res.push_back(character);
                count--;
            }
            if(count > 0)maxheap.push({count,character});
        }
        return res;

    }
};
