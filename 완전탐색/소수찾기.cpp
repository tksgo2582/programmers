#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num){  //소수판별
    if(num < 2)         // 1인 경우
        return false;
    for(int i = 2; i <= sqrt(num); i++){    //2부터 시작, 제곱근까지 판별
        if( num % i == 0)   //나눠지는 수 있다면 false
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector <int> nums;
    sort(numbers.begin(), numbers.end());   //순열 전에는 정렬
    
    do{ //next_permutation 순열 사용
        string str;
        //순열을 가지고 모든 수 만들기, 하나씩 추가하면서 모든 가지 수 넣기
        for(int i = 0; i < numbers.size(); i++){
            str.push_back(numbers[i]);
            nums.push_back(stoi(str));
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    //정렬 후 중복원소 제거
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    for(int i =0; i < nums.size(); i++){
        if(isPrime(nums[i])){
            answer++;
        }
    }
    return answer;
}