bool cmp(string a,string b){
    string first = a+b;
    string second = b+a;
    return first > second;
}
    string largestNumber(vector<int>& nums) {
        vector<string>elements;
        for(int i = 0;i < nums.size();i++){
            elements.push_back(to_string(nums[i]));
        }
        sort(elements.begin(),elements.end(),[](string a,string b){
            return a+b > b+a;
        });
        if(elements[0]=="0")return "0";
        string res="";
        for(int i = 0;i < elements.size();i++){
            res += elements[i];
        }
        return res;
    }
