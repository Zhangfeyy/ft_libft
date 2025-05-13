#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "../lib/libft/libft.h"

char *ft_decimal(va_list args);
char *ft_unsigned(va_list args);
char *ft_hexl(va_list args);
char *ft_hexu(va_list args);
char *ft_character(va_list args);
char *ft_string(va_list args);
int	ft_printf(const char *string, ...);
char *ft_void(va_list args);
char	*ft_itoa_int(int n);
char	*ft_itoa_unsigned(unsigned int n);

#endif