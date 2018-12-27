#include <iostream>
#include <string>
#include <cstring>

using namespace std;



struct Element
{
	string Word;
	int Numb;	
	bool Flag;
	Element* Next;	
	Element(string W, int N): Word(W), Numb(N),Flag(false), Next(NULL) {};
	void swap(Element* p) 
	{
		std::swap(Word,p->Word);
		std::swap(Numb,p->Numb);
		std::swap(Flag,p->Flag);
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
		virtual ~myLibrary();
		void AddNewWord(const string &NewWord);
		void PrintAll();
		int  mCount();
		void RestartSearch();
		bool Search(string &str);		
};

class myPhrase: public myLibrary
{
	public:
	void AddNewWord(const string &NewWord, const int Numb);
	void SortByNumber();
	bool Next();
	bool Read(string &str);
	bool Read(string &str, bool &Flag);
	void WriteFlag(bool flag);
};

#include "cLibrary.cxx"
#include "cPhrase.cxx"

