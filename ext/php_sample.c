
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php_sample.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "zend.h"
#include "zend_API.h"
#include "zend_exceptions.h"
#include "zend_operators.h"
#include "zend_constants.h"
#include "zend_ini.h"
#include "zend_interfaces.h"


static zend_function_entry sample_functions[] = {
  ZEND_FE(hello_world_fx, NULL)
  {NULL, NULL, NULL}
};


ZEND_FUNCTION(hello_world_fx)
{
  zval* name;

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE)
    return;

 zend_print_zval(name, 0);
}

/* here my clasess */

zend_class_entry *test_ce;

PHP_METHOD(Test, getFoo)
{
    zval *obj, *foo_value;

    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    obj = getThis();

    foo_value = zend_read_property(test_ce, obj, "foo", sizeof("foo") - 1, 1 TSRMLS_CC);

    RETURN_ZVAL(foo_value, 1, 0);
}

PHP_METHOD(Test, setFoo)
{
    zval *obj, *new_foo_value;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &new_foo_value) == FAILURE) {
        return;
    }

    obj = getThis();

    zend_update_property(test_ce, obj, "foo", sizeof("foo") - 1, new_foo_value TSRMLS_CC);
}

ZEND_BEGIN_ARG_INFO_EX(arginfo_void, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_set, 0, 0, 1)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

const zend_function_entry test_functions[] = {
    PHP_ME(Test, getFoo, arginfo_void, ZEND_ACC_PUBLIC)
    PHP_ME(Test, setFoo, arginfo_set, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_MINIT_FUNCTION(sample)
{
    zend_class_entry tmp_ce;
    INIT_CLASS_ENTRY(tmp_ce, "Test", test_functions);

    test_ce = zend_register_internal_class(&tmp_ce TSRMLS_CC);

    return SUCCESS;
}

/** class end */

zend_module_entry sample_module_entry = {
  STANDARD_MODULE_HEADER,
  "sample",
  sample_functions,
  PHP_MINIT(sample),
  NULL,
  NULL,
  NULL,
  NULL,
  "1.0",
  STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SAMPLE
ZEND_GET_MODULE(sample)
#endif


