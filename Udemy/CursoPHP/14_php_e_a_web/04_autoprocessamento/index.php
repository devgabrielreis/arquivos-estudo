<?php
    $httpMethod = $_SERVER["REQUEST_METHOD"];

    if($httpMethod === "POST")
    {
        $nome = $_POST["nome"];
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Autoprocessamento</title>
</head>
<body>
    <?php if($httpMethod === "GET") : ?>
        <form action="index.php" method="POST" onsubmit="return onSubmit()">
            <div>
                <input class="nome" type="text" name="nome" placeholder="Digite seu nome">
            </div>
            <div>
                <input type="submit" value="Enviar">
            </div>
            <div>
                <p></p>
            </div>
        </form>
    <?php else : ?>
        <h1>O seu nome é <?php echo $nome ?></h1>
    <?php endif; ?>

    <script>
        function onSubmit()
        {
            let inpt = document.querySelector(".nome");

            if (inpt.value.length < 3)
            {
                document.querySelector("p").innerHTML = "Nome muito curto";
                return false;
            }

            return true;
        }
    </script>
</body>
</html>