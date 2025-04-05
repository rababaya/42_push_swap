#include "libft.h"
#include "ft_printf.h"
#include <fcntl.h>

int main ()
{
	int a = open("libft.h", O_RDONLY);
	char *s = get_next_line(a);
	ft_printf("%d\n", ft_strlen(s));
	free(s);
}
