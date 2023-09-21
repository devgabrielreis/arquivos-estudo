<?php
    // alterar fuso horario
    date_default_timezone_set("America/Sao_Paulo");

    // funcao date
    $hoje = date("d/m/Y");

    echo "hoje é $hoje<br>";
    var_dump($hoje);
    echo "<br>";

    // string to time
    echo strtotime("1 minute", 0) . "<br>";
    $amanha = date("d/m/y", strtotime("1 day"));

    echo "amanha é $amanha<br>";

    // funcao mktime
    $dia = mktime(0, 0, 0, 2, 17, 2001);
    echo date("d/m/Y", $dia) . "<br>";

    // objeto DateTime
    $dia = new DateTime();
    var_dump($dia);
    echo "<br>";

    echo "hoje é " . $dia->format('d/m/Y') . " <br>";

    $dia->modify("+1 month");
    echo "daqui a um mes sera " . $dia->format('d/m/Y') . " <br>";

    $dia->setDate(2001, 2, 17); // altera a data
    var_dump($dia);
    echo "<br>";

    $dia->setTime(14, 30, 15); // altera a hora
    var_dump($dia);
    echo "<br>";

    // calcular diferenca entre datas
    $hoje = new DateTime();
    $diferenca = $dia->diff($hoje);
    var_dump($diferenca);
    echo "<br>";

    // é possivel comparar datas
    var_dump($dia > $hoje);
    echo "<br>";
    var_dump($dia < $hoje);
    echo "<br>";
    var_dump($dia === $hoje);
    echo "<br>";
?>
