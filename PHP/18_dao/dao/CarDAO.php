<?php
    include_once("models/Car.php");

    class CarDAO implements CarDAOInterface
    {
        private $conn;

        public function __construct(PDO $conn)
        {
            $this->conn = $conn;
        }

        public function findAll()
        {
            $carsArray = [];
            
            $stmt = $this->conn->query("SELECT * FROM cars");

            $data = $stmt->fetchAll();

            foreach($data as $carData)
            {
                $car = new Car();

                $car->setId($carData["id"]);
                $car->setBrand($carData["brand"]);
                $car->setKm($carData["km"]);
                $car->setColor($carData["color"]);

                $carsArray[] = $car;
            }

            return $carsArray;
        }

        public function create(Car $car)
        {
            $stmt = $this->conn->prepare("INSERT INTO cars (brand, km, color) VALUES (:brand, :km, :color)");
            $stmt->bindParam(":brand", $car->getBrand());
            $stmt->bindParam(":km", $car->getKm());
            $stmt->bindParam(":color", $car->getColor());
            $stmt->execute();
        }
    }
?>
