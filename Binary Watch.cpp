class Solution {
private:
    int reqLights(int n){
        int count = 0;
        for(int i = 6;i >= 0;i--){
            if((n >> i) & 1){
                count++;
            }
        }
        return count;
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        for(int i = 0;i < 12;i++){
            int total = turnedOn;
            int req = reqLights(i);
            string temp = "";
            if(req > total)continue;
            temp += to_string(i);
            temp += ":";
            total -= req;
            for(int j = 0;j < 60;j++){
                string temp1 = "";
                req = reqLights(j);
                if(req == total){
                    if(j < 10){
                        temp1 += "0";
                        temp1 += (j + '0');
                       
                    }
                    else{
                        temp1 += to_string(j);
                        
                    }
                    string final = temp + temp1;
                    ans.push_back(final);
                   
                }
            }
        }
        return ans;
    }
};
