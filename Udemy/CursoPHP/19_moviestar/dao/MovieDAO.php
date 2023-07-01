<?php
    require_once("models/Movie.php");
    require_once("models/Message.php");
    require_once("dao/ReviewDAO.php");

    class MovieDAO implements MovieDAOInterface
    {
        private $conn;
        private $url;
        private $message;

        public function __construct(PDO $conn, $url)
        {
            $this->conn = $conn;
            $this->url = $url;
            $this->message = new Message($url);
        }

        public function buildMovie($data)
        {
            $movie = new Movie();

            $movie->id = $data["id"];
            $movie->title = $data["title"];
            $movie->description = $data["description"];
            $movie->image = $data["image"];
            $movie->trailer = $data["trailer"];
            $movie->category = $data["category"];
            $movie->length = $data["length"];
            $movie->users_id = $data["users_id"];

            // recebe as ratings do filme
            $reviewDao = new ReviewDao($this->conn, $this->url);
            $movie->rating = $reviewDao->getRatings($data["id"]);

            return $movie;
        }

        public function findAll()
        {

        }

        public function getLatestMovies()
        {
            $stmt = $this->conn->query("SELECT * FROM movies ORDER BY id DESC");
            $stmt->execute();

            $data = $stmt->fetchAll();

            if($data === false)
            {
                return [];
            }
            
            $movies = [];

            foreach($data as $item)
            {
                $movies[] = $this->buildMovie($item);
            }

            return $movies;
        }

        public function getMoviesByCategory($category)
        {
            $stmt = $this->conn->prepare("SELECT * FROM movies WHERE category = :category ORDER BY id DESC");
            $stmt->bindParam(":category", $category);
            $stmt->execute();

            $data = $stmt->fetchAll();

            if($data === false)
            {
                return [];
            }
            
            $movies = [];

            foreach($data as $item)
            {
                $movies[] = $this->buildMovie($item);
            }

            return $movies;
        }

        public function getMoviesByUserId($id)
        {
            $stmt = $this->conn->prepare("SELECT * FROM movies WHERE users_id = :users_id");
            $stmt->bindParam(":users_id", $id);
            $stmt->execute();

            $data = $stmt->fetchAll();

            if($data === false)
            {
                return [];
            }

            $movies = [];

            foreach($data as $item)
            {
                $movies[] = $this->buildMovie($item);
            }

            return $movies;
        }

        public function findById($id)
        {
            $stmt = $this->conn->prepare("SELECT * FROM movies WHERE id = :id");
            $stmt->bindParam(":id", $id);
            $stmt->execute();

            $data = $stmt->fetch();

            if($data === false)
            {
                return false;
            }

            return $this->buildMovie($data);
        }

        public function findByTitle($title)
        {
            $movies = [];

            $stmt = $this->conn->prepare("SELECT * FROM movies
                                          WHERE title LIKE :title");

            $param = '%'.$title.'%';
            $stmt->bindParam(":title", $param);
            $stmt->execute();

            if($stmt->rowCount() > 0)
            {
                $moviesArray = $stmt->fetchAll();

                foreach($moviesArray as $movie)
                {
                    $movies[] = $this->buildMovie($movie);
                }
            }

            return $movies;
        }

        public function create(Movie $movie)
        {
            $stmt = $this->conn->prepare("INSERT INTO movies (
                title, description, image, trailer, category, length, users_id
                ) VALUES (
                :title, :description, :image, :trailer, :category, :length, :users_id
            )");

            $stmt->bindParam(":title", $movie->title);
            $stmt->bindParam(":description", $movie->description);
            $stmt->bindParam(":image", $movie->image);
            $stmt->bindParam(":trailer", $movie->trailer);
            $stmt->bindParam(":category", $movie->category);
            $stmt->bindParam(":length", $movie->length);
            $stmt->bindParam(":users_id", $movie->users_id);

            $stmt->execute();

            // redireciona para a home
            $this->message->setMessage("Filme adicionado com sucesso!", "success", "index.php");
        }

        public function update(Movie $movie)
        {
            $stmt = $this->conn->prepare("UPDATE movies SET 
                title = :title,
                description = :description,
                image = :image,
                trailer = :trailer,
                category = :category,
                length = :length
                WHERE id = :id
            ");

            $stmt->bindParam(":title", $movie->title);
            $stmt->bindParam(":description", $movie->description);
            $stmt->bindParam(":image", $movie->image);
            $stmt->bindParam(":trailer", $movie->trailer);
            $stmt->bindParam(":category", $movie->category);
            $stmt->bindParam(":length", $movie->length);
            $stmt->bindParam(":id", $movie->id);

            $stmt->execute();

            // redireciona para a dashboard
            $this->message->setMessage("Filme atualizado com sucesso!", "success", "dashboard.php");
        }

        public function destroy($id)
        {
            $stmt = $this->conn->prepare("DELETE FROM movies WHERE id = :id");
            $stmt->bindParam(":id", $id);
            $stmt->execute();

            $this->message->setMessage("Filme removido com sucesso!", "success", "dashboard.php");
        }
    }
?>
