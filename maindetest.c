#include "./Includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	// ft_printf("moi  : %5d\n", -42);
	// printf("test : %5d\n", -42);
	// ft_printf("%0+5d\n", -42);
	// ft_printf("%+10.5d\n", 4242);
	/*ft_printf("@moi      : %.d %.0d\n", 42, 43);
	printf("@moulitest: %.d %.0d\n", 42, 43);*/
	
	/*short a;
	a = 32768;

	ft_printf("moi  : %ld\n", 2147483648);
	printf("test : %ld\n", 2147483648);

	ft_printf("moi  : %lld\n", -9223372036854775808);
	printf("test : %lld\n", -9223372036854775808);

	ft_printf("moi  : %jd\n", 9223372036854775807);
	printf("test : %jd\n", 9223372036854775807);

	ft_printf("moi  : %zd\n", 4294967295);
	printf("test : %zd\n", 4294967295);
	ft_printf("min moi : %ld\n", LONG_MIN);
	printf("min : %ld\n", LONG_MIN);
	ft_printf("moi  : h = %hd\n", a);
	printf("test : h = %hd\n", a);

	char a;
	a = 0x3F;
	write(1, &a, 1);

	ft_printf("moi  : h = %hd\n", 123);
	printf("test : h = %hd\n", 123);

	ft_printf("moi  : h = %hD\n", 12467981246798);
	printf("test : h = %hD\n", 12467981246798);

	ft_printf("moi  : %hhd\n", 128);
	printf("test : %hhd\n", 128);
	ft_printf("moi  : %D\n", LONG_MIN);
	printf("test : %lD\n", LONG_MIN);
	printf("%.0p, %.p\n", 0, 0);
	ft_printf("%.0p, %.p\n", 0, 0);
	ft_printf("moi  : %lo\n", LONG_MAX);
	printf("test : %lo\n", LONG_MAX);

	ft_printf("moi  : %U\n", ULONG_MAX / 2);
	printf("test : %U\n", ULONG_MAX / 2);
	ft_printf("moi  : %s %c blabla\n", "bonjour\0\0", 0);
	printf("test : %s %c blabla\n", "bonjour\0\0", 0);

	ft_printf("moi  : %hhO\n", USHRT_MAX);
	printf("test : %hhO\n", USHRT_MAX);

	ft_printf("moi  : {%010d}\n", -42);
	printf("test : {%010d}\n", -42);

	//int a = 4;
	ft_printf("moi  : %lp\n", 42);
	printf("test : %lp\n", 42);

	ft_printf("moi  : %2x\n", 2);
	printf("test : %2x\n", 2);
	ft_printf("moi  : %C\n", 255);
	printf("test : %C\n", 255);
	ft_printf("moi  : %C\n", L'莨');
	printf("test : %C\n", L'莨');
	int i = ft_printf("moi  : %C\n", 256);
	int j = printf("test : %C\n", 256);*/

	/*int i = ft_printf("moi  = %lc, %lc\n", L'ÊM-^ZM-^V', L'ÿ≠');
	int j = printf("test = %lc, %lc\n", L'ÊM-^ZM-^V', L'ÿ≠');
	printf("i = %d\nj = %d\n", i, j);
	ft_printf("moi  : %S\n", L"Ê莨ÿ");
	printf("test : %S\n", L"Ê莨ÿ");
	ft_printf("moi  : %#.o\n", 42);
	printf("test : %#.o\n", 42);
	
	ft_printf("moi  : {%5p}\n", 0);
	printf("test : {%05p}\n", 0);
	ft_printf("moi  : {% 03d}\n", 0);
	printf("test : {% 03d}\n", 0);*/
	ft_printf("moi  : %.d %.0d\n", 42, 43);
	printf("test : %.d %.0d\n", 42, 43);

	/*ft_printf("moi  : %c\n", 42);
	printf("test : %c\n", 42);*/
	

	/*ft_printf("moi  : % Zooo\n");
	printf("test : % Zooo\n");

	unsigned long int a = 123465798789;

	ft_printf("moi : %lo\n", a);
	printf("test: %hho\n", a);
	ft_printf("%#o", 0)
	printf("%O", LONG_MAX);
	printf("%#o", 0);*/

	return (0);
}
