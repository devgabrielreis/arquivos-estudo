<?php
    $host = "localhost";
    $dbname = "agenda";
    $user = "root";
    $password = "";

    try
    {
        $conn = new PDO("mysql:dbname=$dbname;host=$host", $user, $password);

        // Ativat o modo de erros
        $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    }
    catch (PDOException $e)
    {
        $error = $e->getMessage();
        echo "Erro: $error<br>";
    }
?>
