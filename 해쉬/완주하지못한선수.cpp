#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map <string, int> maraton;

    for(int i =0; i < participant.size(); i++){
        maraton[participant[i]] += 1;
    }
    for(int i = 0; i < completion.size(); i++){
        maraton[completion[i]] -= 1;
    }
    for(auto a : maraton){
        if(a.second > 0){
            answer = a.first;
        }
    }

    return answer;
}