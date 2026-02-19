/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 07:52:06 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/12 14:11:22 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	result;
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	src_index;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	result = dest_len + src_len;
	if (size <= dest_len)
		return (src_len + size);
	src_index = 0;
	while (src[src_index] != '\0' && size - 1 > dest_len)
	{
		dest[dest_len] = src[src_index];
		src_index++;
		dest_len++;
	}
	dest[dest_len] = '\0';
	return (result);
}
/*
int main(void)
{
    char dst1[50];
    char dst2[50];
    char src[] = " World!";
    size_t result1, result2;
    
    printf("=== Testing ft_strlcat ===\n\n");
    
    // Test 1: Normal concatenation with enough space
    printf("Test 1: Normal concatenation\n");
    strcpy(dst1, "Hello");
    strcpy(dst2, "Hello");
    
    result1 = ft_strlcat(dst1, src, sizeof(dst1));
    result2 = strlcat(dst2, src, sizeof(dst2));
    
    printf("ft_strlcat: '%s' (return: %zu)\n", dst1, result1);
    printf("strlcat:    '%s' (return: %zu)\n", dst2, result2);
    printf("Match: %s\n\n", strcmp(dst1, dst2) == 0 
		&& result1 == result2 ? "✓" : "✗");
    
    // Test 2: Destination buffer exactly fits
    printf("Test 2: Buffer exactly fits\n");
    char small1[12] = "Hello";
    char small2[12] = "Hello";
    
    result1 = ft_strlcat(small1, src, sizeof(small1));
    result2 = strlcat(small2, src, sizeof(small2));
    
    printf("ft_strlcat: '%s' (return: %zu)\n", small1, result1);
    printf("strlcat:    '%s' (return: %zu)\n", small2, result2);
    printf("Match: %s\n\n", strcmp(small1, small2) == 0 
		&& result1 == result2 ? "✓" : "✗");
    
    // Test 3: Destination buffer too small
    printf("Test 3: Buffer too small\n");
    char tiny1[10] = "Hello";
    char tiny2[10] = "Hello";
    
    result1 = ft_strlcat(tiny1, src, sizeof(tiny1));
    result2 = strlcat(tiny2, src, sizeof(tiny2));
    
    printf("ft_strlcat: '%s' (return: %zu)\n", tiny1, result1);
    printf("strlcat:    '%s' (return: %zu)\n", tiny2, result2);
    printf("Match: %s\n\n", strcmp(tiny1, tiny2) == 0 
		&& result1 == result2 ? "✓" : "✗");

	    // Test 4: Empty source string
    printf("Test 4: Empty source\n");
    strcpy(dst1, "Hello");
    strcpy(dst2, "Hello");
    
    result1 = ft_strlcat(dst1, "", sizeof(dst1));
    result2 = strlcat(dst2, "", sizeof(dst2));
    
    printf("ft_strlcat: '%s' (return: %zu)\n", dst1, result1);
    printf("strlcat:    '%s' (return: %zu)\n", dst2, result2);
    printf("Match: %s\n\n", strcmp(dst1, dst2) == 0 
		&& result1 == result2 ? "✓" : "✗");
    
    // Test 5: Empty destination string
    printf("Test 5: Empty destination\n");
    dst1[0] = '\0';
    dst2[0] = '\0';
    
    result1 = ft_strlcat(dst1, "Hello", sizeof(dst1));
    result2 = strlcat(dst2, "Hello", sizeof(dst2));
    
    printf("ft_strlcat: '%s' (return: %zu)\n", dst1, result1);
    printf("strlcat:    '%s' (return: %zu)\n", dst2, result2);
    printf("Match: %s\n\n", strcmp(dst1, dst2) == 0 
		&& result1 == result2 ? "✓" : "✗");
    
    // Test 6: Size = 0
    printf("Test 6: Size = 0\n");
    strcpy(dst1, "Hello");
    strcpy(dst2, "Hello");
    
    result1 = ft_strlcat(dst1, src, 0);
    result2 = strlcat(dst2, src, 0);
    
    printf("ft_strlcat: '%s' (return: %zu)\n", dst1, result1);
    printf("strlcat:    '%s' (return: %zu)\n", dst2, result2);
    printf("Match: %s\n\n", strcmp(dst1, dst2) == 0 
					&& result1 == result2 ? "✓" : "✗");
    
    // Test 7: Size = 1 (only space for null terminator)
    printf("Test 7: Size = 1\n");
    strcpy(dst1, "Hello");
    strcpy(dst2, "Hello");
    
    result1 = ft_strlcat(dst1, src, 1);
    result2 = strlcat(dst2, src, 1);
    
    printf("ft_strlcat: '%s' (return: %zu)\n", dst1, result1);
    printf("strlcat:    '%s' (return: %zu)\n", dst2, result2);
    printf("Match: %s\n\n", strcmp(dst1, dst2) == 0 
					&& result1 == result2 ? "✓" : "✗");
    
}*/
