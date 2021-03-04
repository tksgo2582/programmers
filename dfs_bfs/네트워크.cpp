/* 
    1. dfs활용 --> bfs 로 변경
    2. 네트워크 인접리스트 만들고 순호
    3. visit 배열 활용하여 bfs 다 돌고 검사 안된곳 추가 검사...cnt++
 */

#include <string>
#include <vector>
#include <queue>
using namespace std;
int visited[210];
vector<int> computer[210];
void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i =0; i < computer[now].size(); i++){
            int next = computer[now][i];
            if(visited[next] != 1){
                visited[next] = 1;
                q.push(next);
            }
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < computers.size(); i++){
        for(int j =0 ; j < computers[i].size(); j++){
            if(i == j) continue;
            if(computers[i][j] == 1)
                computer[i].push_back(j);
        }
    }
    for(int i =0 ; i < n; i++){
        if(visited[i] == 0){
            bfs(i);
            answer++;
        }
    }

    return answer;
}