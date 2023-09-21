<?php
    $validacoes = [];

    if(count($_POST) > 0)
    {
        if(strlen($_POST["nome"]) > 0)
        {
            if(strlen($_POST["nome"]) < 3)
            {
                $validacoes[] = "Nome muito curto";
            }
        }
        else
        {
            $validacoes[] = "Insira seu nome";
        }

        if(strlen($_POST["email"]) > 0)
        {
            if(strlen($_POST["email"]) < 3)
            {
                $validacoes[] = "E-mail muito curto";
            }
        }
        else
        {
            $validacoes[] = "Insira seu e-mail";
        }

        if(strlen($_POST["senha"]) > 0)
        {
            if(strlen($_POST["senha"]) < 8)
            {
                $validacoes[] = "Senha muito curta";
            }
            elseif($_POST["senha"] !== $_POST["confirmacao"])
            {
                $validacoes[] = "As senhas não coincidem";
            }
        }
        else
        {
            $validacoes[] = "Insira uma senha";
        }

        if(count($validacoes) === 0)
        {
            echo "Cadastrado com sucesso!";
        }
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Validação de Form</title>
</head>
<body>
    <?php if(count($validacoes)) : ?>
        <ul>
            <?php foreach($validacoes as $validacao) : ?>
                <li><?php echo $validacao?></li>
            <?php endforeach; ?>
        </ul>
    <?php endif; ?>
    <form action="index.php" method="POST">
        <div>
            <input type="text" name="nome" placeholder="Digite seu nome">
        </div>
        <div>
            <input type="text" name="email" placeholder="Digite seu e-mail">
        </div>
        <div>
            <input type="password" name="senha" placeholder="Digite a sua senha">
        </div>
        <div>
            <input type="password" name="confirmacao" placeholder="Confirme sua senha">
        </div>
        <div>
            <input type="submit" value="Enviar">
        </div>
    </form>
</body>
</html>