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

char *slash(char *s, int *i)
{
	char *tmp1, *tmp2;
	char *res;

	tmp1 = ft_substr(s, 0, *i);
	tmp2 = ft_strdup(s + *i + 1);
//	printf("tmp1: %s\n", tmp1);
//	printf("tmp2: %s\n", tmp2);

	res = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);

	printf("res: %s\n", res);

	free(s);

	return res;
}

char *gap(char *s, int *i)
{
	int j;
	char *tmp1, *tmp2, *tmp3;
	char *res1, *res2;

	j = *i;
	while (s[++(*i)] != '\'')
		;
	tmp1 = ft_substr(s, 0, j);
	tmp2 = ft_substr(s, j + 1, *i - j - 1);
	tmp3 = ft_strdup(s + *i + 1);
//	printf("tmp1: %s\n", tmp1);
//	printf("tmp2: %s\n", tmp2);
//	printf("tmp3: %s\n", tmp3);

	res1 = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);

	res2 = ft_strjoin(res1, tmp3);
	free(tmp3);
	free(res1);
//	printf("i: %d, j: %d\n", *i, j);

//	printf("res: %s\n", res2);

	free(s);
	*i = *i - 1;
	return res2;
}

char *gap2(char *s, int *i)
{
	int j;
	char *tmp1, *tmp2, *tmp3;
	char *res1, *res2;

	j = *i;
//	char *com = ft_strdup("com\\mand'lsdkcomm'andmi\"Nishe\"ll");
	while (s[++(*i)] != '\"')
		if (s[*i] == '\\' && (s[*i + 1] == '$' || s[*i + 1] == '\\' || s[*i + 1] == '\"'))
			s = slash(s, i);
	tmp1 = ft_substr(s, 0, j);
	tmp2 = ft_substr(s, j + 1, *i - j - 1);
	tmp3 = ft_strdup(s + *i + 1);
	//	printf("tmp1: %s\n", tmp1);
	//	printf("tmp2: %s\n", tmp2);
	//	printf("tmp3: %s\n", tmp3);

	res1 = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);

	res2 = ft_strjoin(res1, tmp3);
	free(tmp3);
	free(res1);
	//	printf("i: %d, j: %d\n", *i, j);

	//	printf("res: %s\n", res2);

	free(s);
	*i = *i - 1;
	return res2;
}



void parser(char *s)
{
	int i;

	i = -1;
	while(s[++i])
	{
		if (s[i] == '\'')
		{
			s = gap(s, &i);
			printf("s: %s, s[i]: %c\n", s, s[i]);
		}
		if (s[i] == '\"')
		{
			s = gap2(s, &i);
			printf("s: %s, s[i]: %c\n", s, s[i]);
		}
		if (s[i] == '\\')
			s = slash(s, &i);

	}
}


// " ' $ ; | > >> <
int main(void)
{
//	char *com = ft_strdup("com\\mand'lsdk'co'mm'and");
//	char *com = ft_strdup("com\"man\\\\\\$\\\"dlsdk\"co'mman'd");
	char *com = ft_strdup("\"sdf\"com\\\"ma;|nd\"lsdkcomma\"nd");

	printf("%s\n", com);
	pre_parser(com);
	printf("All is OK\n");
//	parser(com);

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