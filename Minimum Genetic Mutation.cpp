 int minMutation(string startGene, string endGene, vector<string>& bank) {
        bool check = false;
        for(int i = 0;i < bank.size();i++){
            if(bank[i] == endGene){
                check = true;
                break;
            }
        }
        if(check == false){
            return -1;
        }

        unordered_set<string>bank_set(bank.begin(),bank.end());
        queue<pair<string,int>>q;
        q.push({startGene,0});
        while(!q.empty()){
            pair<string,int>current = q.front();
            q.pop();
            string currentGene = current.first;
            int currDist = current.second;
            if(currentGene == endGene){
                return currDist;
            }
            vector<char> BASES = {'A', 'C', 'G', 'T'};
            for(int i = 0;i < currentGene.length();i++){
                char original = currentGene[i];
                for(char nextBase : BASES){
                    if(nextBase != original){
                        string nextGene = currentGene;
                        nextGene[i] = nextBase;
                        if(bank_set.count(nextGene)){
                            q.push({nextGene,currDist+1});
                            bank_set.erase(nextGene);
                            if(nextGene == endGene){
                                return currDist + 1;
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
