/*
1. coke machines。大中小三个可乐机，每按一次出可乐量分别在[Amin,Amax], [Bmin
, Bmax], [Cmin, Cmax]之间，但不能确定具体容量是多少，现在想通过按这三个可乐
机，达到容量为[D, E]之间的可乐，问能否做到。也就是能否找到非负整数x, y, z使
得x*Amin+y*Bmin+z*Cmin>=D并且x*Amax+y*Bmax+z*Cmax<=E。感觉是个扩展的背包问题
，我给了穷举法和DP的解法，不过面试官最后说有个复杂度不依赖于D和E的解法，现在
也不知道怎么做。\

可乐机那题的解法，我能想到的是 DP， f(a, b)=True 表示能做到挤出的可乐量在[a, b]区间内。
f(a, b) = f(a+1, b) or f(a, b-1) or f(a-rangeL(i), b-rangeR(i)), i = 0, 1, 2
f(0, 0) = True
 记忆化搜索，O((E - D)^2) 时间和空间复杂度。
关于更好的解法，可以理解成：求空间中夹在第一象限和两个平面中的整数点。估计用几何解法能做到复杂度与 D, E 无关？
*/

/*
 best way O(N) N = machines.size()
 1台咖啡机 L1,H1
 
 def get_low_num(low,L1):
  if low % L1 == 0: return low / L1
  return low/L1 + 1
 
 if get_low_num(low,L1) <= high/H1 return true;
 
 Or
 find x， 使得 (low-x) / L1 <= (high-x) / H1 暂时不考虑 不能整除情况
 x >= (H1 * low - L1 * High) / (H1 - L1)
 
 find y >= x get_low_num(low - y, L1) <= (high-y) / H1
 
 第2台咖啡机 L2 H2, 看能否得到可乐量在 [min(y, low), high] 之间
 
 
*/
struct CokeMachie {
int cmin, cmax; 
};

//类似背包 把cmin当重量 cmax当价值，不同的是求价值最小。然后重量在[low,high]之间 价值也<=high 说明有解
bool CombineCokeMachinesWithDP(const vector<CokeMachie> &machines, const int low, const int high) {
    vector<int> f(high + 1, INT_MAX);
    f[0] = 0;
    for (int i = 0; i < machinies.size(); i++)
    for (int j = 0; j <= high - machinies[i].cmin; j++)
    {
        if (f[j] < INT_MAX)
                f[j + machinies[i].cmin] = min(f[j + machinies[i].cmin], f[j] + machinies[i].cmax); 

    }
    
    for (int j = low; j <= high; j++) 
        if (f[j] <= high) return true;
    return false;
}
