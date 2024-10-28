#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../ft_printf/ft_printf.h"
#include "criterion-2.4.2/include/criterion/assert.h"
#include "criterion-2.4.2/include/criterion/criterion.h"
#include "criterion-2.4.2/include/criterion/redirect.h"

#define BUFFER_SIZE 128

void redirect_all_stdout(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

// % //////////////////////////////
Test(ft_printf_suite, test_ft_printf_perc, .init=redirect_all_stdout)
{
	int	res;

	res = ft_printf("%%");
	cr_assert_stdout_eq_str("%", "Expected ft_printf to print percents.");
	cr_assert_eq(1, res);
}

Test(ft_printf_suite, test_ft_printf_perc3, .init=redirect_all_stdout)
{
	int	res;

	res = ft_printf("%%%%%%");
	cr_assert_stdout_eq_str("%%%", "Expected ft_printf to print percents.");
	cr_assert_eq(3, res);
}

Test(ft_printf_suite, test_ft_printf_perc4, .init=redirect_all_stdout)
{
	int	res;

	res = ft_printf("%% %% %% %%");
	cr_assert_stdout_eq_str("% % % %", "Expected ft_printf to print percents");
	cr_assert_eq(7, res);
}

// char //////////////////////////
Test(ft_printf_suite, test_ft_print_char, .init=redirect_all_stdout)
{
	int	res;

	res = ft_printf("...%c...", 'a');
	cr_assert_stdout_eq_str("...a...", "Expected ft_printf to print '...a...'");
	cr_assert_eq(7, res);
}

Test(ft_printf_suite, test_ft_print_char_back, .init=redirect_all_stdout)
{
	int	res;

	res = ft_printf("%c...", 'b');
	cr_assert_stdout_eq_str("b...", "Expected ft_printf to print 'b...'");
	cr_assert_eq(4, res);
}

Test(ft_printf_suite, test_ft_print_char_front, .init=redirect_all_stdout)
{
	int	res;

	res = ft_printf("...%c", 'c');
	cr_assert_stdout_eq_str("...c", "Expected ft_printf to print '...c'");
	cr_assert_eq(4, res);
}

Test(ft_printf_suite, test_ft_print_char_single, .init=redirect_all_stdout)
{
	int	res;

	res = ft_printf("%c", 'd');
	cr_assert_stdout_eq_str("d", "Expected ft_printf to print 'd'");
	cr_assert_eq(1, res);
}

// str //////////////////////////
Test(ft_printf_suite, test_ft_print_str, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("%s", "---Thinny+++");
	cr_assert_stdout_eq_str("---Thinny+++", "Expected ft_printf to print '---Thinny+++'");
	cr_assert_eq(12, res);
}

Test(ft_printf_suite, test_ft_print_str_back, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("%s", "Thinny+++");
	cr_assert_stdout_eq_str("Thinny+++", "Expected ft_printf to print 'Thinny+++'");
	cr_assert_eq(9, res);
}

Test(ft_printf_suite, test_ft_print_str_front, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("%s", "---Thinny");
	cr_assert_stdout_eq_str("---Thinny", "Expected ft_printf to print '---Thinny'");
	cr_assert_eq(9, res);
}

Test(ft_printf_suite, test_ft_print_str_single, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("%s", "Thinny");
	cr_assert_stdout_eq_str("Thinny", "Expected ft_printf to print 'Thinny'");
	cr_assert_eq(6, res);
}

Test(ft_printf_suite, test_ft_print_str_empty_space, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("%s", " ");
	cr_assert_stdout_eq_str(" ", "Expected ft_printf to print ' '");
	cr_assert_eq(1, res);
}

Test(ft_printf_suite, test_ft_print_str_empty, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("%s", "");
	cr_assert_stdout_eq_str("", "Expected ft_printf to print ''");
	cr_assert_eq(0, res);
}

Test(ft_printf_suite, test_ft_print_str_with_new_line, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("%s\n", "Thinny");
	cr_assert_stdout_eq_str("Thinny\n", "Expected ft_printf to print 'Thinny'");
	cr_assert_eq(7, res);
}

Test(ft_printf_suite, test_ft_print_str_null, .init=redirect_all_stdout)
{
	char	*str;
	int	res;

	str = NULL;
	res = ft_printf("%s", str);
	cr_assert_stdout_eq_str("(null)", "Expected ft_printf to print '(null)'");
	cr_assert_eq(6, res);
}

// decimal /////////////////////////
Test(ft_printf_suite, test_ft_print_dec, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("...%d...", 5);
	cr_assert_stdout_eq_str("...5...", "Expected ft_printf to print '...5...'");
	cr_assert_eq(7, res);
}

Test(ft_printf_suite, test_ft_print_dec_back, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("%d...", 42);
	cr_assert_stdout_eq_str("42...", "Expected ft_printf to print '42...'");
	cr_assert_eq(5, res);
}

Test(ft_printf_suite, test_ft_print_dec_front, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("...%d", 456);
	cr_assert_stdout_eq_str("...456", "Expected ft_printf to print '...456'");
	cr_assert_eq(6, res);
}

Test(ft_printf_suite, test_ft_print_dec_single, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("%d", 1234);
	cr_assert_stdout_eq_str("1234", "Expected ft_printf to print '1234'");
	cr_assert_eq(4, res);
}

// integer ////////////////////////
Test(ft_printf_suite, test_ft_print_int, .init=redirect_all_stdout)
{
	int	res;

	res = ft_printf("...%i...", 5);
	cr_assert_stdout_eq_str("...5...", "Expected ft_printf to print '...5...'");
	cr_assert_eq(7, res);
}

Test(ft_printf_suite, test_ft_print_int_back, .init=redirect_all_stdout)
{
	int	res;

	res = ft_printf("%i...", 42);
	cr_assert_stdout_eq_str("42...", "Expected ft_printf to print '42...'");
	cr_assert_eq(5, res);
}

Test(ft_printf_suite, test_ft_print_int_front, .init=redirect_all_stdout)
{
	int	res;

	res = ft_printf("...%i", 456);
	cr_assert_stdout_eq_str("...456", "Expected ft_printf to print '...456'");
	cr_assert_eq(6, res);
}

Test(ft_printf_suite, test_ft_print_int_single, .init=redirect_all_stdout)
{
	int	res;

	res = ft_printf("%i", 1234);
	cr_assert_stdout_eq_str("1234", "Expected ft_printf to print '1234'");
	cr_assert_eq(4, res);
}

// unsigned integer ////////////////////////
Test(ft_printf_suite, test_ft_print_u_int, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("...%u...", 5);
	cr_assert_stdout_eq_str("...5...", "Expected ft_printf to print '...5...'");
	cr_assert_eq(7, res);
}

Test(ft_printf_suite, test_ft_print_u_int_back, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("%u...", 42);
	cr_assert_stdout_eq_str("42...", "Expected ft_printf to print '42...'");
	cr_assert_eq(5, res);
}

Test(ft_printf_suite, test_ft_print_u_int_front, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("...%u", 456);
	cr_assert_stdout_eq_str("...456", "Expected ft_printf to print '...456'");
	cr_assert_eq(6, res);
}

Test(ft_printf_suite, test_ft_print_u_int_single, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("%u", 1234);
	cr_assert_stdout_eq_str("1234", "Expected ft_printf to print '1234'");
	cr_assert_eq(4, res);
}

Test(ft_printf_suite, test_ft_print_u_int_high, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("%u", 4294967295);
	cr_assert_stdout_eq_str("4294967295", "Expected ft_printf to print '4294967295'");
	cr_assert_eq(10, res);
}

// hex //////////////////////////////////
Test(ft_printf_suite, test_ft_pritf_hex_low, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("%x", 42);
	cr_assert_stdout_eq_str("2a", "Expected ft_printf to print '2a'");
	cr_assert_eq(2, res);
}

Test(ft_printf_suite, test_ft_pritf_hex_upper, .init=redirect_all_stdout)
{
	int res;

	res = ft_printf("%X", 42);
	cr_assert_stdout_eq_str("2A", "Expected ft_printf to print '2a'");
	cr_assert_eq(2, res);
}

// void * ///////////////////////////////
Test(ft_printf_suite, test_ft_printf_memory_address, .init=redirect_all_stdout)
{
	int	nbr = 42;
	ft_printf("%p", &nbr);
	fflush(stdout);
	FILE *output_stream = cr_get_redirected_stdout();
	char buffer[BUFFER_SIZE] = {0};
	fgets(buffer, BUFFER_SIZE, output_stream);
    cr_assert(buffer[0] == '0' && buffer[1] == 'x', "Output should start with '0x'.");
}

Test(ft_printf_suite, test_ft_printf_memory_null, .init=redirect_all_stdout)
{
	int	res;
	res = ft_printf("%p", NULL);
	cr_assert_stdout_eq_str("(nil)", "Expected ft_printf to print '(nil)'");
	cr_assert_eq(5, res, "Expected ft_printf to print '(nil)'");
}

Test(ft_printf_suite, test_ft_printf_minus_one, .init=redirect_all_stdout)
{
	int	res;
	res = ft_printf(0);
	cr_assert_stdout_eq_str("", "Expected ft_printf to print ''");
	cr_assert_eq(-1, res, "Expected ft_printf to print '-1'");
}

Test(ft_printf_suite, test_ft_printf_mixed_return, .init=redirect_all_stdout)
{
	int	res;
	res = ft_printf("...%d..%c..", 1, 'a');
	cr_assert_eq(res, 9, "Expected ft_printf to return 0");
}

// mixed /////////////////////////////
Test(ft_printf_suite, test_ft_printf_mixed, .init=redirect_all_stdout)
{
	int res;
	res = ft_printf("mixed%%%c%%%s%%%d%%%i%% %x %X", 'A', "42", 42, 42, 42, 42);
	cr_assert_stdout_eq_str("mixed%A%42%42%42% 2a 2A", "Expected printf to print a mixed output.");
	cr_assert_eq(23, res);
}	
