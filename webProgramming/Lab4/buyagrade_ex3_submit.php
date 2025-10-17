<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<title>Buy Your Way to a Better Education!</title>
		<link rel="stylesheet" href="buyagrade.css" />
	</head>
	<?php $file='people.txt'; $current=file_get_contents($file); ?>

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
				<dd><?php echo $_POST['cardnumber']; echo " ( "?>
				
				<?php echo $_POST['cardtype']; echo " )" ?>
				</dd>

				<dt>Here are all the suckers who have submitted here:</dt>
				<dd>
					<?php
					$file = 'people.txt';
					$current = $_POST['name'];
					$current .= ";";
					$current .= $_POST['section'];
					$current .= ";";
					$current .= $_POST['cardnumber'];
					$current .= ";";
					$current .= $_POST['cardtype'];
					$current .= "\r\n";

					//file을 write용으로 열어서 쓰는 부분이다.
					file_put_contents($file, $current, FILE_APPEND | LOCK_EX);

					//file을 read용으로 열어서 읽어들인 것을 string형태로 저장하는 것이다.
					//그러므로 allData는 string 변수이다.
					$allData = file_get_contents($file);

					//explode는 전체 스트링을 separator 단위로 끊어서 배열에 저장해준다.
					//여기서 lines가 배열 변수이고 "\r\n"이 separator(구분자)에 해당되며 allData가 전체 string에 해당된다.
					$lines = explode("\r\n", $allData);

					//배열에 관해서 반복문을 돌릴때에는 foreach 반복문이 편하다.
					//기본적인 c언어의 for문도 제공한다.
					//아무튼 아래의 코드는 lines라는 배열을 하나씩 반복문으로 돌리는데,
					//각 배열의 값을 line 변수에 담는다는 것이다.
					//참고로 띄어쓰기 부분에서 <br>을 써주지 않으면 절대로 new line이 안되니 참고하자.
					foreach($lines as $line) {
						echo "$line <br>";
					}

					?>
				</dd>
			</dl>
		</form>
	</body>
</html>