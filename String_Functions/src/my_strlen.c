int my_strlen(char *str)
{
    char *tmp = str;
    while(*tmp != '\0')
    {
        tmp++;
    }
    return tmp - str;

}
