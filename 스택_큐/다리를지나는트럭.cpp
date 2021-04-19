#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int next_truck = 0;
    int weight_sum = 0;
    queue <int> q;
    
    for(int i = 0; i < bridge_length; i++){
        q.push(0);
    }
    while(!q.empty()){
        answer++;
        weight_sum -= q.front();
        q.pop();

        if(next_truck < truck_weights.size()){
            if(weight_sum + truck_weights[next_truck] <= weight){
                weight_sum += truck_weights[next_truck];
                q.push(truck_weights[next_truck]);
                next_truck++;
            }
            else{
                q.push(0);
            }
        }
    }
    return answer;
}