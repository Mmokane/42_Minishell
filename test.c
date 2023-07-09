#include "includes/minishell.h"

int main()
{
	int i = 1;
	if (i == 0)
	{
		printf("%s", "GOOD");
	}
	else
		write(2, "`BAD'\n", 7);
}