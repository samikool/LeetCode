#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using std::vector;
using std::string;
using std::cout;

/**
 * Original attempt
 * Correct idea, Terrible code
 */
string longestPalindromee(string s) {
    string res = "", t_res = ""; //get ride of res and t_res completely use max length and indicies to return substring of s
    int left=0, right=0;

    for(int i=1; i<s.length(); i++){ //drop i++ - see comments above first while
        //add break condition to leave loop if based on max len and i its impossible to find longer palindrome
        //have ifs into whiles might as well have whiles with slightly altered conditions
        if(s[i-1] == s[i+1]){
            left = i-1;
            right = i+1;
            t_res += s[i];

            //use this loop to adjust right and use next loop to find final length
            //if see repeated letters next to eachother adjust i so don't get stuck in going through them all again
            while(s[left] == s[right]){
                t_res = s[left] + t_res;
                t_res += s[right];           
                --left;
                ++right;

                if(left < 0 || right == s.length()){
                    break;
                }
            }
            //still need a condition like this but just store start indicie (left) and length (right-left+1)
            res = t_res.length() > res.length() ? t_res : res;
            t_res.clear();
        }

        //get rid of useless if
        //this loop given a correct left and right should continue to test there is a palindrome
        if(s[i] == s[i-1]){
            left = i-1;
            right = i;

            while(s[left] == s[right]){
                t_res = s[left] + t_res;
                t_res += s[right];           
                --left;
                ++right;

                if(left < 0 || right == s.length()){
                    break;
                }
            }
            //still need a condition like this but just store start indicie (left) and length (right-left+1)
            res = t_res.length() > res.length() ? t_res : res;
            t_res.clear();
        }
    }

    return res == "" ? s.substr(0,1) : res;
}

/**
 * Optomized Original
 */
string longestPalindrome(string s){
    if (s.size() < 2) return s;
    int n = s.size(), mlen = 0, start = 0, l, r;

    for(int i=0; i<s.size();){
        if(n-i <= mlen/2) break; //might start at halfway to end but not at end
        l=i, r=i;

        while(r < n-1 && s[l] == s[r+1]){
            ++r;
        }

        i = r+1;

        while(l > 0 && r < n-1 && s[l-1] == s[r+1]){
            --l; ++r;
        }

        if(mlen < r - l + 1){
            mlen = r - l + 1;
            start = l;
        }
    }
    return s.substr(start, mlen);
}


/**
 * Dynamic Solution, much slower than optomized-original because of table allocation
 */
string longestPalindromeee(string s){
    if (s.size() < 2) return s;

    int n = s.size(), i, j, l=0, r=1;

    int **t = (int**) calloc(n, sizeof(int*));
    for(i=0; i<n; i++)  t[i] = (int*) calloc(n, sizeof(int));

    for(int k=0; k<n; ++k){
        i=0,j=k;
        while(j != n){
            if(k == 0){
                t[i][j] = 1;
                l=i;
                r=j;
            }
            else if(k == 1 && s[i] == s[j]){
                t[i][j] = 1;
                l=i;
                r=j;
            }
            else if(s[i]==s[j] && t[i+1][j-1]){
                t[i][j] = 1;
                l=i;
                r=j;
            }
     
            // cout << i << ' ' << j << '\n';
            // printTable(t,n);
            i = i+1;
            j = j+1;
        }
    }
    return s.substr(l,r-l+1);
}

void printTable(int **t, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << t[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(){
    string s = "cbbd";
    cout << longestPalindrome(s) << "\n";

    s = "ababcbabaxyxyxyxyzyxyxyxyx";
    cout << longestPalindromee(s) << "\n";

    return 0;
}