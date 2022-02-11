class Solution {
public:
     bool checkInclusion(string s1, string s2) {
        
        bool flag=true;
        
        map<char,int> mp;
        
        map<char,int> mp1;
        
        for(auto x: s1) mp1[x]++;
        
        int n=s1.size();
        int m=s2.size();
        
        if(n>m) {
            return false;
        }
        
        for(int i=0;i<n;i++){
            
            mp[s2[i]]++;
        }
        
        for(auto x: mp1){
            
            if(mp.find(x.first)==mp.end()){
                flag=false;
                break;
            }
            else{
                if(x.second!=mp[x.first]){
                    flag=false;
                   break;
                }
            }
        }
        
        if(flag) return flag;
        for(int i=n;i<m;i++){
            mp[s2[i]]++;
            mp[s2[i-n]]--;
            
            if(mp[s2[i-n]]==0){
                mp.erase(s2[i-n]);
            }
            
            flag=true;
            
             for(auto x: mp1){
            
            if(mp.find(x.first)==mp.end()){
                flag=false;
                break;
            }
            else{
                if(x.second!=mp[x.first]){
                    flag=false;
                   break;
                }
            }
        }
            
            if(flag) return true;
        }
        
        return flag;
    }
};