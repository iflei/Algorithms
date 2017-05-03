#include <iostream>
#include <vector>
using namespace std;
 
int main() 
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1, -1);
    for(int i = 0; i < m; ++i) 
	{
        int trap;
        cin >> trap;
        v[trap] = 0; //0表示陷阱 
    }
    
    v[1] = 1;//从1位置出发 
    //如果2没有陷阱走到2 
    if(v[2] != 0)
		v[2] = 1;
    for(int i = 3; i <= n; i++) 
	{
        if(v[i] != 0)
            v[i] = v[i-1] + v[i-2]; //斐波那契数列 
    }
    cout << v[n];
    return 0;
}