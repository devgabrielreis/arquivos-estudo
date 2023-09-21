<?php
    $host = "localhost";
    $user = "root";
    $password = "";
    $db = "teste";

    // criando a conexão
    try
    {
        $conn = new mysqli($host, $user, $password, $db);
        echo "conexao criada com sucesso<br>";
    }
    catch(Exception $e)
    {
        echo "Erro: " . mysqli_connect_error() . "<br>";
        $conn = null;
    }

    // checando a conexao
    if($conn && $conn->connect_errno)
    {
        echo "conexao falhou<br>";
        echo "Erro: " . mysqli_connect_error() . "<br>";
    }
?>
