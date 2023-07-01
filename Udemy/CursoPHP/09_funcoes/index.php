<?php
    function funcao()
    {
        echo "Eu sou uma função!<br>";
    }

    funcao();

    function soma($num1, $num2)
    {
        return $num1 + $num2;
    }

    $result = soma(2, 6, 7); // o php ignora os parametros a mais;

    function subtracao($num1, $num2 = 10)
    {
        return $num1 - $num2;
    }

    echo subtracao(5) . "<br>";

    function someFunc($a, $b)
    {
        // retorna os argumentos da funcao
        // nesse caso os valores de $a e $b
        print_r(func_get_args());

        // retorna o numero de argumentos que
        // uma funcao recebeu, nesse caso 2
        echo func_num_args() . "<br>";
    }

    someFunc(4, 6);

    // var_dump e print_r sao uteis para debug
    $arr5 = [1, 2, 3, 4, 5, 6];
    print_r($arr5);
    echo "<br>";
    var_dump($arr5);
    echo "<br>";
?>
