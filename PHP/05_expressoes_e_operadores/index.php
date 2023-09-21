<?php
    // mudança de tipo implícito (auto cast)

    echo 5 / 2; // inteiro / inteiro resultou em float

    if(is_string(5 . 2))
    {
        echo "<br>o . concatena strings<br>";
    }

    echo "\"5\" * 12 resulta num valor do tipo " . gettype("5" * 12) . "(" . "5" * 12 . ")<br>";

    // operadores

    // modulo
    5 % 2; // 1

    // exponeciação
    5 ** 2; // 25

    // concatenação
    "He"."llo"; // "Hello"

    // auto incremento e decremento
    $a = 5;
    $a++; // 6
    $a--; // 5

    // comparacao
    5 == "5"; // true
    5 === "5"; // false
    5 != "5"; // false
    5 !== "5"; // true
    5 >= 5; // true
    5 <= 6; // true
    5 < 4; // false
    5 > 4; // true

    // operadores logicos
    (1 > 0) && (2 > 1); // AND
    (1 < 0) || (2 > 1); // OR
    !(1 === 0); // NOT

    if(true xor false)
    {
        echo "xor = exclusive or<br>";
    }

    // operador de cast
    // tipos: int, bool, float, string, array, object e unset
    echo (int)2.7; // 2
    echo "<br>";

    // operador de atribuicao
    $b = 10;
    $b += 1; // 11
    $b -= 1; // 10
    // existem tb /= *= e %=

    // operador ternário
    echo ((55 < 100) ? "é verdadeiro" : "é falso")."<br>";
?>
