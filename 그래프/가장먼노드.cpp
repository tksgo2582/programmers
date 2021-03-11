//벨만포드알고리즘 사용?
// ㄴㄴㄴㄴ... 그냥 단순하게 bfs 로도 해결 가능... 
// 양방향 그래프, 간선비용 모두 1 
// 방문여부체크하면서 이전비용에서 +1
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 20010
#define INF 50010
using namespace std;
int Map[MAX][MAX];
int dist[MAX];
int visited[MAX];

void dijk(int n){
    queue<int> q;
    visited[1] = true;
    q.push(1);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 2; i < n+1;i++){
            if( visited[i] == false&& Map[cur][i]){
                q.push(i);
                visited[i] = true;
                dist[i]= dist[cur] + 1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    for(int i = 0 ; i < edge.size();i++){
        Map[edge[i][0]][edge[i][1]] = Map[edge[i][1]][edge[i][0]] = 1;
    }
    
    dijk(n);
    
    int max_num = 0;
    for(int i =0 ;i<=n; i++){
        if(dist[i] != INF)
            max_num = max(dist[i], max_num);
    }
    
    return count(dist+1, dist+n+1, max_num);
    
}