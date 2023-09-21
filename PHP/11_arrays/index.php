<?php
    header("Content-type: text/plain");

    // adicionando novos dados a um array;
    $arr = [];

    var_dump($arr);

    $arr[2] = "teste";
    $arr[2] .= " de array";

    var_dump($arr);

    // arrays associativos;
    $arrayAssociativo = ["nome" => "Gabriel", "idade" => 22];
    $arrayAssociativo["estado"] = "São Paulo";

    var_dump($arrayAssociativo);

    // adicionar itens no fim do array
    $arr = [];
    var_dump($arr);

    $arr[] = 8;
    $arr[] = 6;
    $arr[] = 4;
    var_dump($arr);

    // range
    $arr = range(0, 9, 2);
    var_dump($arr);
    echo gettype(range(0,5)) . "\n";

    // count
    echo count([1, 2, 3, 4, 5]) . "\n";

    // criando varias vaiaveis com os valores de um array
    $arr = [1, 2, 3];
    // a função ignora itens a mais
    // e lança um warning caso não haja
    // itens suficientes
    list($num1, $num2, $num3) = $arr;
    echo "$num1 $num2 $num3\n";

    // slicing
    $arr = [0, 1, 2, 3, 4, 5, 6, 7];
    var_dump(array_slice($arr, 5, 2));

    // array chunk
    $arr = range(1, 8);
    $arrays = array_chunk($arr, 3);
    var_dump($arrays);

    // pegar apenas chaves ou valores de um array associativo
    array_keys($arrayAssociativo);
    array_values($arrayAssociativo);

    // varificar se chave existe em um array associativo
    array_key_exists("nome", $arrayAssociativo); // retorna booleano
    isset($arrayAssociativo["nome"]); // isset tb serve para variaveis

    // remover diversos elementos de um array
    $arr = range(0, 9);
    $removidos = array_splice($arr, 2, 2);
    var_dump($arr);
    var_dump($removidos);

    // transformar chaves de um array em variaveis
    $arr = [
        "var1" => "valor",
        "var2" => "teste",
        "var3" => 42
    ];

    extract($arr);

    echo "$var1 $var2 $var3\n";
    // caso já exista uma variavel com o
    // mesmo nome ela sera sobrescrita

    // criar um array associativo a partir de variaveis
    $nome = "Carlos";
    $idade = 21;
    $estado = "Santa Catarina";

    $arr = compact("nome", "idade", "estado");

    var_dump($arr);

    // foreach com arrays
    foreach([1,2,3] as $num)
    {
        echo "$num ";
    }
    echo "\n";

    foreach (["var1" => "valor", "var2" => "teste","var3" => 42] as $key => $value)
    {
        echo "$key $value | ";
    }
    echo "\n";

    // array reduce
    $arr = [0,1,2,3,4];

    function soma($a, $b) {return $a + $b;}

    echo array_reduce($arr, "soma", 10) . "\n";

    // verificar se item esta na array
    $arr = ["banana", "maça", "pera", "laranja"];

    in_array("pera", $arr); // retorna um booleano

    // ordenar array
    $arr = [5,4,6,3,7,2,8,2,9,1,0];
    sort($arr);
    var_dump($arr);

    rsort($arr); // crescente
    var_dump($arr); // decrescente

    $arr = [
        "var1" => "valor",
        "var2" => "teste",
        "var3" => 42
    ];
    asort($arr); // ordena pelos valores
    arsort($arr); // ordena pelos valores em ordem decescente
    ksort($arr); // ordena pelas chaves
    krsort($arr); // ordena pelas chaves em ordem decrescente

    // reverter arrays
    $arr = [1,2,3,4,5];
    $arrRevertido = array_reverse($arr);
    // não altera a array original

    // embaralhar arrays
    shuffle($arr);
    // altera o array original

    // somar arrays
    $arr = range(0, 10);
    echo array_sum($arr) . "\n";

    // unindo arrays
    $arr = [1,2,3];
    $arr2 = [10, 20, 30];

    var_dump(array_merge($arr, $arr2));

    // calcular diferença entre arrays
    array_diff($arr, $arr2);
?>
