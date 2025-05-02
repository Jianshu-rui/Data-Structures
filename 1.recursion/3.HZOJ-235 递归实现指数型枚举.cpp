#include <bits/stdc++.h>
using namespace std;

int arr[10];

void print_one_result(int n) {
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return ;
}

void f(int i, int j, int n) {
    if (j > n) return ;
    for (int k = j; k <= n; k++) {
        arr[i] = k;
        print_one_result(i);
        f(i + 1, k + 1, n);
    }
    return ;
}

/*
1. f(i, j, n) 表示i位置开始，并且i位置可选的数字最小是j，最大是n的所有指数型枚举
    f(i, j, n) 表示实现i位置及其以后的所有位置的指数型枚举，j是i位置最小可用数字
2. 边界条件
    j > n, 直接返回
3. 递归关系
    f(i, j, n) 是一个集合，表示从i位置开始，j数字开始，所有枚举的集合

    f(i, j, n) = 
    {
        j + f(i + 1, j + 1, n)
        j + 1 + f(i + 1, j + 2, n)
        j + 2 + f(i + 1, j + 3, n)
        j + 3 + f(i + 1, j + 4, n)
        j + 4 + f(i + 1, j + 5, n)
        ...
        n + f(i + 1, n + 1, n)
    }
*/

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    // Your code here
    int n;
    cin >> n;
    f(0, 1, n);
    return 0;
}