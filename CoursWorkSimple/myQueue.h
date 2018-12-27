#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Element
{
	string Word;	
	Element* Next;	
	Element(string W): Word(W), Next(NULL) {};
	void swap(Element* p) 
	{
		std::swap(Word,p->Word);
	};
};
typedef Element* pElement;

class myLibrary
{
	protected:
		pElement Remember;
		pElement Head;
		void Clear();
		void AddBefore(pElement p, pElement NewElement);
		void AddLast(pElement NewElement);
		int  ListCount;
		pElement FindPlace(string NewWord);
	public:
		myLibrary(); 
		~myLibrary();
		void AddNewWord(const string &NewWord);
		void AddNewWord(const string &NewWord, const int Numb);
		void PrintAll();
		int  mCount();
		void RestartSearch();
		bool Next(string &str);
		bool Search(string &str);		
};

#include "myQueue.cxx"

