#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool canTransform(string lhs, string rhs) {
        int size = lhs.size();
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (lhs[i] != rhs[i])
                count++;
        }
        if (count == 1)
            return true;
        return false;        
    }

    bool isMemberOfVector(vector<string> v, string s) {
        int size = v.size();
        for (int i = 0 ; i < size; i++)
            if (v[i] == s)
                return true;
        return false;
    }


    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue< vector<string> > q;

        
        unordered_set<string>::iterator it;
        for (it = wordList.begin(); it != wordList.end(); ++it) {
            if (canTransform(beginWord, *it)) {
                if (*it == endWord)
                    return 2;
                vector<string> t;
                // t.push_back(begin);                
                t.push_back(*it);   
                q.push(t);
            }
        }


        // cout << "q.size( " << q.size() << " )" << endl;

        while (!q.empty()) {
            // q.front();
            unordered_set<string>::iterator it;

            for (it = wordList.begin(); it != wordList.end(); ++it) {                
                if (!isMemberOfVector(q.front(), *it)) {
                    // cout << q.front().back() << " " << *it << endl;

                   if (canTransform(q.front().back(), endWord))                     
	                    return 2 + q.front().size();
                   
                   if (canTransform(q.front().back(), *it)) {
                       if (*it == endWord)
                            return 1 + q.front().size();
                       vector<string> t = q.front();
                       t.push_back(*it);
	                   q.push(t);
                   }
                }
            }

            q.pop();
        }
        
        return 0;
    }
};

int main() {
    // beginWord = "hit"
    // endWord = "cog"
    // worldList = "hot", "dot", "dog", "lot", "log"
    // As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog"
#if 0
    string beginWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordList;

    wordList.insert("hot");
    wordList.insert("dot");
    wordList.insert("dog");
    wordList.insert("lot");
    wordList.insert("log");
#endif
#if 0
    string beginWord = "a";
    string endWord = "c";
    unordered_set<string> wordList;
    wordList.insert("a");
    wordList.insert("b");
    wordList.insert("c");
#endif
#if 1
    string beginWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordList;

    wordList.insert("hot");
    wordList.insert("cog");
    wordList.insert("dot");
    wordList.insert("dog");
    wordList.insert("hit");
    wordList.insert("lot");
    wordList.insert("log");
#endif
    Solution s;
    cout << s.ladderLength(beginWord, endWord, wordList) << endl;
    // cout << s.canTransform("hot", "dot") << endl;
    // cout << s.canTransform("hat", "dot") << endl;
    return 0;
}