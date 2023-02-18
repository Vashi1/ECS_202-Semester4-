#include <stdio.h>
int main(){
	char *cp;
	printf("%lu%lu%lu", sizeof(char *), sizeof(*cp), sizeof(cp));
}
