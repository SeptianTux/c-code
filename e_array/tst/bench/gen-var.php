<?php



$char_list_var  = "q w e r t y u i o p a s d f g h j k l z x c v b n m Q W E R T Y U I O P A S D F G H J K L Z X C V B N M 1 2 3 4 5 6 7 8 9 0";
$char_list_arr  = explode (" ", $char_list_var);
$loop_max = 1000;
$val_strlen = 0;
$val = "";
$val_arr = array();

for ($i=0; $i<$loop_max-1; $i++)
{
    $val_strlen = rand(2, 256);
    $val = "    strcpy(data[$i], \"";
    
    
    for ($j=0; $j<=$val_strlen-1; $j++)
    {
        $val = $val . $char_list_arr[rand(0, 61)];
    }
    
    //$val_arr[$i] = $val . "\";";
    echo $val . "\");\n";
}


//print_r ($val_arr);
