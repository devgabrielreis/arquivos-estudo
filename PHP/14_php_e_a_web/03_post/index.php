<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>POST</title>
</head>
<body>
    <form action="cadastro.php" method="POST">
        <div>
            <input type="text" name="marca" placeholder="Marca do carro">
        </div>
        <div>
            <input type="text" name="preco" placeholder="Preço do carro">
        </div>
        <div>
            <input type="checkbox" name="opcionais[tetosolar]" id="tetosolar" value="1">
            <label for="tetosolar">Teto solar</label>
        </div>
        <div>
            <input type="checkbox" name="opcionais[pelicula]" id="pelicula" value="1">
            <label for="pelicula">Pelicula</label>
        </div>
        <div>
            <input type="checkbox" name="opcionais[blindado]" id="blindado" value="1">
            <label for="blindado">Blindagem</label>
        </div>
        <div>
            <input type="submit" value="Enviar">
        </div>
    </form>
</body>
</html>
