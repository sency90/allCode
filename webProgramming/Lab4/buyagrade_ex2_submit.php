<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<title>Buy Your Way to a Better Education!</title>
		<link rel="stylesheet" href="buyagrade.css" />
	</head>

	<body>
	<form action="" method="get">
		<h1>Thanks, sucker!</h1>
		<p>Your information has been recorded.</p>
		<dl>
			<dt>Name</dt>
			<dd><?php echo $_POST['name'] ?></dd>

			<dt>Section</dt>
			<dd><?php echo $_POST['section'] ?></dd>

			<dt>Credit Card</dt>
			<dd><?php echo $_POST['cardnumber'] ?> ( <?php echo $_POST['cardtype'] ?> ) </dd>
		</dl>
	</form>
	</body>
</html>
?>