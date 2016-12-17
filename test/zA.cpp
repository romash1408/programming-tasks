#include <iostream>

using namespace std;

char *A[130], *E[130];
int c;

bool dump()
{
	if(c == 0) return false;
	if(c == 1)
	{
		for(char *i = A[0]; i != E[0]; ++i)
			cout << *i;
	}
	else
	{
		for(int i = 0; i < c; ++i)
			cout << *A[i];
		cout << " (";
		for(int i = 0; i < c; ++i)
		{
			for(char *j = A[i]; j != E[i]; ++j)
				cout << *j;
			cout << (i + 1 == c ? ')' : ' ');
		}
	}
	c = 0;
	return true;
}

bool word(char *start, char *end)
{
	A[c] = start;
	E[c] = end;
	bool f = true;
	
	if(*start < 'A' || *start > 'Z' || end - start == 1) f = false;
	else
	{
		for(char *i = start + 1; i != end; ++i)
		{
			if(*i < 'a' || *i > 'z')
			{
				f = false;
				break;
			}
		}
	}
	
	if(f)
	{
		c++;
	}
	else
	{
		if(dump())
			cout << ' ';
		for(char *i = start; i != end; ++i)
		{
			cout << *i;
		}
	}
	return f;
}

void abbr(char *i, char *end)
{
	c = 0;
	char *from = i;
	for(; i != end; ++i)
	{
		if(*i == ' '){
			if(!word(from, i))
				cout << ' ';
			from = i + 1;
		}
	}
	word(from, i);
	dump();
}

int main()
{
	char s[130];
	while(gets(s))
	{
		char *i, *from;
		for(i = from = s; *i; ++i)
		{
			if(*i == '.' || *i == ',')
			{
				abbr(from, i);
				from = i + 1;
				cout << *i;
			}
		}
		abbr(from, i);
		cout << endl;
	}
	return 0;
}