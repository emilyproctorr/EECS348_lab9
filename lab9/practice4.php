<?php
if($_POST) {
    $num = $_POST["size"];

echo "<table border =\"1\">";
    echo "<tr >";
        echo "<td ></td> \n";
        for ($col=1; $col <= $num; $col++) {
            echo "<td>$col</td> \n";
        }
    echo "</tr>";

    for ($row=1; $row <= $num; $row++) {
        echo "<tr> \n";

        echo "<td>$row</td>";

        for ($col=1; $col <= $num; $col++) {
            $p = $col * $row;
            echo "<td>$p</td> \n";
        }

        echo "</tr>";
    }
echo "</table>";
}
?>
