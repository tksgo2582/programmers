// 중요 포인트 : 우선순위큐를 이용해서, 쌓여있는 요청에 대해서는 빨리처리할 수 있는거 먼저...
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue< vector<int> > pq;
    sort(jobs.begin(), jobs.end()); // 작업요청 시간별로 정렬.
    int idx = 0, time = 0;
    
    while(!pq.empty() || idx < jobs.size()){    //작업할게 남아있다.
        if(idx < jobs.size() && jobs[idx][0] <= time){  // 들어올 작업이 있고, 그 작업의 시작시간이 현재 시간에 들어와 있을때
            pq.push({-jobs[idx][1], jobs[idx][0]}); 
            idx++;
            continue;
        }    
        // 현재 작업 존재
        if(!pq.empty()){
            time += -pq.top()[0];
            answer += time - pq.top()[1];   //현재 시간 - 요청 들어온 시간
            pq.pop();
        }else{
            time = jobs[idx][0];
        }
    }
    return answer/jobs.size();
}