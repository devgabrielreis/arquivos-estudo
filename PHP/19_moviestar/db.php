<?php
    $db_name = "moviestar";
    $db_host = "localhost";
    $db_user = "root";
    $db_pass = "";

    $conn = new PDO("mysql:host=$db_host;dbname=$db_name", $db_user, $db_pass);

    // habilitar erros pdo
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $conn->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
?>
