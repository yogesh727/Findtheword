#include <bits/stdc++.h> 
using namespace std; 

// the Structure for  the Trie 

struct T{ 
	bool isName; 
	unordered_map<char, T*> m; 
	    int fre; 
}; 


// Function 
// create a new Trie node 
T* NewTNode() 
{ 
	T* node = new T; 
	node->isName = false; 
	return node; 
} 


//The Function to insert a student with its frequency
// in the dictionary built using a Trie 


void insertion(T*& root, const string& str, 
			const int& frequency) 
{ 

	if (root == NULL) 
		root = NewTNode(); 

	T* tmp = root; 

	for (int j = 0; j< str.length(); j++) 
    { 
		char y = str[j]; 

		//  new node if there is no path 
		if (tmp->m.find(y) == tmp->m.end()) 
			tmp->m[y] = NewTNode(); 

		tmp = tmp->m[y]; 
	} 

	tmp->isName = true; 
	tmp->fre = frequency; 
} 


// Function to search a student in the Trie
//return its frequency if it exists

 int search(T * root, string word)
 {
     if(root == NULL) 
	 return -1;

     T* tmp = root; 

	// Search a student in the Trie 

	for (int i = 0; i < word.length(); i++)
	 { 
		tmp = tmp->m[word[i]]; 
		if (tmp == NULL) 
			return -1; 
	} 

    if (tmp->isName) 
		return tmp->fre; 
    return -1;    
 }

// Main function
 
int main() 
{ 
	T* root = NULL; 

	// Build the dictionary 
	ifstream myFile;
	myFile.open("EnglishDictionary.csv");
	string lines, words;
	string fre;
	vector<pair<string, int>> vec;
	int f;

	while(getline(myFile, lines))
	{
		stringstream ss(lines);
		getline(ss, words, ',');
		getline(ss, fre, ',');
		f = stoi(fre);
		vec.push_back({words,f});
	}

	for(auto it : vec)
	{
		insertion(root, it.first, it.second);
	}
	

    int ans = search(root, "Rahul");
	if(ans != -1)
     cout << "YES " << ans << endl;
	else 
	cout << "NO\n";

	return 0;              
}