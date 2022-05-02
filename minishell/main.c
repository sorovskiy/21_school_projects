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

int main(int argc, char **argv, char **env)
{
	int n;
	t_list	*stack = NULL, *lst;

	// gaps, slash
//	char *com = ft_strdup("\"sdf\"com\\\"ma | nd\"lsdkcomma\"nd\\xx");
	// dollar($)
//	char *com = ft_strdup("\"sdf\"com$USER ma|nd\"lsdkcomma\"nd");
//	char *red = ft_strdup("$USER ls \"-l ls\"k | echo $US\'ER|ef\'sd\"df ; gssd\"d ; cat -e abc");
	// multiple command
//	char *com = ft_strdup("ls \"-l ls\"k first > second_out.txt se > firstout.txt | echo $US\'ER|ef\'s d\"df  ; gssd\"d ; cat -e abc > outfile.txt ");
	// redirects
	char *com = ft_strdup("< main.cs ls -l -a > file1 > file2 > file3");

	printf("%s\n\n", com);


	n = stack_init(com, &stack);

	printf("Preparser check result: n = %d\n\n", n);
	ft_lstprint(stack);


	lst = stack;
	while (lst)
	{
		printf("\nBefore parser: %s\n", lst->pre_com);
		parser(lst, env);
		if (errno != 0)
		{
			printf("Errno ist't null\n");
			return errno;
		}
		printf("After parser: %s\n", lst->pre_com);
//		while (*lst->com)
//		{
//			printf("%s ", *lst->com);
//			lst->com = lst->com + 1;
//		}
//		printf("\n");
		lst = lst->next;
	}

//
	printf("\n");
	ft_lstprint(stack);


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