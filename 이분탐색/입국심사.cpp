/* 
    1. 이분탐색 활용.   
    전체에서 반씩 줄이며 탐색 ... mid/t1 + mid/t2 == n-2 일때 정답??
    최대 걸리는 시간 = 1e9 * 1e9 = 1e18
 */

#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long low=0, hi=1e18, mid;

    while(low<=hi){
        mid = (low+hi)/2;
        long long result = 0;
        for(int i = 0; i < times.size(); i++){
            result += mid/times[i];
        }
        if(result >= n){
            answer = mid;
            hi = mid - 1;
        }else if(result < n){
            low = mid+1; 
        }
    }
    
    return answer;
}