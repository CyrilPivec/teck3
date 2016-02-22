/*
** my_str_to_wordtab.c for str in /home/pivec_c/rendu/PSU_2014_myirc/src_server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Sun Apr 12 15:43:33 2015 cyril pivec
** Last update Sat Jul  4 23:45:52 2015 Florian Tousch
*/

#include <server.h>

int		tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      free (tab[i]);
      i++;
    }
  free(tab);
}

int		count_word(char *str, char separe)
{
  int		i;
  int		count;

  i = 0;
  count = 1;
  while (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
    i++;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
	{
	  while (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
	    i++;
	  if (str[i])
	    count++;
	}
      if (str[i])
	i++;
    }
  return (count);
}

char		**my_str_to_wordtab(char *str, char separe)
{
  char		**tab;
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  tab = malloc(sizeof(*tab) * ((count_word(str, separe) + 1)));
  while (str[i] == '\t' || str[i] == ' ' || str[i] == separe)
    i++;
  while (str[i])
    {
      tab[j] = malloc(sizeof(**tab) * (strlen(str) + 1));
      k = 0;
      while (str[i] != ' ' && str[i] != '\t' && str[i] != separe && str[i])
        tab[j][k++] = str[i++];
      tab[j++][k] = '\0';
      while (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
	i++;
    }
  tab[j] = NULL;
  return (tab);
}
