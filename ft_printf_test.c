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

Test(ft_printf_suite, test_ft_printf, .init=redirect_all_stdout)
{
	int res;
	res = ft_printf("...%d..%c..", 1, 'a');
	cr_assert_eq(res, 0, "Expected ft_printf to return 9");
	cr_assert_stdout_eq_str("...1..a..", "Expected ft_printf to print ...1..a..");

}
