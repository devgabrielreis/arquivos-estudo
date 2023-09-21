<?php
    $host = "localhost";
    $user = "root";
    $password = "";
    $db = "teste";

    $conn = new mysqli($host, $user, $password, $db);

    $sql = "SELECT * FROM pessoas";
    $result = $conn->query($sql);
    var_dump($result);
    $conn->close(); // encerra a conexao
?>
