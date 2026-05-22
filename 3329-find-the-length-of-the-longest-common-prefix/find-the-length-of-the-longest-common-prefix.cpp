// Trie Node Definition
class TrieNode {
public:
    TrieNode* children[10];  // Only 10 digits (0-9)
    TrieNode() {
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
    }
};

// Trie Class for inserting and finding longest prefix
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert number as a string into the Trie
    void insert(const string& numStr) {
        TrieNode* node = root;
        for (char digit : numStr) {
            int idx = digit - '0';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
    }

    // Find longest common prefix between the given number and numbers in the Trie
    int longestCommonPrefix(const string& numStr) {
        TrieNode* node = root;
        int prefixLength = 0;
        for (char digit : numStr) {
            int idx = digit - '0';
            if (node->children[idx]) {
                prefixLength++;
                node = node->children[idx];
            } else {
                break;  // Stop when there is no match
            }
        }
        return prefixLength;
    }
};

class Solution {
public:
    // Function to find the longest common prefix length between two arrays
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        
        // Insert all numbers from arr2 into the Trie as strings
        for (int num : arr2) {
            trie.insert(to_string(num));
        }

        int maxLength = 0;  // Track the maximum common prefix length
        
        // For each number in arr1, find the longest common prefix with numbers in the Trie
        for (int num : arr1) {
            maxLength = max(maxLength, trie.longestCommonPrefix(to_string(num)));
        }
        
        return maxLength;  // Return the maximum common prefix length found
    }
};