#include <stdlib.h>
#include <stdio.h> 	/* for ////printf */
#include <string.h>	/* for strlen */
#include <stdbool.h>

#include "regex.h"

bool inInfinite = false;

bool checkLiterals(char* reg, char** target, char** new, int li)
{
	if(reg[0] == '\\')
	{
		*new = (reg + 2);
		(*target)[0] = reg[1];
		(*target)[1] = 0;
		return true;
	}


	if(inInfinite && li == 1)
	{
		inInfinite = false;
		*new = reg + 3;
		if((*new)[0] == 0){
			(*(target))[0] = 0;
			return true;
		}
		return checkLiterals(*new, target, new, -1);

		return false;
	}

	if(reg[1] == '*' || (inInfinite && li == 0))
	{
		(*(target))[0] = reg[0];
		(*(target))[1] = reg[2];
		if(reg[2] == 0)
		{
			(*new)[0] = 0;
			(*(target))[0] = 0;
			return true;
		}
		(*(target))[2] = 0;
		*new = reg;
		inInfinite = true;
		return true;
	}

	if(reg[1] == '+')
	{
		(*target)[0] = reg[0];
		(*target)[2] = 0;
		inInfinite = true;
		*new = reg;
		return true;
	}

	return false;
}

bool checkClasses(char* reg, char** target, char** new)
{
	bool breaking = false;
	char t[1000] = "";
	int j = 0;
	
	if(reg[0] == '[')
	{
		for(int i = 1; reg[i] != 0; i++)
		{

			if(reg[i] == ']')
			{
				*new = (reg + (i+1));
				breaking = true;
				break;
			}

			t[j] = reg[i];
			j += 1;
		}
		if(breaking)
		{
			t[j + 1] = 0;
			strcpy(*target, t);
			return true;
		}
	}
	return false;
}

bool callRegex(char* reg, char* text)
{
	for(int i = 0; text[i] != 0; i++)
	{
		if(parseReg(reg, (text + i))) return true;
	}
	return false;

}

bool parseReg(char* reg, char* text)
{
	int lastIndex = -1; //Last index of search string matched
	char* new = (char*)malloc(100*sizeof(char));
	char* t = getTarget(reg, &new, lastIndex);



	for(int i = 0; text[i] != 0; i++)
	{
		if(checkTarget(text[i],t,&lastIndex))
		{
			
			if(new[0] == 0) return true;
	
			t = getTarget(new, &new, lastIndex);

			if(new[0] == 0) return true;

		}
		else
		{
			return false;
		}
	}

	return false;
}

char* getTarget(char* reg, char** new, int li)
{

	char* target = (char*)malloc(100*sizeof(char));
	if(checkLiterals(reg, &target, new, li)) return target;
	if((*new)[0] != 0)
	{
		reg = (*new);
	}
	if(checkClasses(reg, &target, new)) return target;

	
	*new = &(reg[1]);

	char *temp = malloc(sizeof(char)*100);
	temp[0] = reg[0];
	temp[1] = 0;


	return temp;

}

bool checkTarget(char c, char* t, int* lastIndex)
{
	for(int i = 0; t[i] != 0; i++)
	{

		if(c == t[i]) 
		{
			*lastIndex = i;
			return true;
		}
		if(t[i] == '.')
		{
			*lastIndex = i;
			return true;
		}
	}
	*lastIndex = -1;
	return false;

}

