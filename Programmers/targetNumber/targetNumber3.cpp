//다른 풀이

// 첫 번째 풀이

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0, mid_value;
    
    if (numbers.empty()) {
        if (target == 0) { return 1; }
        else { return 0; }
    }

    mid_value = numbers.back();
    numbers.pop_back();
    
    answer += solution(numbers, target+mid_value);
    answer += solution(numbers, target-mid_value);

    return answer;
}






// 두 번째 풀이

#include <string>
#include <vector>

using namespace std;

int factorial(int n) {
    if (n == 0) { return 1; }
    return n * factorial(n-1);
}

int DFS(int idx, int target, bool* check, int* count) {
    int answer = 0, max, nextIdx;
    
    // 종료되는 부분 => check가 끝까지 갔다.
    if (idx == 51){
        if (target == 0) { return 1; }
        else { return 0; }
    }
    
    
    // idx 값을 몇 개 갖고 있는지 확인
    max = count[idx];
    
    // 다음 index 위치를 찾기
    nextIdx = idx + 1;
    while (nextIdx < 51) {
        if (check[nextIdx]) { break; }
        nextIdx++;
    }
    
    // 중요!
    for (int i=0;i<=max;i++) {
        answer += DFS(nextIdx, target + idx * (2*i-max), check, count) * (factorial(max) / factorial(i) / factorial(max-i));
        // 할 필요 없음!
//        answer += DFS(nextIdx, target - idx * (2*i-max), check, count);
    }

    return answer;
}

int solution(vector<int> numbers, int target) {
    int answer = 0, N = numbers.size(), idx;
    bool check[51];     // i번째 값이 존재하는지 확인
    int count[51];      // i번째 값이 몇 개 존재하는지 확인
    
    // check의 초기값
    for (int i=0;i<51;i++) { check[i] = false; }
    
    // check와 count 세팅
    for (int i=0;i<N;i++) {
        int j = numbers.back();
        numbers.pop_back();
        
        if (check[j]) { count[j]++; }
        else { check[j] = true; count[j] = 1; }
    }
    
    idx = 1;
    while (idx < 51) {
        if (check[idx]) { break; }
        idx++;
    }
    
    // 시작
    answer = DFS(idx, target, check, count);
    
    return answer;
}





// 세 번째 풀이

#include <string>
#include <vector>

using namespace std;

int DFS(vector<int> numbers, int target, int sum) {
    int answer = 0, mid_value;
    
    if (numbers.empty()) {
        if (target == 0) { return 1; }
        else { return 0; }
    }
    
    if ((target + sum < 0) || (target - sum > 0)) { return 0; }
    
    mid_value = numbers.back();
    numbers.pop_back();
    
    sum -= mid_value;
    
    answer += DFS(numbers, target+mid_value, sum);
    answer += DFS(numbers, target-mid_value, sum);
    
    return answer;
}

int solution(vector<int> numbers, int target) {
    int sum = 0, N = numbers.size();
    
    for (int i=0;i<N;i++) {
        sum += numbers[i];
    }

    return DFS(numbers, target, sum);
}