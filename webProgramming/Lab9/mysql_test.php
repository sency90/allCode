<?php
	$db = mysql_connect("localhost", "root", "");
	mysql_select_db("company");

	$results = mysql_query("select fnmae, lname, salary from employee where salary >= 30000 and (sex='F' or fname like 'J%') order by salary");

	while ($record = mysql_fetch_array($results)) {
		?>
		<li> <?= $record["lname"] ?>, ruled by <?= $record["salary"] ?> </li>
		<?php
	}	
?>