<?php
    header("content-type:text/plain");
?>

SERVER_SOFTWARE identificacao do servidor
SERVER_NAME hostname dns ou ip do servidor
SERVER_PROTOCOL protocolo do servidor
SERVER_PORT porta do servidor
QUERY_STRING argumentos apos o ? na url

<?php
    var_dump($_SERVER);
?>
