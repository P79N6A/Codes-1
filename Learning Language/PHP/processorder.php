<html>
<head>
	<title>Bob 's Auto Parts - Order Results</title>
</head>
<body>
	<h1>Bob 's Auto Parts</h1>
	<h2>Order Results</h2>
	<table boder = "0" cellpadding = "5">
	<tr>
		<td bgcolor = "#cccccc" align = "center">How did you find Bob's?</td>
		<td><select name = 'find'>
			<option value = 'a'>Web</option>
			<option value = 'b'>Friends</option>
		</td>
	</tr>
	<tr>
		<td bgcolor = "#cccccc">Distance</td>
		<td bgcolor = "#cccccc">Cost</td>
	</tr>
	<?php
		$tireqty = $_POST[ 'tireqty' ];
		$oilqty = $_POST[ 'oilqty' ];
		$sparkqty = $_POST[ 'sqarkqty'];
		echo '<p>Your order is as follows:</p>';
		echo $tireqty.'tires<br/>';
		echo $oilqty.'bottles of oil<br/>';
		echo $sparkqty.'sqark plugs<br/>';
		echo '<p style="color:red">Order processed at'.@date(" H:i, jS F Y")."</p>";
		//phpinfo();
		$distance = 50;
		while ($distance <= 250)
		{
			echo "<tr>
					<td align = \"right\">$distance</td>
					<td align = \"right\">".($distance/10)."</td>
				</tr>\n";
			$distance += 50;
		}
		$outputstring = "What happened ?".@date(" H:i, jS F Y");
		//$p = fopen("/users/apple1/desktop/order.rtf", "ab");
		//fwrite($p, $outputstring, strlen($outputstring));
		//fclose($p);
	?>
</body>
</html>