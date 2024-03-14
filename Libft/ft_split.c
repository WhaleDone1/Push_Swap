/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:16:28 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/11 09:16:51 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
    return (NULL);
}

static char	*ft_strndup(const char *src, int n)
{
    int i;
    int j;
    char *dest;

    i = 0;
    j = 0;
    while (src[i] && i < n)
        i++;
    dest = (char *)malloc(sizeof(char) * (i + 1));
    if (!dest)
        return (NULL);
    while (j < n)
    {
        dest[j] = src[j];
        j++;
    }
    dest[n] = '\0';
    return (dest);
}

static int	range_to_sep(const char *str, char charset)
{
    int i;

    i = 0;
    while (str[i] && charset != str[i])
        i++;
    return (i);
}

static int	count_word(const char *str, char charset)
{
    int i;
    int word;

    i = 0;
    word = 0;
    if (!charset)
        return (1);
    while (str[i])
    {
        while (str[i] && charset == str[i])
            i++;
        if (str[i])
            word++;
        while (str[i] && charset != str[i])
            i++;
    }
    return (word);
}

char	**ft_split(const char *str, char c)
{
    int i;
    char **split;

    i = 0;
    if (!str)
        return (NULL);
    split = malloc(sizeof(char *) * (count_word(str, c) + 1));
    if (!split)
        return (NULL);
    while (*str)
    {
        while (*str && c == str[0])
            str++;
        if (*str)
        {
            split[i] = ft_strndup(str, range_to_sep(str, c));
            if (!split[i])
                return (ft_free(split));
            i++;
        }
        while (*str && c != str[0])
            str++;
    }
    split[i] = NULL;
    return (split);
}
