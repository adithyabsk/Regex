#ifndef RGX_H
#define RGX_H

bool checkLiterals(char* reg, char** target, char** new, int li);
bool checkClasses(char* reg, char** target, char** new);
bool callRegex(char* reg, char* text);
bool parseReg(char* reg, char* text);
char* getTarget(char* reg, char** new, int li);
bool checkTarget(char c, char* t, int* lastIndex);


#endif

