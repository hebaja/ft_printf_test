#!/bin/bash
export LD_LIBRARY_PATH=./criterion-2.4.2/lib:$LD_LIBRARY_PATH
cc -I ./criterion-2.4.2/include ft_printf_test.c ../ft_printf/libftprintf.a -L ./criterion-2.4.2/lib -lcriterion -o crit && ./crit

