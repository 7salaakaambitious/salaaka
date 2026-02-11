<?php


if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST["name"];
    $email = $_POST["email"];
    $address = $_POST["address"];

    try {
        require_once "db.php";

        $query = "INSERT INTO users (name, email, address) VALUES
        (?,?,?);";

        $stmt = $pdo->prepare($query);

        $stmt->execute([$name, $email, $address]);

        $pdo = null;
        $stmt = null;

        header("Location: ../html/index.html");

        die();
    } catch (PDOException $e) {
        die("Query failed: " . $e->getMessage());
    }
} else {
    header("Location: ../html/index.html");
}
?>