

void checkLiterals(char* reg, char* target, char* new)
{

	if(reg[0] == '\\')
	{
		new = (reg + 1);
		target = reg[1];
		return true;
	}
	return false;
}

void checkClasses(char* reg, char* target, char* new)
{
	bool breaking = false;
	char t[10000] = "";
	int j = 0;
	
	if(reg[0] == '[')
	{
		for(int i = 1; reg[i] != 0; i++)
		{
			t[j] = reg[i];
			j += 1;
			if(reg[i] == ']')
			{
				new = (reg + i);
				breaking = true;
				break;
			}
		}
		if(breaking)
		{
			strncpy(target, t, j + 1);
			return true;
		}
	}
	return false
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

	char* new;
	char* t = getTarget(reg, new);

	for(int i = 0; text[i] != 0; i++)
	{
		if(checkTarget(text[i],t))
		{
			
			t = getTarget(new, new);
			if(new[0] == 0) return true;
			
		}
		else
		{
			return false;
		}
	}

	return false;
}

char* getTarget(char* reg, char* new)
{

	char* target;
	
	if(checkLiterals(reg, target, new)) return target;
	if(checkGroup(reg, target, new)) return target;
	
	new = (reg + 1);
	return reg[0];

}

bool checkTarget(char c, char* t)
{

	for(int i = 0; t[i] != 0; i++)
	{
		if(c == t[i]) return true;
		if(t[i] == '.') return true;
	}
	return false;

}
