#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    
    map<string, int> id_map;
    map<string, set<string>> r_map;
    
    for(int i=0; i<id_list.size(); i++){
        id_map[id_list[i]] = i;
    }
    for(auto i : report){
        stringstream ss(i);
        string a, b;
        ss >> a >> b;
        r_map[b].insert(a);
    }
    for(auto i : r_map){
        if(i.second.size() >= k){
            for(auto j : i.second){
                answer[id_map[j]]++;
            }
        }
    }
    return answer;
}