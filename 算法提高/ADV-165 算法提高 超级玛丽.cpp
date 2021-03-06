算法提高 超级玛丽
问题描述
　　大家都知道"超级玛丽"是一个很善于跳跃的探险家，他的拿手好戏是跳跃，但它一次只能向前跳一步或两步。有一次，他要经过一条长为n的羊肠小道，小道中有m个陷阱，这些陷阱都位于整数位置，分别是a1,a2,....am，陷入其中则必死无疑。显然，如果有两个挨着的陷阱，则玛丽是无论如何也跳过不去的。
　　现在给出小道的长度n，陷阱的个数及位置。求出玛丽从位置1开始，有多少种跳跃方法能到达胜利的彼岸（到达位置n）。
输入格式
　　第一行为两个整数n,m
　　第二行为m个整数，表示陷阱的位置
输出格式
　　一个整数。表示玛丽跳到n的方案数
样例输入
4 1
2
样例输出
1
数据规模和约定
　　40>=n>=3,m>=1
　　n>m;
　　陷阱不会位于1及n上

分析：和leetcode上面那道爬楼梯问题类似，但是要注意的是，爬楼梯是爬n的长度，而这里是从1出发到n，只要走n-1的长度，所以是初始化v[1] = 1, v[2]处如果没陷阱就是1，有陷阱就是0，然后根据状态转移方程v[i] = v[i-1] + v[i-2];求得v[n]的值即为种类个数~~~

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1, -1);
    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        v[temp] = 0;
    }
    v[1] = 1;
    v[2] = v[2] == 0 ? v[2] : 1;
    for(int i = 3; i <= n; i++) {
        if(v[i] != 0)
            v[i] = v[i-1] + v[i-2];
    }
    cout << v[n];
    return 0;
}