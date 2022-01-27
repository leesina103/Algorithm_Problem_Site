// https://www.acmicpc.net/problem/1003 1003번

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// 이 코드는 메모리제이션이 안되기 때문에, 시간초과 뜸으로 안됨.
// int zerocount = 0;
// int onecount = 0;

// int fibonacci(int n) {
//     if (n == 0) {
//         zerocount++;
//         // cout << "0";
//         return 0;
//     }
//     else if (n == 1) {
//         onecount++;
//         // cout << "1";
//         return 1;
//     }
//     else {
//         return fibonacci(n - 1) + fibonacci(n - 2);
//     }
// }

// int main()
// {
//     cout << fibonacci(3) << endl; //1012
//     cout << zerocount << " " << onecount ;
//     cout << fibonacci(6) << endl;         //101101015
//     cout << zerocount << " " << onecount ;
//     cout << fibonacci(22) << endl;         //101101015
//     cout << zerocount << " " << onecount ;
//     return 0;
// }

// 희찬이 풀이방식(Botton-up), 아예 모든수의 피보나치 수열의 0과1의 개수를 다 저장해놓기
// int fibo[41][2]; 
// void fibonacci() {
//     fibo[0][0]=1;
//     fibo[0][1]=0;
//     fibo[1][0]=0;
//     fibo[1][1]=1;
//     for(int i=2;i<41;i++){
//         fibo[i][0]=fibo[i-2][0]+fibo[i-1][0];
//         fibo[i][1]=fibo[i-2][1]+fibo[i-1][1];
//     }
// }

// int main(){
//     int N,c,zero,one; cin>>N;
//     fibonacci();
//     while(N--){
//         cin>>c;
//         zero=fibo[c][0];
//         one=fibo[c][1];
//         cout<<zero<<" "<<one<<endl;
//     }
// }


// 내 풀이(Botton-up)
int cache[41][2];

void fibonacci(int n){
    if (n == 0) {
        cache[0][0] = 1;
        cache[0][1] = 0;
    }
    else if (n == 1) {
        cache[1][0] = 0;
        cache[1][1] = 1;
    }

    for(int i=2 ; i<=n ; i++) {
        cache[i][0] = cache[i-1][0] + cache[i-2][0];
        cache[i][1] = cache[i-1][1] + cache[i-2][1];
    }
}

// 내 풀이2(Top-down)
// 각각의 n값에 대하여 0,1의 개수를 담을 수 있는 배열을 만들어서 그 배열 자체를 return 하는 방법
// ex) fibo(2) = fibo(1) + fibo(0); => 10 / 1과 0이 한번씩 나오므로
// fibo[2][0] = 1, fibo[2][1] = 1; 으로 저장하고 fibo[2]={1,1}; 자체를 return 하는 방식
int *fibonacci2(int n)
{
    if (n == 0)
    {
        cache[0][0] = 1;
        cache[0][1] = 0;
        return cache[0];
    }
    else if (n == 1)
    {
        cache[1][0] = 0;
        cache[1][1] = 1;
        return cache[1];
    }

    int &ret1 = cache[n][0];
    int &ret2 = cache[n][1];

    if (ret1 != -1 || ret2 != -1)
        return cache[n];

    ret1 = fibonacci2(n - 1)[0] + fibonacci2(n - 2)[0];
    ret2 = fibonacci2(n - 1)[1] + fibonacci2(n - 2)[1];
    return cache[n];
}

// int main(){
//     memset(cache, -1, sizeof(cache));
    
//     // fibonacci(3);
//     // cout << cache[3][0] << " " << cache[3][1];
//     // fibonacci(4);
//     // cout << cache[4][0] << " " << cache[4][1];
//     int num;
//     cin >> num;
//     for(int i=0 ; i<num ; i++){
//         cin >> num;
//         int* arr = fibonacci2(num);
//         cout << arr[0] << " " << arr[1] << endl;
//     }
//     // int *arr = fibonacci2(3);
//     // cout << arr[0] << " " << arr[1] << endl;
//     // arr = fibonacci2(4);
//     // cout << arr[0] << " " << arr[1] << endl;
//     return 0;
// }

int main(){
    int num;
    cin >> num;
    for(int i=0 ; i<num ; i++){
        cin >> num;
        cout << num+1;
    }
}

int main(){
    int N,c,zero,one; cin>>N;
    while(N--){
        cin>>c;
        cout<<c+1 <<" "<<c+2<<endl;
    }
}

// 3
// 0
// 1
// 3

// 2
// 6
// 22