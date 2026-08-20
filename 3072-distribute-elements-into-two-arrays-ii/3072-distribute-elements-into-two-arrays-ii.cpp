void update(vector<int>& tree, int x) {
    while (x < tree.size()) {
        tree[x]++;
        x += x & -x;
    }
}

int query(vector<int>& tree, int x) {
    int sum = 0;

    while (x > 0) {
        sum += tree[x];
        x -= x & -x;
    }

    return sum;
}

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> v = nums;

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        int m = v.size();

        vector<int> tree1(m + 1);
        vector<int> tree2(m + 1);

        vector<int> arr1 = {nums[0]};
        vector<int> arr2 = {nums[1]};

        int idx1 = lower_bound(v.begin(), v.end(), nums[0]) - v.begin() + 1;
        int idx2 = lower_bound(v.begin(), v.end(), nums[1]) - v.begin() + 1;

        update(tree1, idx1);
        update(tree2, idx2);

        for (int i = 2; i < nums.size(); i++) {
            int idx = lower_bound(v.begin(), v.end(), nums[i]) - v.begin() + 1;

            int greater1 = arr1.size() - query(tree1, idx);
            int greater2 = arr2.size() - query(tree2, idx);

            if (greater1 > greater2 ||
                (greater1 == greater2 && arr1.size() <= arr2.size())) {
                arr1.push_back(nums[i]);
                update(tree1, idx);
            }
            else {
                arr2.push_back(nums[i]);
                update(tree2, idx);
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        return arr1;
    }
};