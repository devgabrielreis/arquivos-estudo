<?php
    $expressao = true;

    if($expressao)
    {
        echo "a primeira expressão é verdadeira<br>";
    }
    else if($expressao)
    {
        echo "a primeira expressão é falsa mas a segunda é verdadeira<br>";
    }
    else
    {
        echo "nenhuma expressão é verdadeira<br>";
    }

    $diaDaSemana = 5;
    $dia = NULL;

    switch($diaDaSemana)
    {
        case 0:
            $dia = "domingo";
            break;
        case 1:
            $dia = "segunda-feira";
            break;
        case 2:
            $dia = "terça-feira";
            break;
        case 3:
            $dia = "quarta-feira";
            break;
        case 4:
            $dia = "quinta-feira";
            break;
        case 5:
            $dia = "sexta-feira";
            break;
        case 6:
            $dia = "sábado";
            break;
        default:
            $dia = "inválido";
            break;
    }

    echo "Hoje é ".$dia."<br>";
?>
