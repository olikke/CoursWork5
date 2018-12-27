#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <chrono>

#include "myQueue.h"

using namespace std;

/*
	*Чистим слово от знаков препинания, открывающих, закрывающих скобок, кавычек и прочей нечести.
	*Поиск производится с начала слова до первой встреченной буквы (или до конца слова) 
	*А потом в обратном цикле с конца слова 
	*Знаки препинания, вставленные в середину слова и не окруженные пробелом (хоть с 1 стороны)
	*не рассматриваются, по причине неграмотных входных данных. В нормальном русском языке такого не бывает :)
*/
void ClearWord(string &str)
{
	if (str.empty()) return;
	for (unsigned int i=0; i<str.length(); i++)
	{ 
		if (ispunct(str[i])) 
		{
			str.erase(i,1); 
			i--;
		}	
		else break;
	}
	if (str.empty()) return;
	for(unsigned int i = str.length()-1; i >=0; i--)
	{ 
		if(ispunct(str[i])) 
		{
			str.erase(i,1);	
		} 
		else break;
	} 
}

int main(int argc, char **argv)
{
	if (argc==1)
	{
		cout<<  "Неверные входные данные программы."<<endl<<
				"Формат вызова программы: ./CourseWork Library.txt, где"<<
				"Library.txt - имя файла исходного текста (библиотеки слов)."<< endl;
		return 0;			
	}	
	
	string sPhrase;	
	string temp;
	
	cout<<"Введтите фразу:..."<<endl;
	//прочитали строку целиком
	std::getline(std::cin,sPhrase);	
	
	//для разбиения на слова исользовали поток stringstream, потому что у него есть операторы <<, >> и т.д. Удобно
	stringstream x;
	x<<sPhrase;
	
	ifstream in(argv[1]);
	if (!in.is_open())
	{
		cout<<"Имя файла не верное или файл не может быть прочитан."<<endl;
		return false;
	}	
	
	//считка с файла
	myLibrary* Library=new myLibrary();	
	while (!in.eof())
	{
		in>>temp;
		ClearWord(temp);
		if (temp.empty()) continue;		
		Library->AddNewWord(temp);
	}
	in.close();
		
	cout<<"Формирование библиотеки закончено. Всего: "<<Library->mCount()<< "слов."<< endl;
	
	auto begin=chrono::steady_clock::now();	
	//Установка указателя поиска на начало списка.
	Library->RestartSearch();
	
	//search
	cout<<"Исходная фраза: "<<endl<<sPhrase<<endl<<"Обработанная фраза: "<<endl;	
	while (x>>temp)
	{
		ClearWord(temp);
		if (temp.empty()) continue;		
		if (Library->Search(temp))
		for (auto x:temp) cout<<x<<" ";	else cout<<"<"<<temp<<">";
		cout<<" ";
		Library->RestartSearch();				
	}	
	cout<<endl;
	auto end=chrono::steady_clock::now();		
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	cout<<"Время, затраченное на обработку: "<<elapsed_ms.count()<<"mcs"<<endl;
	
	
	
	delete (Library);
	return 0;
}

