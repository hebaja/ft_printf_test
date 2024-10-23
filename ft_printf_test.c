#include <stdio.h>
#include <unistd.h>
#include "../ft_printf/ft_printf.h"
#include "criterion-2.4.2/include/criterion/criterion.h"
#include "criterion-2.4.2/include/criterion/redirect.h"

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

Test(ft_printf_suite, test_ft_print_char, .init=redirect_all_stdout)
{
	ft_printf("...%c..", 'a');
	cr_assert_stdout_eq_str("...a..", "Expected ft_printf to print ...a..");
}
/*
Test(ft_printf_suite, test_ft_print_str, .init=redirect_all_stdout)
{
	ft_printf("%s", "hello");
	cr_assert_stdout_eq_str("hello", "Expected ft_printf to print Thinny");
}
*/
Test(ft_printf_suite, test_ft_print_stri1)
{
	ft_printf("...%s", "hello");
}

Test(ft_printf_suite, test_ft_print_dec, .init=redirect_all_stdout)
{
	ft_printf("...%d..", 5);
	cr_assert_stdout_eq_str("...5..", "Expected ft_printf to print ...5..");
}
