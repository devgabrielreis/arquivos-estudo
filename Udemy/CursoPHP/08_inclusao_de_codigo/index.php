<?php
    include "p.html";
    include "funcs.php";
    include "nao_existente.php"; // include apenas lançará um warning
                                 // caso o arquivo não exista
    echo soma(10, 4)."<br>";

    require "funcs2.php";

    echo subtracao(8, 1);

    // require "nao_existente.php"; // gera um erro fatal

    // include_once "arquivo" // o arquivo só é incluido uma vez
    // require_once "arquivo" // o arquivo só é incluido uma vez
?>

// short tags
// <? echo "teste" ?>
// não utilizar!!!

// exibição de conteúdo
<?= "Teste 2" ?>

Um arquivo que mistura php com HTML costuma ter a extensão .phtml ou .php
