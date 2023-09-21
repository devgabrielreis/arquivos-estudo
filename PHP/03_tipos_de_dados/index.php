<?php
    // inteiro
    $idade = 22;
    echo $idade / 7;
    echo "<br>";
    echo intdiv(10, 3);
    echo "<br>";
    echo 5 * 5;

    if(is_int($idade))
    {
        echo "<br>o valor da variável \$idade é inteiro<br>";
    }

    $nome = "Gabriel";

    if(!is_int($nome))
    {
        echo "o valor da variável \$nome não é inteiro<br>";
    }

    // float

    $saldo = -1.22;

    if(is_float($saldo))
    {
        echo "o saldo é um float ($saldo)<br>";
    }

    $saldo = -1.00;

    echo "$saldo<br>";

    if(is_float($saldo))
    {
        echo "o saldo é um float ($saldo)<br>";
    }

    if(!is_int($saldo))
    {
        echo "o valor da variável \$saldo não é inteiro<br>";
    }

    // string
    $nome = 'Essa é uma string';

    $num = 10;

    echo "o número é $num<br>";
    echo 'o número é $num<br>';

    echo is_string($nome);
    echo "<br>";

    // booleano
    $started = true;
    $ended = false;

    echo "$started $ended <br>";
    
    $isbool = is_bool($ended);

    // array
    $frutas = ["maça", "banana", "pera", "laranja", 0];

    echo $frutas[1];
    echo "<br>";
    print_r($frutas);
    print("<br>");
    print_r($nome);
    print("<br>");

    // array associativo
    $pessoa = [
        "nome" => "Gabriel",
        "idade" => 22
    ];

    echo $pessoa["nome"];
    echo "<br>";
    print_r($pessoa);
    echo "<br>";

    // objetos
    class Pessoa
    {
        function falar()
        {
            echo "Olá<br>";
        }
    }

    $gabriel = new Pessoa();
    $gabriel->nome = "Gabriel";

    echo "$gabriel->nome<br>";

    $gabriel->falar();

    // null
    $nada = NULL;

    if(is_null($nada))
    {
        echo "vazio<br>";
    }
?>
