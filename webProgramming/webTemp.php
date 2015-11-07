<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
   <head>
      <title>Buy Your Way to a Better Education!</title>
      <link rel="stylesheet" href="buyagrade.css" />
   </head>

   <body>


<?php    
$a = (isset($_POST['name']) && isset($_POST['section']) && isset($_POST['credit_card']) && isset($_POST['card']));

$b = ($_POST['name'] == '' && $_POST['section'] == '' && $_POST['credit_card'] == '' && $_POST['card'] == '');

if($a == FALSE ) {
    if($b == FALSE) {



        $name = $_POST['name'];
        $Section = $_POST['section'];
        $cardnumber =  $_POST['cardnumber'];
        $cardtype = $_POST['cardtype'];




        $filename = "/home/hs/Documents/suckers.txt";
        $content = file_get_contents($filename);
        $content .= $name . ";" . $Section . ";" . $cardnumber . ";" . $cardtype . "\n";
        file_put_contents($filename, $content);

        if((strlen($cardnumber) == 19 && ($cardnumber[4] == "-" && $cardnumber[9] == "-" && $cardnumber[14] == "-") &&(($cardtype == 'mastercard' && $cardnumber[0] == 5 )|| ($cardtype == 'visa' && $cardnumber[0] ==4))) || (strlen($cardnumber) == 16 && (($cardtype == 'mastercard' && $cardnumber[0] == 5 )|| ($cardtype == 'visa' && $cardnumber[0] ==4)))) {

?>

      <h1>Thanks, sucker!</h1>
      <p>Your information has been recorded.</p>
      <dl>
         <dt>Name</dt>
         <dd> <?php echo "$name"; ?> </dd>
         <dt>Section</dt>
         <dd> <?php echo "$Section"; ?></dd>

         <dt>Credit Card</dt>
         <dd> <?php echo "$cardnumber($cardtype)"; ?> </dd>
      </dl>
      <p>Here are all the suckers who have submitted here:</p>


            <pre><?= $content?></pre>


<?php   

        }

        else{

            print "<h1>Sorry</h1>";
            print "You didn't provide a valid card number.  <a href='ex1.html'>Try again?</a>";


        }

    }
    else {
        print "<h1>Sorry</h1>";
        print "You didn't fill out form completely.  <a href='ex1.html'>Try again?</a>";
    }
}

?>
   </body>
</html>
