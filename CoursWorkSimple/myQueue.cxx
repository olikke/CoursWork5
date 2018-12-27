myLibrary::myLibrary():
	Remember (NULL),
	Head (NULL),
	ListCount (0)
{

}

myLibrary::~myLibrary()
{
	Clear();
}

void myLibrary::RestartSearch()
{
	Remember=Head;
}

bool myLibrary::Next(string &str)
{
	if (Remember) 
	{
		str=Remember->Word;
		Remember=Remember->Next;
		return true;
	}
	return false;
}

bool myLibrary::Search(string &str)
{
	while (Remember && (Remember->Word<=str))
	{
		if (str==Remember->Word) return true;
		Remember=Remember->Next;
	}	
	return false;
}

void myLibrary::PrintAll()
{	
	if (Head==NULL) return;
	pElement q=Head;
	while(q) 
	{
		cout<<q->Word<<endl;
		q=q->Next;	
	}	
	cout<<endl;
}

int myLibrary::mCount()
{
	return ListCount;
}

void myLibrary::Clear()
{
	while (Head)
	{
		pElement temp=Head->Next;
		delete Head;
		Head=temp;
	}
}

void myLibrary::AddNewWord(const string &NewWord)
{
	pElement NewElement=new Element (NewWord);
	pElement p=FindPlace(NewWord);
	if (p && p->Word==NewWord) 
	{
		//это слово-повтор, в список не добавляем. Обязательно почистим :))
		delete NewElement;
		return;
	}
	AddBefore(p,NewElement);
}

pElement myLibrary::FindPlace(string NewWord)
{
	pElement q=Head;
	while (q && NewWord>q->Word)
		q=q->Next;
	return q;	
}

void myLibrary::AddLast(pElement NewElement)
{
	//если список был пуст
	if (Head==NULL)
	{
		Head=NewElement;	
		return;	
	}
	//в конец списка
	pElement q=Head;
	while(q->Next) q=q->Next;
	q->Next=NewElement;		
};

void myLibrary::AddBefore(pElement p, pElement NewElement)
{
	ListCount++;
	if (p==NULL)
	{
		AddLast(NewElement);
		return;		
	}
	if (p==Head)
	{	
		Head=NewElement;
		NewElement->Next=p;
		return;
	}
	//реально вставили после заданного узла
	NewElement->Next=p->Next;
	p->Next=NewElement;
	//а потом поменяли данные
	NewElement->swap(p);
}


