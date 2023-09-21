<?php
    $_variavel = "eu sou uma variavel";
    echo $_variavel;
    echo "<br>";
    $velocidadeMaxima = 100;

    // variavel de variavel
    $nome = "Gabriel";

    $var = "nome";

    $$var = "Bob";

    echo $nome; // Bob
    echo "<br>";

    // variavel por referencia
    $valor = 1200;

    $ponteiro =& $valor;

    $ponteiro = 1000;

    echo $valor; // 1000
    echo "<br>";

    // escopo

    //local
    function teste()
    {
        $varLocal = 5;

        echo "$varLocal <br>";
    }

    teste();

    // global
    $varGlobal = "eu sou uma variavel global";

    function teste2()
    {
        global $varGlobal;

        echo "$varGlobal <br>";

        $varGlobal = "variavel global alterada dentro da funcao";
    }

    teste2();

    echo "$varGlobal <br>";

    // static
    function testeStatic()
    {
        static $var = 10;
        $var++;
        echo "$var<br>";
    }

    testeStatic();
    testeStatic();
    testeStatic();

    // parametros
    function soma($num1, $num2)
    {
        return $num1 + $num2;
    }

    $num = 10;

    echo "$num + 15 = ".soma($num, 15)."<br>";
?>
