#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	static char *s_hidden = "hi low\0don't print me lol\0";
/*	ft_printf("test 1 'd': %*.*d\n", 15, 10, 5); //+ширина > точности
	printf("test 1 'd': %*.*d\n", 15, 10, 5);
	ft_printf("test 2 'd': %-3.d\n", 10); //+ширина < точности
	printf("test 2 'd': %-3.d\n", 10);
	ft_printf("test 3 'd': %*.*d\n", -5, 15, 5); //-ширина
	printf("test 3 'd': %*.*d\n", -5, 15, 5);
	ft_printf("Test 4 'd': %.10d\n", 5); // точность больше числа
	printf("test 4 'd': %.10d\n", 5);
	ft_printf("Test 5 'd': %.1d\n", 15); // точность меньше числа
	printf("test 5 'd': %.1d\n", 15);
	ft_printf("test 6 'd': %10d\n", 15); // ширина больше числа
	printf("test 6 'd': %10d\n", 15);
	ft_printf("test 7 'd': %1d\n", 15); // ширина меньше числа
	printf("test 7 'd': %1d\n", 15);
	ft_printf("test 8 'd': %-10d\n", 15); // ширина отрицательная
	printf("test 8 'd': %-10d\n", 15);
	ft_printf("test 9 'd': %010d\n", 15); // ширина 0
	printf("test 9 'd': %010d\n", 15);
	ft_printf("test 10 'd': %d, %i, %d, %d, %i\n", 15, 123123, 43, 56564, -3478534);
	printf("test 10 'd': %d, %i, %d, %d, %i\n", 15, 123123, 43, 56564, -3478534); */
	ft_printf("%% \n"); // +ширина
	/*printf("%% \n");
	ft_printf("test 2 's': %-40s\n", "Hello my dear friend"); // -ширина
	printf("test 2 's': %-40s\n", "Hello my dear friend");
	ft_printf("test 3 's': %.40s\n", "Hello my dear friend"); // точность больше строки
	printf("test 3 's': %.40s\n", "Hello my dear friend");
	ft_printf("test 4 's': %.1s\n", "Hello my dear friend"); // точность меньше строки
	printf("test 4 's': %.1s\n", "Hello my dear friend");
	ft_printf("test 5 's': %100.100s\n", "Hello my dear friend"); // +ширина и точность больше строки
	printf("test 5 's': %100.100s\n", "Hello my dear friend");
	ft_printf("test 6 's': %-40.40s\n", "Hello my dear friend"); // -ширина и точность больше строки
	printf("test 6 's': %-40.40s\n", "Hello my dear friend");
	ft_printf("test 7 's': %40.5s\n", "Hello my dear friend"); // +ширина и точность меньше строки
	printf("test 7 's': %40.5s\n", "Hello my dear friend");
	ft_printf("test 8 's': %-40.5s\n", "Hello my dear friend"); // -ширина и точность меньше строки
	printf("test 8 's': %-40.5s\n", "Hello my dear friend");
	ft_printf("%c\n", 'c');
	printf("%c\n", 'c');
	ft_printf("%10c\n", 'c');
	printf("%10c\n", 'c');
	ft_printf("%-10c\n", 'c');
	printf("%-10c\n", 'c');
	ft_printf("%*c\n", 10, 'c');
	printf("%*c\n", 10, 'c');
	ft_printf("%*c\n", -10, 'c');
	printf("%*c\n", -10, 'c');
	ft_printf("test 1 'x': %*.*X\n", 15, 10, 3452011); //+ширина > точности
	printf("test 1 'x': %*.*X\n", 15, 10, 3452011);
	ft_printf("test 2 'x': %*.*X\n", 10, 15, 3452011); //+ширина < точности
	printf("test 2 'x': %*.*X\n", 10, 15, 3452011);
	ft_printf("test 3 'x': %*.*X\n", -5, 15, 3452011); //-ширина
	printf("test 3 'x': %*.*X\n", -5, 15, 3452011);
	ft_printf("Test 4 'x': %.10X\n", 3452011); // точность больше числа
	printf("test 4 'x': %.10X\n", 3452011);
	ft_printf("Test 5 'x': %.1X\n", 3452011); // точность меньше числа
	printf("test 5 'x': %.1X\n", 3452011);
	ft_printf("test 6 'x': %10X\n", 3452011); // ширина больше числа
	printf("test 6 'x': %10X\n", 3452011);
	ft_printf("test 7 'x': %1X\n", 3452011); // ширина меньше числа
	printf("test 7 'x': %1X\n", 3452011);
	ft_printf("test 8 'x': %-10X\n", 3452011); // ширина отрицательная
	printf("test 8 'x': %-10X\n", 3452011);
	ft_printf("test 9 'x': %010X\n", 3452011); // ширина 0
	printf("test 9 'x': %010X\n", 3452011); */
}
