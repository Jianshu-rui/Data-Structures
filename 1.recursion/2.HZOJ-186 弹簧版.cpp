#include <bits/stdc++.h>
using namespace std;

int f(int i, vector<int> &arr, int n) { // f(i) 表示第从第i个弹簧板开始跳，跳出边界的次数
    if (i >= n) return 0; // 边界条件，如果i大于等于n，说明已经跳出边界了，返回0
    return f(i + arr[i], arr, n) + 1; // 假设f(i + arr[i]) 是正确的, 计算f(i)的值
}

/*
此题跟以前做的题目有点不同，与题意有关，但归纳的本质不变
以前是知道f(i)的值，求f(i + arr[i])的值
现在是知道f(i + arr[i])的值，求f(i)的值

当然这都是形式上的差异，实际上是一样的
*/

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    // Your code here
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    cout << f(0, arr, n) << endl;
    return 0;
}