<?php
    echo "index.php";

    if(isset($_GET["id"]))
    {
        echo "<br>" . $_GET["id"] . "<br>";
    }

    // .htaccess
    // RewriteEngine On
    // RewriteRule ^curso_php\/teste\/([0-9a-zA-z]+)[\/]?$ /curso_php/teste/index.php?id=$1 [L]
?>