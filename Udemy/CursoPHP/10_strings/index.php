<?php
    // muda o tipo de arquivo para texto puro
    header("Content-type: text/plain");

    // interpolando variaveis
    $nome = "Gabriel";

    echo "O nome dele é $nome\n";
    echo "O nome dele é {$nome}\n";

    // valores de escape
    print("nada de \"novo\"\n");

    // strlen() retorna o número de caracteres numa string
    echo "O nome dele possui ".strlen($nome)." letras.\n";

    // percorrendo strings
    for($i = 0; $i < strlen($nome); $i++)
    {
        echo $nome[$i];
    }
    echo "\n";

    // removendo espaços em branco no
    // começo e final da string
    $nome2 = "     Carlos    ";
    $nome3 = "      Rodrigo     ";

    echo ".".trim($nome2).".\n";
    echo ".".rtrim(ltrim($nome3)).".\n";
    // as strings originais não são alteradas

    // alterando o case da string
    $nome = "gabriel reis de jesus campos";
    echo strtolower($nome);
    echo "\n";
    echo strtoupper($nome);
    echo "\n";
    echo ucfirst($nome); // primeira letra da string fica maiuscula
    echo "\n";
    echo ucwords($nome); // primeira letra de cada palavra fica maiuscula
    echo "\n$nome\n";
    // as strings originais não são alteradas

    // removendo tags do HTML
    $str = "<h1>nome</h1>";

    echo strip_tags($str);
    echo "\n" . $str . "\n";

    // substring
    echo substr("eae glr", 4, 3) . "\n";
    // as strings originais não são alteradas

    // inverter string
    echo strrev("abcde") . "\n";
    // as strings originais não são alteradas

    //  repetir string
    echo str_repeat("oi", 10) . "\n";
    // as strings originais não são alteradas

    // string para array
    $str = "string de teste";
    echo var_dump(explode(" ", $str)) . "\n";
    echo gettype($str) . "\n";
    // as strings originais não são alteradas

    // array para string
    $arr = ["a", "r", "r", "o", "z"];
    echo implode(" ", $arr) . "\n";

    // encontrar substr na string
    $string = "o cachorro comeu a racao";

    if(strpos($string, "cachorro") !== false) // retorna false caso nao encontre
    {
        echo "a palavra cachorro esta no indice " . strpos($string, "cachorro") . "\n";
    }

    // encontrar a ultima ocorrencia de uma substring na string
    $string = "oioioioioi";

    if(strrpos($string, "oi") !== false) // retorna false caso nao encontre
    {
        echo "o ultimo oi esta no indice " . strrpos($string, "oi") . "\n";
    }

    // retornando o resto da string
    // com a funcao strstr() podemos encontrar um texto em uma string
    // se algo for encontrado, a funcao vai retornar o resto da string
    // apos o texto encontrado
    // se nao encontrar nada retorna false
    echo strstr("ola pessoas do grupo!!!!", "pessoas") . "\n";

    // decompor uma url
    var_dump(parse_url("https://subdominio.gabrielreis.dev.br/funcionalidade/opcao?id=4"));
?>
