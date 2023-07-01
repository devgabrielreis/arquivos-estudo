-- cria um banco de dados chamado "teste"
CREATE DATABASE teste;

-- destroi um banco de dados chamado "teste" (vai pra lixeira?)
DROP DATABASE teste;

-- seleciona o banco de dados a ser usado
USE nome;

-- criar tabelas
CREATE TABLE nomedatabela (
	coluna1 tipodedado,
	coluna2 tipodedado
);

-- constraints
-- são definidas na criacao da coluna de uma tabela
-- nomecoluna TIPODEDADO CONSTRAINTS
-- tipos:
NOT NULL -- nao permite que o dado adicionado esteja vazio
UNIQUE -- garante que todos os valores de uma coluna sejam unicos
PRIMARY KEY -- ex: id INT UNSIGNED AUTO_INCREMENT PRIMARY KEY;

-- comando para garantir que o banco de dados nao aceitara um valor nulo
SET @@GLOBAL.SQL_MODE = 'STRICT_ALL_TABLES';

-- adicionar colunas a uma tabela ja existente
ALTER nometebela
ADD nomecoluna INT;

-- remover coluna de tabela
ALTER TABLE nometabela
DROP nomecoluna;

-- modificar tipo da coluna
ALTER TABLE nometabela
MODIFY COLUMN nomecoluna VARCHAR(500);

-- destruir tabelas
DROP TABLE nomedatabela;

-- principais tipos de dados
VARCHAR; -- texto de 0 a 65535 caracteres
VARCHAR(x); --na criacao de tabelas, o limite de caracteres nessa coluna sera "x";
TEXT; -- texto com no maximo 65535 bytes
INT; -- numeros inteiros
BIGINT; -- numeros inteiros com mair proporcao que o INT
DATE; -- data no formato YYYY-MM-DD

-- inserir dados
INSERT INTO nometabela (coluna1, coluna2) VALUES (valor1, valor2);

-- selecionar dados
SELECT * FROM nomedatabela;

-- filtrar seleção
SELECT * FROM nomedatabela WHERE condição;

-- condicionais de WHERE
=
!=
<
>
<=
>=
AND
OR
NOT

-- ordenar resultados
SELECT nome FROM pessoas ORDER BY nome DESC; descendente
SELECT nome FROM pessoas ORDER BY nome ASC; crescente

-- atualizar dados
UPDATE nometabela SET nomecoluna = valor, nomecoluna2 = valor2 WHERE condicao;

-- deletar dados
DELETE FROM nometabela WHERE condição;

-- criar usuario
CREATE USER 'usuario'@'localhost' IDENTIFIED BY 'senha';
GRANT ALL PRIVILEGES ON *.* TO 'usuario'@'localhost'; -- *.* significa todos os bancos e todas as tabelas
FLUSH PRIVILEGES;

-- ver usuarios no mysql
SELECT * FROM mysql.user;
