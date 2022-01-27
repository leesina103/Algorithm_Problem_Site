// https://programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void print_vector(vector<int> vec) {
    for (int a : vec) 
       cout << a;
    cout<<endl;
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<int> next;
   
    next.push_back(numbers.front());
    next.push_back(numbers.front() * -1);
    //처음 vector가 [1,2,3,4,5]라고 가정하면
    //처음에 벡터에서 제일 앞에 있는 것을 대입 [1,-1]
    //밑에 for문은 한번 돌았을 때, [1+2,1-2,-1+2,-1-2]하고 swap으로 초기화 해주기
    //계속 돌면서 모든 index에 진행
    for(int i=1 ; i<numbers.size() ; i++){
        print_vector(next);
        vector<int> copy;
        // copy.clear();
        for(int j=0 ; j<pow(2,i) ; j++){
            copy.push_back(next.at(j) + numbers.at(i));
            copy.push_back(next.at(j) - numbers.at(i));
        }
        next.swap(copy);
    }
    for(int i=0 ; i<next.size(); i++){
        if(next.at(i)==target)
            answer++;
    }
    return answer;
}

int main(){
    vector<int> v;
    v.assign(5,1);   
    cout<< solution(v, 3);
}