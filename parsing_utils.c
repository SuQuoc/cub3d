//FILE COMPLETELY UNUSED

//only checks for space and tabs must remain like this cuz used in identifers.c
int is_blank(char c)
{
    if (c == ' ' || c == 9)
        return (1);
    return (0);
}

int skip_is_blank(char *str, int i)
{
    while (str[i] && is_blank(str[i]))
        i++;
    return (i);
}


int skip_spaces(char *str, int start)
{
    while (str[start] && str[start] == ' ')
        start++;
    return (start);
}