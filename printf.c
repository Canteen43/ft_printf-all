int ft_printf(const char *string, ...)
{
    int     bytes_printed;
    va_list args;

    va_start(args, string);
    while (*string != '\0')
    {
        if (*string != '%')
            write(1, string++, 1);
        

    }
        

    int arg1 = va_arg(args, int);
    va_end(args);
    return (bytes_printed);
}