#ifndef RGX_H
#define RGX_H

void checkLiterals(char* reg, char* target, char* new);
void checkClasses(char* reg, char* target, char* new);
bool callRegex(char* reg, char* text);
bool parseReg(char* reg, char* text);
char* getTarget(char* reg, char* new);
bool checkTarget(char c, char* t);


#endif

