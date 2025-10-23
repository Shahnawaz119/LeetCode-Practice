class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        int number_of_eat=n/2;
        unordered_set<int> st(candyType.begin(),candyType.end());
        return min((int)st.size(),number_of_eat);
    }
};