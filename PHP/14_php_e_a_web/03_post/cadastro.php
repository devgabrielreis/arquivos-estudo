<?php
    var_dump($_POST);
    echo "<BR>";
    $marca = $_POST["marca"];
    $preco = $_POST["preco"];
    $tetosolar = isset($_POST["opcionais"]["tetosolar"]);
    $pelicula = isset($_POST["opcionais"]["pelicula"]);
    $blindado = isset($_POST["opcionais"]["blindado"]);
?>

<p>Você cadastrou um carro da marca <?php echo $marca ?></p>
<p>Preço: <?php echo $preco ?></p>
<?php if($tetosolar) : ?>
    <p>Você quer teto solar.</p>
<?php endif ?>
<?php if($pelicula) : ?>
    <p>Você quer pelicula.</p>
<?php endif ?>
<?php if($blindado) : ?>
    <p>Você quer um carro blindado</p>
<?php endif ?>
