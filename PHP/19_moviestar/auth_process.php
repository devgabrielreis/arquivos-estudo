<?php
    require_once("globals.php");
    require_once("db.php");
    require_once("models/User.php");
    require_once("models/Message.php");
    require_once("dao/UserDAO.php");

    $message = new Message($BASE_URL);

    $userDao = new UserDAO($conn, $BASE_URL);

    // resgata o tipo do formulario
    $type = filter_input(INPUT_POST, "type");

    // verificacao do tipo de formulario
    if ($type === "register")
    {
        $name = filter_input(INPUT_POST, "name");
        $lastname = filter_input(INPUT_POST, "lastname");
        $email = filter_input(INPUT_POST, "email");
        $password = filter_input(INPUT_POST, "password");
        $confirmpassword = filter_input(INPUT_POST, "confirmpassword");

        // verificacao de dados minimos
        if($name && $lastname && $email && $password)
        {
            if($password === $confirmpassword)
            {
                // verifica se o email ja esta cadastrado no sistema
                if($userDao->findByEmail($email) === false)
                {
                    $user = new User();

                    // criacao de token e senha
                    $userToken = $user->generateToken();
                    $finalPassword = $user->generatePassword($password);

                    $user->name = $name;
                    $user->lastname = $lastname;
                    $user->email = $email;
                    $user->password = $finalPassword;
                    $user->token = $userToken;

                    $auth = true;

                    $userDao->create($user, $auth);
                }
                else
                {
                    // envia uma mensagem de erro, pois o usuario ja existe
                    $message->setMessage("Usuário já cadastrado, tente outro e-mail.", "error", "back");
                }
            }
            else
            {
                // enviar uma mensagem de erro pois as senhas nao batem
                $message->setMessage("As senhas não são iguais.", "error", "back");
            }
        }
        else
        {
            // enviar uma msg de erro, de dados faltantes
            $message->setMessage("Por favor, preencha todos os campos.", "error", "back");
        }
    }
    elseif ($type === "login")
    {
        $email = filter_input(INPUT_POST, "email");
        $password = filter_input(INPUT_POST, "password");

        // tenta autenticar o usuario
        if($userDao->authenticateUser($email, $password))
        {
            $message->setMessage("Seja bem-vindo!", "success", "editprofile.php");
        }
        // redireciona o usuario, cajo nao conseguir logar
        else
        {
            $message->setMessage("Usuário e/ou senha incorretos.", "error", "back");
        }
    }
    else
    {
        $message->setMessage("Informações inválidas.", "error", "index.php");
    }
?>
