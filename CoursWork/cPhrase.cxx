void myPhrase::SortByNumber()
{
	//сортировка пузырьком для односвязанного списка выглядела как то очень логично
	pElement p=Head;
	bool flag;
	int i=0;
	do
	{
		flag=false;
		
			for (int j=ListCount-2;j>=i;j--)
			{
				if (p->Numb>p->Next->Numb)
				{
					p->swap(p->Next); //вот это не очень ((
					flag=true;
				}
				p=p->Next;
			}
		p=Head;
		i++;			
	} while (flag);
}

void myPhrase::AddNewWord(const string &NewWord, const int Numb)
{
	pElement NewElement=new Element (NewWord,Numb);
	pElement p=FindPlace(NewWord);
	//В идентичном методе сLibrary тут удалялись повторы слов. Для класса Phrase этого делать нельзя:)
	AddBefore(p,NewElement);	
}

bool myPhrase::Next()
{
	if (Remember->Next==NULL) return false; 
	Remember=Remember->Next;
	return true;
}

void myPhrase::WriteFlag(bool flag)
{
	Remember->Flag=flag;
}

bool myPhrase::Read(string &str)
{
	if (Remember) 
	{
		str=Remember->Word;
		return true;
	}
	return false;
}

bool myPhrase::Read(string &str, bool &Flag)
{
	if (Remember) 
	{
		str=Remember->Word;
		Flag=Remember->Flag;
		return true;
	}
	return false;
}
