<?php
    include_once("db.php");
    include_once("dao/CarDAO.php");

    $carDAO = new CarDAO($conn);

    $cars = $carDAO->findAll();
?>

<h1>Insira um carro</h1>
<form action="process.php" method="POST">
    <div>
        <label for="brand">Marca do carro:</label>
        <input type="text" name="brand" placeholder="Insira a marca">
    </div>
    <div>
        <label for="brand">Kilometragem:</label>
        <input type="text" name="km" placeholder="Insira a kilometragem">
    </div>
    <div>
        <label for="brand">Cor do carro:</label>
        <input type="text" name="color" placeholder="Insira a cor">
    </div>
    <input type="submit" value="Salvar">
</form>
<ul>
    <?php foreach($cars as $car) : ?>
        <li><?php echo $car->getBrand(); ?> - <?php echo $car->getKm(); ?>km - <?php echo $car->getColor(); ?></li>
    <?php endforeach; ?>
</ul>
