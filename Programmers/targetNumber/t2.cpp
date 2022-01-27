#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void print_vector(vector<int> vec) {
    for (int a : vec) {
        printf("%d ", a);
    }
    printf("\n");
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<int> next;
    vector<int> copy;

    next.push_back(numbers.front());
    next.push_back(numbers.front() * -1);
    for (int i = 1; i < numbers.size(); i++) {
        print_vector(next);

        copy.clear();
        for (int j = 0; j < pow(2, i); j++) {
            copy.push_back(next.at(j) + numbers.at(i));
            copy.push_back(next.at(j) - numbers.at(i));
        }
        next.swap(copy);
    }
    print_vector(next);

    for (int i = 0; i < next.size(); i++) {
        if (next.at(i) == target)
            answer++;
    }
    return answer;
}

int main(){
    vector<int> v;
    v.assign(5,1);   
    cout<< solution(v, 3);
}