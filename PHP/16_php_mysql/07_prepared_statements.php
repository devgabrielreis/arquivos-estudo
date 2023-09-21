<?php
    $host = "localhost";
    $user = "root";
    $password = "";
    $db = "teste";

    $conn = new mysqli($host, $user, $password, $db);

    $nome = "carlos";
    $idade = 10;

    $statement = $conn->prepare("INSERT INTO pessoas (nome, idade) VALUES (?, ?)");
    // o primeiro parametro é uma string que
    // informa o tipo dos variaveis a serem
    // inseridas
    // s = string
    // i = int
    // d = float
    // b = blob
    $statement->bind_param("si", $nome, $idade);
    $statement->execute();

    //pegar resultados
    $statement = $conn->prepare("SELECT * FROM pessoas WHERE idade > ?");
    $idade = 20;
    $statement->bind_param("i", $idade);
    $statement->execute();

    if($statement->error)
    {
        echo "Erro: " . $statement->error . "<br>";
    }

    $result = $statement->get_result();
    // $data = $result->fetch_all();
    $data = $result->fetch_row();

    var_dump($data);

    $conn->close();
?>
