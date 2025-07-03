char kthCharacter(int k) {
        string s = "a";
        string gen = "b";
        s+=gen;
        while(s.size() < k){
            string newgen = gen;
            for(int i = 0;i < gen.size();i++){
                if(gen[i]=='z'){
                    newgen += 'a';
                }
                else{
                    newgen += ((gen[i] - 'a' + 1)+'a');
                }
            }
            s += newgen;
            gen = newgen;
        }
        return s[k-1];
    }
