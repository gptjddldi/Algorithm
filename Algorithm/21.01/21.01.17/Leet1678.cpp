// Leet Code 1678. Goal Parser Interpretation

#include <bits/stdc++.h>

using namespace std;

string interpret(string cmd){
    string res = "";
    for (int i = 0; i < cmd.length(); i++)
    {
        switch (cmd[i])
        {
        case 'G':
            res+=cmd[i];
            break;
        case '(':
            if(cmd[i+1] == ')') {
                res+='o';
                i++;
            }
            else{
                res += "al";
                i +=3;
            }
        default:
            break;
        }
    }
    return res;
    
}

int main(){
    cout<< interpret("G()(al)");
}
