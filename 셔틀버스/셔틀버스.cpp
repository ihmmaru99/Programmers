#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    int result;
    string answer = "";
    vector<int> v;
    for(string time : timetable)
        v.push_back(stoi(time.substr(0,2)) * 60 + stoi(time.substr(3,2)));
    sort(v.begin(), v.end());
    int bus = 540;
    int index = 0;
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=index; j<v.size(); j++){
            if(v[j] <= bus){
                index++;
                cnt++;
                if(cnt == m)
                    break;
            }
        }
        if(i == n - 1){
            if(cnt == m){
                result = v[index-1]-1;
            }
            else
                result = bus;
        }
        bus += t;
    }
    int h = result / 60;
    if(h < 10)
        answer += "0" + to_string(h) + ":";
    else
        answer += to_string(h) + ":";
    int minutes = result % 60;
    if(minutes < 10)
        answer += "0" + to_string(minutes);
    else
        answer += to_string(minutes);
    return answer;
}