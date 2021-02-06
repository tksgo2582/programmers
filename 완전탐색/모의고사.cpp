// 123번 학생이 찍는 답안과 실제 답안과의 비교.
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int arr1[5] = {1,2,3,4,5};
    int arr2[8] = {2,1,2,3,2,4,2,5};
    int arr3[10] = {3,3,1,1,2,2,4,4,5,5};
    
    int grades[3] = {0,0,0};
    for(int i =0 ; i < answers.size(); i++){
        if(answers[i] == arr1[i%5])
            grades[0]++;
        if(answers[i] == arr2[i%8])
            grades[1]++;
        if(answers[i] == arr3[i%10])
            grades[2]++;
    }
    int MAX = max(grades[2],max(grades[0], grades[1]));
    cout << MAX;
    for(int i = 0; i < 3; i++){
        if(grades[i] == MAX)
            answer.push_back(i+1);
    }
    return answer;
}