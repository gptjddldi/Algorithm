// Leet Code 824. Goat Latin
#include <bits/stdc++.h>
using namespace std;

string toGoatLatin(string cmd){
    unordered_set<char> vowel({'a','e','i','o','u','A','E','I','O','U'});
    string res, temp;
    istringstream S(cmd);
    int count = 1;
    while(S>>temp){
        res += ' ' + (vowel.count(temp[0])== 1 ? temp : temp.substr(1) + temp[0]) + "ma";
        for(int i=0;i<count;i++) res+='a';
        count++;
    }
    return res.substr(1);
}

int main() {
    cout<<toGoatLatin("i speak Goat Latin");
}
