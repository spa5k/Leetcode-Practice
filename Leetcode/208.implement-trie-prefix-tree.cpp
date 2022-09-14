/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (59.92%)
 * Likes:    8037
 * Dislikes: 100
 * Total Accepted:    660.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to
 * efficiently store and retrieve keys in a dataset of strings. There are
 * various applications of this data structure, such as autocomplete and
 * spellchecker.
 *
 * Implement the Trie class:
 *
 *
 * Trie() Initializes the trie object.
 * void insert(String word) Inserts the string word into the trie.
 * boolean search(String word) Returns true if the string word is in the trie
 * (i.e., was inserted before), and false otherwise.
 * boolean startsWith(String prefix) Returns true if there is a previously
 * inserted string word that has the prefix prefix, and false otherwise.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * Output
 * [null, null, true, false, true, null, true]
 *
 * Explanation
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // return True
 * trie.search("app");     // return False
 * trie.startsWith("app"); // return True
 * trie.insert("app");
 * trie.search("app");     // return True
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length, prefix.length <= 2000
 * word and prefix consist only of lowercase English letters.
 * At most 3 * 10^4 calls in total will be made to insert, search, and
 * startsWith.
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class TrieNode
{
public:
  TrieNode *links[26];
  bool isEnd = false;

  TrieNode *get(char ch)
  {
    return links[ch - 'a'];
  }
  void put(char ch, TrieNode *node)
  {
    links[ch - 'a'] = node;
  }
  bool containsKey(char ch)
  {
    return (links[ch - 'a'] != nullptr);
  }
};

class Trie
{
private:
  TrieNode *root;

public:
  Trie()
  {
    root = new TrieNode();
  }

  void insert(string word)
  {
    TrieNode *node = root;
    for (int i = 0; i < word.size(); i++)
    {
      if (node->containsKey(word[i]))
      {
        node->put(word[i], new TrieNode());
      }
      node = node->get(word[i]);
    }
    node->isEnd = true;
  }

  bool search(string word)
  {
    TrieNode *node = root;
    for (int i = 0; i < word.size(); i++)
    {
      if (node->containsKey(word[i]))
      {
        return false;
      }
      node = node->get(word[i]);
    }
    return node->isEnd;
  }

  bool startsWith(string prefix)
  {
    TrieNode *node = root;
    for (int i = 0; i < prefix.length(); i++)
    {
      if (node->links[prefix[i] - 'a'] == nullptr)
        return false;
      node = node->links[prefix[i] - 'a'];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
