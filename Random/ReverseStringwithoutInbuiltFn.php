<?php

$str='Hello';
// for($i=0;$str[$i]!="";$i++){
//     echo $str[$i].'-';
// }
function recursiveReverse($s,$i){
    if($s[$i] === "") return;
    
    recursiveReverse($s,$i+1);
    echo $s[$i];
}
recursiveReverse($str,0);