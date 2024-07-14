#include "trie.h"
#include <iostream>
#include <cstring>
using std::cout, std::endl;

Trie::Trie()
{
	root = NULL;
}

// Returns new trie node (initialized to NULLs)
struct TrieNode* Trie::getNode(void)
{
	TrieNode* newNode;
	newNode->isWordEnd = 0;
	for (int i = 0; i < ALPHABET_SIZE; i++) newNode->children[i] = nullptr;
	return newNode;
}

// If not present, inserts key into trie. If the
// key is prefix of trie node, just marks leaf node
void Trie::insert(struct TrieNode* root, const std::string key)
{
	TrieNode* node = root;
	for (char c : key)
	{
		if(node->children[c-'a'] != nullptr) node = node->children[c-'a'];
		else{
			node -> children[c - 'a'] = getNode();
			node = node -> children[c - 'a'];
		}
	}
	node->isWordEnd = 1;
	
}

bool Trie::search(struct TrieNode *root, std::string key)
{
	TrieNode* node = root;
	for (char c : key)
	{
		if(node->children[c-'a']!=nullptr) node = node->children[c-'a'];
		else return 0;
	}
	if(node->isWordEnd == 0) return 0;
	
	return 1;
}

// Returns 0 if current node has a child
// If all children are NULL, return 1.
bool Trie::isLastNode(struct TrieNode* root)
{
	if(root->isWordEnd == 1) return 1;
	else return 0;
}

// Recursive function to print auto-suggestions for given
// node.
void Trie::suggestionsRec(struct TrieNode* root,
					std::string currPrefix)
{
	for (int i = 0; i < ALPHABET_SIZE; i++) if(root->children[i]!=nullptr) suggestionsRec(root->children[i], currPrefix+ char(i+'a'));
	if(root->isWordEnd == 1) cout << currPrefix << endl;
	
	// found a std::string in Trie with the given prefix
}

// print suggestions for given query prefix.
int Trie::printAutoSuggestions(TrieNode* root, const std::string query)
{
	TrieNode* node = root;
	for (char c: query)
	{
		if(node->children[c-'a']!=nullptr) node = node->children[c-'a'];
		else return -1;
	}
	
	suggestionsRec(node, query);
}

// Process the file "lorem.txt" to insert the words in lorem.txt and store the relevant context as needed.
void Trie::processContext()
{
	
}
