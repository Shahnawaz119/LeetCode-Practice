class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // Step 1: Create a mapping of each character to its position
        vector<int> index(26);
        for (int i = 0; i < order.size(); i++) {
            index[order[i] - 'a'] = i;
        }

        // Step 2: Compare each adjacent pair of words
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            bool valid = false;

            for (int j = 0; j < min(word1.size(), word2.size()); j++) {
                if (word1[j] != word2[j]) {
                    if (index[word1[j] - 'a'] > index[word2[j] - 'a']) {
                        return false;
                    }
                    valid = true;
                    break;
                }
            }

            // If words are identical up to the length of word2, 
            // but word1 is longer, it's invalid (e.g., "apple" > "app")
            if (!valid && word1.size() > word2.size()) {
                return false;
            }
        }

        return true;
    }
};
