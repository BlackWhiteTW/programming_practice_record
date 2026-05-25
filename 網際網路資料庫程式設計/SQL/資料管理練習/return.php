<!DOCTYPE html>
<html lang="zh-TW">
    <head>
        <meta charset="UTF-8">
        <title>學生基本資料</title>
        <style>
                table {
                margin: auto;
                border-collapse: collapse;
                width: 300px;
                text-align: center;
            }
            th, td {
                border: 1px solid #cccccc;
                padding: 5px;
            }
            th {
                background-color: #f9f9f9;
            }
        </style>
    </head>
    <body>
        <?php
            $host = "localhost";
            $username = "root";
            $password = "123456";
            $dbname = "school";

            $conn = mysqli_connect($host, $username, $password, $dbname);

            if (!$conn) {
                die("資料庫連線失敗: " . mysqli_connect_error());
            }

            mysqli_set_charset($conn, "utf8");

            $sql = "SELECT stud_no, stud_name, stud_addr FROM students";
            $result = mysqli_query($conn, $sql);

            echo "<table>" , "<tr>" , "<th>學號</th>" , "<th>姓名</th>" , "<th>地址</th>" , "</tr>";

            while ($row = mysqli_fetch_row($result)) {
                echo "<tr>";
                echo "<td>" . $row[0] . "</td>";
                echo "<td>" . $row[1] . "</td>";
                echo "<td>" . $row[2] . "</td>";
                echo "</tr>";
            }
            echo "</table>";

            mysqli_free_result($result);
            mysqli_close($conn);
        ?>
    </body>
</html>