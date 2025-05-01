#include <bits/stdc++.h>
using namespace std;

// 反着推的
int f(int n) { // f(n)表示第n天的桃子数
    if (n == 1) return 1; // 边界条件，第一天的桃子数（由于反着推，原是第n天）
    return (f(n - 1) + 1) * 2; // 假设f(n-1)的桃子数是正确的，然后计算f(n)
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    // Your code here
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}