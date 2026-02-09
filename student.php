<?php

    $conn = mysqli_connect("localhost", "root", "", "my_database");

    if (!$conn) {
        die("Connection failed");
    }

    /*$dbs = "my_database";

    $sql = "CREATE DATABASE $dbs";

    if (mysqli_query($conn, $sql)) {
        echo "Database Created";
    } else {
        echo "Failed to create database";
    }*/

    $table = "CREATE TABLE student(ID INT AUTO_INCREMENT PRIMARY KEY,
                                    NAME VARCHAR(100), EMAIL VARCHAR(100) UNIQUE, AGE INT, COURSE VARCHAR(100))";

    if (mysqli_query($conn, $table)) {
        echo "<br>Table Created";
    } else {
        echo "<br>Failed to create table";
    }

    $insert = "INSERT INTO student (ID, NAME, EMAIL, AGE, COURSE)
           VALUES (1, 'SHAKTI', 'shaktisherpa356@gmail.com', 20, 'BCA')";

    if (mysqli_query($conn, $insert)) {
        echo"<br>1 is inserted";
    } else {
        echo "<br>Failed to insert 1";
    }

    $insert2 = "INSERT INTO student (ID, NAME, EMAIL, AGE, COURSE)
           VALUES (2, 'Salaaka', 'salaaka21@gmail.com', 21, 'BCA')";

    if (mysqli_query($conn, $insert2)) {
        echo"<br>2 is inserted";
    } else {
        echo "<br>Failed to insert 2";
    }

    $insert3 = "INSERT INTO student (ID, NAME, EMAIL, AGE, COURSE)
           VALUES (3, 'Shadow', 'shadowshakti321@gmail.com', 22,' BCA')";

    if (mysqli_query($conn, $insert3)) {
        echo"<br>3 is inserted";
    } else {
        echo "<br>Failed to insert 3";
    }

    $insert4 = "INSERT INTO student (ID, NAME, EMAIL, AGE, COURSE)
           VALUES (4, 'Suman', 'sumangauli456@gmail.com', 25, 'BCA')";

    if (mysqli_query($conn, $insert4)) {
        echo"<br>4 is inserted";
    } else {
        echo "<br>Failed to insert 4";
    }

    $insert5 = "INSERT INTO student (ID, NAME, EMAIL, AGE, COURSE)
           VALUES (5, 'Anjan', 'anjangrg56@gmail.com', 19, 'BCA')";

    if (mysqli_query($conn, $insert5)) {
        echo"<br>5 is inserted";
    } else {
        echo "<br>Failed to insert 5";
    }

    mysqli_close($conn);
?>