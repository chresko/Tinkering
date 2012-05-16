#include <stdio.h>
#include <string.h>

void removeChar(char* array, char r);
void removeChar(char* s, char r) {
	char* d = s;
    while (*s) {
   		if (*s != r) {
			*d++ = *s;
		}
		++s;
	}
	*d = '\0';
}

int main(int argc, char *argv[]) {
	char array[6] = {'a','b','c','a','b','c'};
	
	removeChar(array, 'b');
	for (int i = 0; i < strlen(array); ++i) {
		printf("%c", array[i]);
	}
}