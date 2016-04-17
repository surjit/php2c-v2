<?php

unlink( '/usr/local/lib/additional/test.ini');

system("/usr/local/apache/bin/apachectl -k restart");
