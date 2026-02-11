<?php

    $dbServer = "mysql:host=localhost;dbname=my_database";
    $dbUsername = "root";
    $dbPwd = "";
    $dbName = "my_database";

    try {
        $pdo = new PDO($dbServer, $dbUsername, $dbPwd);
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    } catch (PDOException $e) {
            echo "Connection failed" . $e->getMessage();
    } 


?>