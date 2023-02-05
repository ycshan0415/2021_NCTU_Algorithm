#include<iostream>
using namespace std;
#define mod 1000000007;

long long power(long long a, long long n){
    long long ans = 1;
    while(n > 0){
        if(n % 2 == 1){
            ans = (ans * a) % mod;
            n--;
        }
        n = n / 2;
        a = (a * a) % mod;
    }
    
    return ans;
}

long long f(long long a, long long b, long long day){
    //通式
    long long ans, c, pn;
    c = b / (a - 1);
    pn = power(a, day - 1);
    ans = (pn * (1 + c)  - c) % mod;
    if (ans < 0)
        ans += mod; 
    
    return ans ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long a, b, n;
    cin >> a >> b >> n;
    //a = the age of the person, b = unhealthy factor

    for (long long i = 0; i < n; i++){
        long long day;
        cin >> day;
        cout << f(a, b, day) << "\n";
    }

    return 0;
}