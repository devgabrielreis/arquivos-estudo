<?php
    if(isset($_COOKIE["nome"]))
    {
        $nome = $_COOKIE["nome"];
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Cookies</title>
</head>
<body>
    <h1>Página!</h1>
    <?php if(isset($nome)) : ?>
        <h1>Bem vindo de volta <?php echo $nome ?>!</h1>
    <?php endif; ?>
</body>
</html>