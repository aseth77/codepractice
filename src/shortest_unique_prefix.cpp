/*
Find shortest unique prefix to represent each word in the list.
Example:
Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
NOTE : Assume that no word is prefix of another. In other words, the representation is always possible.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int NUM_OF_ALPHABETS = 26;

#define TRIE_GET_INDEX(x)     (x - 'a')

class Solution {
public:
  vector<string> prefix(vector<string> &A);
};

typedef struct _TrieNode {
  struct _TrieNode* children[NUM_OF_ALPHABETS];
  bool isLeaf;  //is Full world
  int frequency;
} TrieNode;


TrieNode *create_node()
{
  TrieNode *node = new  TrieNode;
    
  node->isLeaf = false;
  node->frequency = 1;
    
  for (unsigned int i = 0; i < NUM_OF_ALPHABETS; i++)
    node->children[i] = NULL;
        
  return node;    
}

void add_word(TrieNode *root, string word) 
{
  TrieNode *pNode = root;
  int wordlen = word.length();
    
  for(unsigned int i = 0; i < wordlen; i++) {
    int index = TRIE_GET_INDEX(word[i]);
        
    if(!pNode->children[index])
      pNode->children[index] = create_node();
    else
      pNode->children[index]->frequency++;
            
    pNode = pNode->children[index];
  }
    
  pNode->isLeaf = true;
    
}

string query_word(TrieNode *root, string str) 
{
  TrieNode*pNode = root;
  string ans = "";
  int i = 0;
  int wordlen = str.size();

  for(unsigned int i = 0; i < wordlen; i++) {
    int index = TRIE_GET_INDEX(str[i]);
    ans += str[i];
    if((pNode->children[index])->frequency == 1)
      return ans;
    pNode = pNode->children[index];
  }
  return "";
}

vector<string> Solution::prefix(vector<string> &A) {
  // Do not write main() function.
  // Do not read input, instead use the arguments to the function.
  // Do not print the output, instead return values as specified
  // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
  vector<string> result;
    
  TrieNode *root = create_node();
    
  for (unsigned int i = 0; i < A.size(); i++) {
    add_word(root, A[i]);
  }
    
    
  for (unsigned int i = 0; i < A.size(); i++) {
    string ans = query_word(root, A[i]);
        
    if(!ans.empty())
      result.push_back(ans);
        
  }
    
  return result;
}


int main(int argc, char **argv)
{
  vector<string> input;
  vector<string> output;

  for(unsigned i = 0; i < argc; i++) {
    input.push_back(argv[i]);
  }
  
  Solution s;
  output = s.prefix(input);

  for(vector<string>::iterator it = output.begin(); it != output.end(); ++it) {
    cout << ' ' << *it;
  }
  cout << '\n';

  return 0;

}

