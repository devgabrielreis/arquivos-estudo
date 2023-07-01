<?php
    var_dump($_GET);
    echo "<br>";

    $nome = $_GET["nome"];
    $idade = $_GET["idade"];
?>

<?php if(strlen($idade) && strlen($nome)) : ?>
    <h1>O seu nome é <?php echo $nome ?> e você tem <?php echo $idade ?> anos.</h1>
<?php else : ?>
    <h1>Dados incompletos.</h1>
<?php endif ?>
