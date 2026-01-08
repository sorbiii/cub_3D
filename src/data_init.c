#include "../includes/cube.h"

int is_valid_extention(char *s)
{
    char *pos;
    int len;

    if (!s)
        return (-1);
    len = ft_strlen(s);
    if (len < 4)
        return (-1);
    pos = ft_strnstr(s, ".cub", len);
    if (!pos)
        return (-1);
    if (*(pos + 4) != '\0')
        return (-1);
    return (0);
}

void init_data(int argc, char **argv)
{
    if(argc != 2)
        return (error_and_exit(WRONG_ARG_NUM));
    if (is_valid_extention(argv[1]) == -1)
        return (error_and_exit(WRONG_EXTENTION));
    
    //pierwszy gnl - do kolorow i teksturek - WHITESPACES!
    //sprawdzenie kolorow
    //sprawdzenie teksturek
    //zparsowanie mapy - wyciagnac player, map width, height 
}