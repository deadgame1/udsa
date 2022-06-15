#include <bits/stdc++.h>
using namespace std;


/** 
 * @brief https://leetcode.com/problems/ransom-note/
 * 
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::map<char,int> mp;
        int i;
        for(i=0;i<magazine.length();i++){
            if(mp.count(magazine[i]) != 1){
                mp.insert({magazine[i],1});
            }else{
                mp[magazine[i]]++;
            }
        }
        for(i=0;i<ransomNote.length();i++){
            char keyToCheck = ransomNote[i];
            if(mp.count(keyToCheck) != 1){
                return false;
            }else{
                int value = mp[keyToCheck];
                if(value < 1){
                    return false;
                }
                mp[keyToCheck]--;
                continue;
            }
        }
        return true;
    }
};
int main(){
    Solution s;
    cout<<s.canConstruct("aa","aab");
}