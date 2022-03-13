/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:24:06 by                   #+#    #+#             */
/*   Updated: 2022/01/30 20:21:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
// " ' $ ; | > >> <
//
//int	stack_init2(t_list **stack_a, int argc, char **argv)
//{
//	int	n;
//
//	*stack_a = NULL;
//	n = 0;
//	while (argc-- > 1)
//	{
//		ft_push(stack_a, ft_lstnew(0));
//		n++;
//	}
//	return (n);
//}


int main(int argc, char **argv, char **env)
{
	int n;
	t_list	*stack = NULL;

//	char *com = ft_strdup("\"sdf\"com\\\"ma|nd\"lsdkcomma\"nd\\");
	char *com = ft_strdup("\"sdf\"com$USE ma|nd\"lsdkcomma\"nd");
//	char *com = ft_strdup("ls \"-l ls\"k | echo $US\'ER|ef\'sd\"df ; gssd\"d ; cat -e abc");


	printf("%s\n", com);

//	n = pre_parser(com);


//	stack_init(com, &stack);
//
	printf("\nAll is OK, n = %d\n", n);
//
//	ft_lstprint(stack);


	parser(com, env);

//	while(1);
	return 0;
}



























//int main2(void)
//{
//	FILE *fp;
//	struct stat buff;
//	if((fp=fopen("test", "rb"))==NULL) {
//		printf("Cannot open file.\n");
//		exit (1);
//	}
//	/* заполнение структуры типа stat */
//	stat("test", &buff);
//	printf("Size of the file is: %ld, type: %ld\n", buff.st_size, buff.st_rdev);
//	fclose(fp);
//	return 0;
//}