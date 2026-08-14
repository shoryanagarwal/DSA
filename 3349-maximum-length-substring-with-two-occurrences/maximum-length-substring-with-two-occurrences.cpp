class Solution {
public:
    int maximumLengthSubstring(string s) {
        

        int max_len=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int> freq;
            for(int j=i;j<s.length();j++){
                 freq[s[j]]++;
                if(freq[s[j]]>2){
                    max_len=max(max_len,j-i);
                    break;
                    
                }
                max_len=max(max_len,j-i+1);
               
            }


        }


        return max_len;
        
    }
};