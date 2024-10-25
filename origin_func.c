#include <stdio.h>

int	main()
{
	int	res;
	char	c;
	char	*str;

	c = 'a';
	str = NULL;
	res = printf("..%c..", c);
	printf(" >>> %d\n", res);
	res = printf("%p", &c);
	printf(" >>> %d\n", res);
	printf("NULL pointer -> ");
	res = printf("%p", NULL);
	printf(" >>> %d\n", res);
	printf("String NULL -> ");
	res = printf("%s", str);
	printf(" >>> %d\n", res);
	printf("Zero as argument -> ");
	res = printf(0);
	printf("%d\n", res);
}
