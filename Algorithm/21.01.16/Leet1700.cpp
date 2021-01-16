// Leet Code 1700. Number of Students Unable to Eat Launch
#include <bits/stdc++.h>

using namespace std;

// 학생들 줄은 queue 샌드위치는 statck
// 만약 줄 첫번째 학생이 스택 top 에 있는 샌드위치가 좋으면 그거 받고 나감
// 싫으면 안 받고 queue의 끝으로 감.
// 이 문제의 관건은 "순환"을 찾는 것
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    bool flag = true;
    while(flag && !sandwiches.empty()){
        flag = false;
        for (int i=0; i<= sandwiches.size(); i++) {
            if(students[0] == sandwiches[0]){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                flag = true;
            }
            else{
                students.push_back(students[0]);
                students.erase(students.begin());
            }
        }
    }
    return sandwiches.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> students = {1,1,1,0,0,1};
    vector<int> sandwiches = {1,0,0,0,1,1};

    cout<<countStudents(students, sandwiches);
}