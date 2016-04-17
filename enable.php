<?php


$fp = fopen( '/usr/local/lib/additional/test.ini' , 'w+');
fwrite($fp, "extension=test.so");
fclose( $fp );

system("/usr/local/apache/bin/apachectl -k restart");
