<?php

echo '<pre>';

$t = new Test;
var_dump($t->getFoo()); // NULL (and no notice, because we passed silent=1)

$t->setFoo("abc");
var_dump($t->foo);      // "abc"
var_dump($t->getFoo()); // "abc"

$t->foo = "def";
var_dump($t->foo);      // "def"
var_dump($t->getFoo()); // "def"

echo '</pre>';

