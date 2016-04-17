PHP_ARG_ENABLE(sample, [whether to enable sample support],
[  --enable-sample          Enable sample support])

if test "$PHP_SAMPLE" = "yes"; then
  PHP_NEW_EXTENSION(sample, php_sample.c,$ext_shared,,$P2C_CFLAGS)
fi
