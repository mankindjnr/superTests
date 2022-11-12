#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "Future Alpha, aremos mankindjnr";

	int len = strlen(str);

	printf("length is %d\n", len);

	for (int i = 0; str[i] != '\0'; i++)
	{
		printf("break [%d] : %s\n", i, str[i]);
	}
	return (0);
}
