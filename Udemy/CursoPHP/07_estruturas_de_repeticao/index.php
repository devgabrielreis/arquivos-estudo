<?php
    $condicao = false;

    $arr = [0, 2, 5, 3, 4, 2, 3];
    $x = count($arr);
    $y = 0;

    while($y < $x)
    {
        if($arr[$y] === 5)
        {
            $y++;
            continue;
        }

        echo $arr[$y]."<br>";

        if($arr[$y] === 4)        
        {
            break;
        }

        $y++;
    }

    do
    {
        break;
    } while($condicao);

    $arr2 = [];
    
    for($i = 0; $i < 5; $i++)
    {
        array_push($arr2, $i);
    }

    foreach($arr2 as $num)
    {
        echo "$num<br>";
    }
?>
