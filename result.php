<?php
header("Content-type: text/html; charset=utf-8");

$Code=$_POST['code'];
$username=$_POST['username'];
//$username.='.txt';

//echo "$Code";
//echo "$username";

$fpoint=fopen("/var/www/html/code/".$username,w);
if(fwrite($fpoint,$Code)){
	//echo '写入成功<p>';
}

//执行shell
$ShCommand="./code.sh ./code/".$username;
$result= exec($ShCommand);
//echo "./code.sh "."./code/".$username;

/*$ReFileName="Result";
$handle=fopen($ReFileName,r);
$result=fread($handle,4096);
 */

?>
<table width=500 border="0" align="center" cellpadding="$pagesize" cellspacing="1" bgcolor="#add3ef">
<tr bgColor="#ffffff"> 
<td>统计结果：<br /><?=$result?></td> 
</tr> 
</table>
