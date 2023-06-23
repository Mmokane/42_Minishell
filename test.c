#include "includes/minishell.h"

void	check_tokens(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	printf("--------CHECK_TOKENS-----------\n");
	while (tmp)
	{
		printf("content = %s\n", tmp->content);
		printf("type    = %d\n", tmp->type);
		tmp = tmp->next;
	}
	printf("----------------------------\n");
}
int main()
{
    char *input;
    input = readline("./minishell : ");
    checke_tokens(input);
}