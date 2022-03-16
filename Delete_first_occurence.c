#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* delete_first(char *s, char *pattern)
{
	char *res = malloc(30 * sizeof(*res));
	char *substr = strstr(s, pattern);

	if(!substr) {
		strcpy(res, s);
		return res;
	}

	char *ptr_start = s;
	int difference = substr - ptr_start;
	memcpy(res, s, difference);
	int last_chars = strlen(s) - strlen(pattern) - difference;
	char *ptr_to_last_chars = ptr_start + strlen(s) - last_chars;
	for (int i = 0; i < last_chars; ++i) {
		*(res + difference + i) = *(ptr_to_last_chars + i);
	}
	return res;
}

int main(){
	char *s = "Ana are mere";
	char *pattern = "re";
	char *new_s = delete_first(s, pattern);
	// Decomentati linia dupa ce ati implementat functia delete_first.
	printf("%s\n", new_s);
	free(new_s);
	return 0;
}
