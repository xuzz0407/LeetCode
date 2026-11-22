class ProductOfNumbers {
    vector<int> p{1};
public:
    void add(int x){x?p.push_back(p.back()*x):p.assign(1,1);}
    int getProduct(int k){return k<p.size()?p.back()/p.rbegin()[k]:0;}
};