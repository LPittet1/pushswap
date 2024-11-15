/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:43:16 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/15 15:20:13 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int *ft_realloc(int *start, int new_size)
{
    int     *new;
    int     temp;
    int     pos;

    new = ft_calloc(new_size, sizeof(int));
    while (pos < new_size)
    {
        new[pos] = start[pos];
        pos++;
    }
    free(start);
    return (new);
}

int main()
{
    t_stack test;
    int i = 0;
    
    test.content = ft_calloc(1, sizeof(int));
    test.content[0] = 3;
    test.size = 1;
    while (i < 5)
    {
        test.size++;
        test.content = ft_realloc(test.content, test.size);
        test.content[i] = 3;
        i++;
    }
    i = 0;
    while (i < 5)
    {
        printf("%i\n", test.content[i]);
        i++;
    }
    free(test.content);
}