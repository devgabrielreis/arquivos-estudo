<?php
    $host = "localhost";
    $user = "root";
    $password = "";
    $db = "teste";

    $conn = new mysqli($host, $user, $password, $db);

    $sql = "SELECT * FROM pessoas";

    $result = $conn->query($sql);
    
    $pessoas = $result->fetch_all();

    var_dump($pessoas);

    echo "<br>";
    echo "<br>";

    foreach($pessoas as $pessoa)
    {
        echo "$pessoa[0] tem $pessoa[1] anos<br>";
    }

    $conn->close(); // encerra a conexao
?>
