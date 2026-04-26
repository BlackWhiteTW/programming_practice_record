
<!DOCTYPE html>
<!-- saved from url=(0056)https://webcourse.ncue.edu.tw/Web/PHP/examples/form.html -->
<html><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>
    </title>
    <link rel="stylesheet" href="https://webcourse.ncue.edu.tw/Web/PHP/examples/form.html">
    <style>
        table{
			width: 500px;
			border: 1px solid #000;
			border-collapse: collapse;
		}
		td{
			border: 1px solid #000;
			text-align: center
			
		}
		.c1{
			background-color: pink
		}
	</style>
    
</head>

<body>
    <form name="MyForm1" action="" method="POST">　
        <input type="text" name="num">
        <button type="submit">送出</button>
        
    </form>
    <table>
        <?php
        if (!isset($_POST['num']) || $_POST['num'] === '') {
            $num = 2;
        } else {
            $num = $_POST['num'];
        }
        for($i=1; $i<=9; $i++){
            echo "<tr>" . "<td>$num</td>" . "<td>$i</td>" . "<td class='c1'>" . ($num * $i) . "</td>" . "</tr>";
        }
        ?>
    </tbody></table>
</body></html>