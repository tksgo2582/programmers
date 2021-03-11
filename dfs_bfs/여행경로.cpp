/* 
    1. dfs 활용.. 벡터map 활용해서 dictionary처럼 사용
    2. 방문했는지 체크 필요... -> 삭제를 통해서?pop_back 밖에 안되니.. 오름차순으로 정렬..(back으로 목적지 받기)
    3. value값은 알파벳순으로 정렬

    ++ 
    무조건 알파벳 순이 아닌, 다른 경로가 존재시에만... 뒤에꺼를 먼저 가야 할 수 도 있다.
    for문을 이용해서 순회 하고, 전체 순회 안됐는데 return 이라면 다른거 다시 순회.

    +++
    -> 정답을 비교하기 위해서 벡터가 아닌. ***문자열로 만들어서 넘겨주는 방식!!!!!
        추후에 최소값을 가지는 문자열을 다시 벡터에 넣어주면 끝.
 */
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, vector<string>> airport;
map<string, int> visited;
vector<string> ans;
string ans_path = "a";
int total;

void dfs(string from, int cnt, string path){    //path 로 각 단계별로 상황을 넘겨준다.
    //ans.push_back(from);
    if(cnt == total){
        ans_path = min(path, ans_path);
        return;
    }

    for(int i =0; i < airport[from].size(); i++){
        int idx = airport[from].size()-1;
        string to = airport[from][idx-i]; // 다른 알파벳 먼저 방문해야 하는 경우 있을 수도..
        airport[from].erase(airport[from].begin()+idx - i);
        
        dfs(to, cnt+1, path+to);
        
        airport[from].push_back(to);
        sort(airport[from].begin(),airport[from].end(), greater<string>());
                //ans 배열에 넣었던거 삭제하는 부분...
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    total = tickets.size();

    for(int i = 0; i < tickets.size(); i++){        //벡터맵.. 각 항공에서 갈 수 있는 도시사전 만드는 작업
        string from = tickets[i][0];
        string to = tickets[i][1];
        visited[from]++;    //방문 가능 횟수
        
        airport[from].push_back(to);
        sort(airport[from].begin(),airport[from].end(), greater<string>());
    }
    //ans.push_back("ICN");
    visited["ICN"]++;
    dfs("ICN", 0 ,"ICN");
    for(int i = 0; i < ans_path.size(); i+=3){
        ans.push_back(ans_path.substr(i, 3));
    }
    return ans;
}