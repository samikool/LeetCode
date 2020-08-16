#include <iostream>
#include <cstring>
#include <string>

using std::cout;
using std::string;
using std::max;

int lengthOfLongestSubstring(string s){
    int left=0, right=0, result=0;
    int a[256];
    memset(a,-1,sizeof(a));
    while(right<s.size()){
        if(a[s[right]]==-1 || a[s[right]]<left){
            result = max(result, right-left+1);
            
        } else{
            left = a[s[right]]+1;
        }
        a[s[right]]=right;
        right++;
    }
    return result;
}

int main(){
    string s = "dabcabcbbd";

    cout << lengthOfLongestSubstring(s);

    return 1;
}