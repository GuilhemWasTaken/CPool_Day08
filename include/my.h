/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

void my_putchar(char);
int my_putstr(char *);
void my_put_nbr(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char *);
int my_str_isnum(char *);
int my_str_islower(char *);
int my_str_isupper(char *);
int my_str_isprintable(char *);
int my_putnbr_base(int, char const *);
int my_getnbr_base(char const *, char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
void my_print_params(int, char **);
void my_rev_params(int, char **);
void my_sort_params(int, char **);
int my_strlen(char const *);
char *my_strdup(char const *);
char *concat_params(int, char **);
int my_show_word_array(char * const *);
char **my_str_to_word_array(char const *);
char *convert_base(char const *, char const *, char const *);
