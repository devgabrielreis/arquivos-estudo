<?php
    class Classe
    {
        public $propriedade = "propriedade da classe";
        public const CONSTANTE = 42;

        // visibilidade
        public $var1;    // pode ser acessada por qualquer um
        protected $var2; // pode ser acessada pela classe de origem e as que recebem a mesma herança
        private $var3;   // pode ser acessada apenas pela propria classe

        // funcoes tambem podem ter visibilidade
        public function metodo()
        {
            echo "estou dentro da classe<br>";
            echo "eu tenho uma constante com o valor" . self::CONSTANTE . "<br>";
        }

        public function setPropriedade($novoValor)
        {
            $this->propriedade = $novoValor;

            echo "minha propriedade agora é $this->propriedade <br>";
        }
    }

    $object = new Classe;
    $object->metodo();

    echo $object->propriedade . $object::CONSTANTE . "<br>";

    $object->setPropriedade(30);



    // herança

    class Pessoa
    {
        public $nome;

        public function falar()
        {
            echo "oi<br>";
        }
    }

    class Programador extends Pessoa
    {
        public function trabalhar()
        {
            echo "$this->nome esta trabalhando<br>";
        }

        public function falar()
        {
            echo "como centralizar uma div?<br>";
        }
    }

    $daniel = new Programador();
    $daniel->nome = "daniel";
    $daniel->falar();
    $daniel->trabalhar();

    var_dump($daniel instanceof Pessoa);
    var_dump($daniel instanceof Programador);
    echo "<br>";

    // interface
    // https://www.w3schools.com/php/php_oop_interfaces.asp

    interface Animal
    {
        public const resposta = 42;
        public function respirar();
        public function dormir();
        public function comer();
    }

    class Humano implements Animal
    {
        public function respirar()
        {
            echo "inspira... espira...<br>";
        }

        public function dormir()
        {
            echo "zzz<br>";
        }

        public function comer()
        {
            echo "buchin cheio<br>";
            self::resposta;
        }
    }

    $h = new Humano;
    $h->respirar();
    $h->comer();
    $h->dormir();

    // trait
    // https://www.w3schools.com/php/php_oop_traits.asp
    trait Porta
    {
        // classes podem ter type hint
        public bool $portaAberta = false;
        
        public function abrirPorta()
        {
            if($this->portaAberta)
            {
                echo "a porta ja estava aberta<br>";
                return;
            }

            echo "a porta foi aberta<br>";
            $this->portaAberta = true;
        }

        public function fecharPorta()
        {
            if(!$this->portaAberta)
            {
                echo "a porta ja estava fechada<br>";
                return;
            }

            echo "a porta foi fechada<br>";
            $this->portaAberta = false;
        }
    }

    trait Janela
    {
        // classes podem ter type hint
        public bool $janelaAberta = false;
        
        public function abrirJanela()
        {
            if($this->janelaAberta)
            {
                echo "a janela ja estava aberta<br>";
                return;
            }

            echo "a janela foi aberta<br>";
            $this->janelaAberta = true;
        }

        public function fecharJanela()
        {
            if(!$this->janelaAberta)
            {
                echo "a janela ja estava fechada<br>";
                return;
            }

            echo "a janela foi fechada<br>";
            $this->janelaAberta = false;
        }
    }

    class Predio
    {
        use Porta;
        use Janela;
    }

    $escritorio = new Predio;
    $escritorio->abrirJanela();
    $escritorio->abrirJanela();
    $escritorio->abrirPorta();
    $escritorio->abrirPorta();
    $escritorio->fecharJanela();
    $escritorio->fecharPorta();

    // classe abstratas
    // https://www.w3schools.com/php/php_oop_classes_abstract.asp
    // ela nao pode ser instanciada e 
    // deve ser herdada por outra classe
    abstract class ParentClass {
        abstract public function someMethod1();
        abstract public function someMethod2($name, $color);
        abstract public function someMethod3() : string;
    }

    // construtor
    class Cachorro
    {
        public $nome;
        public $raca;

        public function __construct($nome, $raca)
        {
            $this->nome = $nome;
            $this->raca = $raca;
        }
    }

    $bob = new Cachorro("bob", "labrador");
    echo "O $bob->nome é da raça $bob->raca<br>";

    // classe anonima
    // nao possuem nomes e sao declaradas na criacao da variavel
    $var1 = new class(){public $nome = "Ana";};
    echo $var1->nome . "<br>";

    // funcoes de classe
    var_dump(class_exists("Cachorro"));
    echo "<br>";
    var_dump(get_class_methods("Cachorro"));
    echo "<br>";
    var_dump(get_class_vars("Cachorro"));
    echo "<br>";

    // funcoes de objetos
    var_dump(is_object($bob));
    echo "<br>";
    var_dump(get_class($bob));
    echo "<br>";
    var_dump(method_exists($bob, "__construct"));
    echo "<br>";
?>
