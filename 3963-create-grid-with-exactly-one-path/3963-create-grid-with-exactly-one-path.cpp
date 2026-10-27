class Solution {
public:
    vector<string> createGrid(int m, int n) {
        return [&]{vector<string> g(m,string(n-1,'#')+".");g[0]=string(n,'.');return g;}();
    }
};