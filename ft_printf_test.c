#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../ft_printf/ft_printf.h"
#include "criterion-2.4.2/include/criterion/criterion.h"
#include "criterion-2.4.2/include/criterion/redirect.h"

#define BUFFER_SIZE 128

void redirect_all_stdout(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(ft_printf_suite, test_ft_printf_return, .init=redirect_all_stdout)
{
	int	res;
	res = ft_printf("...%d..%c..", 1, 'a');
	cr_assert_eq(res, 0, "Expected ft_printf to return 0");
}

// char //////////////////////////
Test(ft_printf_suite, test_ft_print_char, .init=redirect_all_stdout)
{
	ft_printf("...%c...", 'a');
	cr_assert_stdout_eq_str("...a...", "Expected ft_printf to print '...a...'");
}

Test(ft_printf_suite, test_ft_print_char_back, .init=redirect_all_stdout)
{
	ft_printf("%c...", 'b');
	cr_assert_stdout_eq_str("b...", "Expected ft_printf to print 'b...'");
}

Test(ft_printf_suite, test_ft_print_char_front, .init=redirect_all_stdout)
{
	ft_printf("...%c", 'c');
	cr_assert_stdout_eq_str("...c", "Expected ft_printf to print '...c'");
}

Test(ft_printf_suite, test_ft_print_char_single, .init=redirect_all_stdout)
{
	ft_printf("%c", 'd');
	cr_assert_stdout_eq_str("d", "Expected ft_printf to print 'd'");
}

// str //////////////////////////
Test(ft_printf_suite, test_ft_print_str, .init=redirect_all_stdout)
{
	ft_printf("%s", "---Thinny+++");
	cr_assert_stdout_eq_str("---Thinny+++", "Expected ft_printf to print '---Thinny+++'");
}

Test(ft_printf_suite, test_ft_print_str_back, .init=redirect_all_stdout)
{
	ft_printf("%s", "Thinny+++");
	cr_assert_stdout_eq_str("Thinny+++", "Expected ft_printf to print 'Thinny+++'");
}

Test(ft_printf_suite, test_ft_print_str_front, .init=redirect_all_stdout)
{
	ft_printf("%s", "---Thinny");
	cr_assert_stdout_eq_str("---Thinny", "Expected ft_printf to print '---Thinny'");
}

Test(ft_printf_suite, test_ft_print_str_single, .init=redirect_all_stdout)
{
	ft_printf("%s", "Thinny");
	cr_assert_stdout_eq_str("Thinny", "Expected ft_printf to print 'Thinny'");
}

Test(ft_printf_suite, test_ft_print_str_empty_space, .init=redirect_all_stdout)
{
	ft_printf("%s", " ");
	cr_assert_stdout_eq_str(" ", "Expected ft_printf to print ' '");
}

Test(ft_printf_suite, test_ft_print_str_empty, .init=redirect_all_stdout)
{
	ft_printf("%s", "");
	cr_assert_stdout_eq_str("", "Expected ft_printf to print ''");
}

// decimal /////////////////////////
Test(ft_printf_suite, test_ft_print_dec, .init=redirect_all_stdout)
{
	ft_printf("...%d...", 5);
	cr_assert_stdout_eq_str("...5...", "Expected ft_printf to print '...5...'");
}

Test(ft_printf_suite, test_ft_print_dec_back, .init=redirect_all_stdout)
{
	ft_printf("%d...", 42);
	cr_assert_stdout_eq_str("42...", "Expected ft_printf to print '42...'");
}

Test(ft_printf_suite, test_ft_print_dec_front, .init=redirect_all_stdout)
{
	ft_printf("...%d", 456);
	cr_assert_stdout_eq_str("...456", "Expected ft_printf to print '...456'");
}

Test(ft_printf_suite, test_ft_print_dec_single, .init=redirect_all_stdout)
{
	ft_printf("%d", 1234);
	cr_assert_stdout_eq_str("1234", "Expected ft_printf to print '1234'");
}

// void * ///////////////////////////////
Test(ft_printf_suite, test_ft_putmem, .init=redirect_all_stdout)
{
	int	nbr = 42;
	ft_printf("%p", &nbr);
	fflush(stdout);
	FILE *output_stream = cr_get_redirected_stdout();
	char buffer[BUFFER_SIZE] = {0};
	fgets(buffer, BUFFER_SIZE, output_stream);
    cr_assert(buffer[0] == '0' && buffer[1] == 'x', "Output should start with '0x'.");
}
