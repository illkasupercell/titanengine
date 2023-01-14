$result5 = dbquery("SELECT MAX(ID) FROM okb_db_itrzadan_statuses where ((ID_edo='".$render_row['ID']."') and (STATUS='Выполнено')) ");
$name5 = mysql_fetch_row($result5);
$total5 = $name5[0];
$result5 = dbquery("SELECT * FROM okb_db_itrzadan_statuses where (ID='".$total5."') ");
$name5 = mysql_fetch_array($result5);
$result6 = dbquery("SELECT * FROM okb_db_itrzadan where (ID='".$render_row['ID']."') ");
$name6 = mysql_fetch_array($result6);

//// дни

if ($name6['DATE_PLAN'][6] == 0) $name6_6 = $name6['DATE_PLAN'][7];
if ($name6['DATE_PLAN'][6] == 1) $name6_6 = $name6['DATE_PLAN'][7] + 10;
if ($name6['DATE_PLAN'][6] == 2) $name6_6 = $name6['DATE_PLAN'][7] + 20;
if ($name6['DATE_PLAN'][6] == 3) $name6_6 = $name6['DATE_PLAN'][7] + 30;

if ($name5['DATA'][6] == 0) $name5_6 = $name5['DATA'][7];
if ($name5['DATA'][6] == 1) $name5_6 = $name5['DATA'][7] + 10;
if ($name5['DATA'][6] == 2) $name5_6 = $name5['DATA'][7] + 20;
if ($name5['DATA'][6] == 3) $name5_6 = $name5['DATA'][7] + 30;

//// мес¤цы
if ($name6['DATE_PLAN'][5] == 1) $name6_d = 31;
if ($name6['DATE_PLAN'][5] == 2) $name6_d = 59;
if ($name6['DATE_PLAN'][5] == 3) $name6_d = 90;
if ($name6['DATE_PLAN'][5] == 4) $name6_d = 120;
if ($name6['DATE_PLAN'][5] == 5) $name6_d = 151;
if ($name6['DATE_PLAN'][5] == 6) $name6_d = 181;
if ($name6['DATE_PLAN'][5] == 7) $name6_d = 212;
if ($name6['DATE_PLAN'][5] == 8) $name6_d = 243;
if ($name6['DATE_PLAN'][5] == 9) $name6_d = 273;
if (($name6['DATE_PLAN'][5] == 0) and ($name6['DATE_PLAN'][4] == 1)) $name6_d = 304;
if (($name6['DATE_PLAN'][5] == 1) and ($name6['DATE_PLAN'][4] == 1)) $name6_d = 334;
if (($name6['DATE_PLAN'][5] == 2) and ($name6['DATE_PLAN'][4] == 1)) $name6_d = 365;

if ($name5['DATA'][5] == 1) $name5_d = 31;
if ($name5['DATA'][5] == 2) $name5_d = 62;
if ($name5['DATA'][5] == 3) $name5_d = 90;
if ($name5['DATA'][5] == 4) $name5_d = 121;
if ($name5['DATA'][5] == 5) $name5_d = 151;
if ($name5['DATA'][5] == 6) $name5_d = 182;
if ($name5['DATA'][5] == 7) $name5_d = 212;
if ($name5['DATA'][5] == 8) $name5_d = 243;
if ($name5['DATA'][5] == 9) $name5_d = 274;
if (($name5['DATA'][5] == 0) and ($name5['DATA'][4] == 1)) $name5_d = 304;
if (($name5['DATA'][5] == 1) and ($name5['DATA'][4] == 1)) $name5_d = 335;
if (($name5['DATA'][5] == 2) and ($name5['DATA'][4] == 1)) $name5_d = 365;

//// столетие
if ($name6['DATE_PLAN'][2] == 0) $name6_2 = $name6['DATE_PLAN'][3];
if ($name6['DATE_PLAN'][2] == 1) $name6_2 = $name6['DATE_PLAN'][3] + 10;
if ($name6['DATE_PLAN'][2] == 2) $name6_2 = $name6['DATE_PLAN'][3] + 20;
if ($name6['DATE_PLAN'][2] == 3) $name6_2 = $name6['DATE_PLAN'][3] + 30;
if ($name6['DATE_PLAN'][2] == 4) $name6_2 = $name6['DATE_PLAN'][3] + 40;
if ($name6['DATE_PLAN'][2] == 5) $name6_2 = $name6['DATE_PLAN'][3] + 50;
if ($name6['DATE_PLAN'][2] == 6) $name6_2 = $name6['DATE_PLAN'][3] + 60;
if ($name6['DATE_PLAN'][2] == 7) $name6_2 = $name6['DATE_PLAN'][3] + 70;
if ($name6['DATE_PLAN'][2] == 8) $name6_2 = $name6['DATE_PLAN'][3] + 80;
if ($name6['DATE_PLAN'][2] == 9) $name6_2 = $name6['DATE_PLAN'][3] + 90;

if ($name5['DATA'][2] == 0) $name5_2 = $name5['DATA'][3];
if ($name5['DATA'][2] == 1) $name5_2 = $name5['DATA'][3] + 10;
if ($name5['DATA'][2] == 2) $name5_2 = $name5['DATA'][3] + 20;
if ($name5['DATA'][2] == 3) $name5_2 = $name5['DATA'][3] + 30;
if ($name5['DATA'][2] == 4) $name5_2 = $name5['DATA'][3] + 40;
if ($name5['DATA'][2] == 5) $name5_2 = $name5['DATA'][3] + 50;
if ($name5['DATA'][2] == 6) $name5_2 = $name5['DATA'][3] + 60;
if ($name5['DATA'][2] == 7) $name5_2 = $name5['DATA'][3] + 70;
if ($name5['DATA'][2] == 8) $name5_2 = $name5['DATA'][3] + 80;
if ($name5['DATA'][2] == 9) $name5_2 = $name5['DATA'][3] + 90;

echo (($name5_6-$name6_6)+($name5_d-$name6_d-1))+($name5_2*365-$name6_2*365)+1;
