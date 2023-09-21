<?php
    // habilitar o pdo no arquivo php.ini
    // descomentando (ou adicionando) as linhas
    // php_pdo
    // e
    // php_pdo_mysql

    $host = "localhost";
    $db = "teste";
    $user = "root";
    $password = "";

    $conn = new PDO("mysql:dbname=$db;host=$host", $user, $password);

    $nome = "Manuela";
    $idade = 19;

    $statement = $conn->prepare("INSERT INTO pessoas (nome, idade) VALUES (:nome, :idade)");
    
    $statement->bindParam(":nome", $nome);
    $statement->bindParam(":idade", $idade);

    $statement->execute();


    $statement = $conn->prepare("SELECT * FROM pessoas WHERE idade > :idade");

    $idade = 20;

    $statement->bindParam(":idade", $idade);

    $statement->execute();

    // $result = $statement->fetch(PDO::FETCH_ASSOC);
    $result = $statement->fetchAll(PDO::FETCH_ASSOC);

    foreach($result as $pessoa)
    {
        echo $pessoa["nome"] . " tem " . $pessoa["idade"] . " anos<br>";
    }

    $conn = null; // encerra a conexão
?>
