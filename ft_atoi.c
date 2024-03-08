long ft_atoi(const char *str)
{
    long nb;
    int sign;
    size_t i;

    nb = 0;
    sign = 1;
    i = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    if (nb * sign < -2147483648 || nb * sign > 2147483647)
        return (2147483648);
    return (nb * sign);
}