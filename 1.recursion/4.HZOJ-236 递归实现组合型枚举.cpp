#include <bits/stdc++.h>
using namespace std;

int arr[10];

void printf_one_result(int n) {
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return ;
}


/*
通过 i == m 作为主要终止条件以及 m - i - 1 <= n - k 作为剪枝条件，代码能够自然避免 j > n 的情况，所以不需要额外判断 j > n
*/
void f(int i, int j, int n, int m) {
    if (i == m) {
        printf_one_result(m);
        return ;
    }
    // n - k >= m - i - 1 简枝，i位置后面的数字个数不能小于m - i - 1
    // 也就是i位置后面至少要有m - i - 1个数字，才能满足m个数字的组合
    for (int k = j; k <= n && m - i - 1 <= n - k; k++){
        arr[i] = k;
        f(i + 1, k + 1, n, m);
    }
}
/*
1. f(i, j, n) 表示i位置开始，并且i位置可选的数字最小是j，最大是n的所有组合型枚举
2. 边界条件
    i == m, 直接返回
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

    int n, m;
    cin >> n >> m;
    f(0, 1, n, m);
    return 0;
}