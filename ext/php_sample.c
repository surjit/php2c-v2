
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
  ZEND_FE(hello_world, NULL)
  {NULL, NULL, NULL}
};

zend_module_entry sample_module_entry = {
  STANDARD_MODULE_HEADER,
  "sample",
  sample_functions,
  NULL,
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

ZEND_FUNCTION(hello_world)
{
  php_printf("Surjit 2.1 \n");
}

