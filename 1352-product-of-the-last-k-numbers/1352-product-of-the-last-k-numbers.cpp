class ProductOfNumbers {
    vector<int> p{1};
public:
    ProductOfNumbers() {}
    void add(int num) { num ? p.push_back(p.back()*num) : p.assign(1, 1);}
    int getProduct(int k) { return k>=p.size() ? 0 : p.back()/p[p.size()-k-1];}
};