CREATE SCHEMA prova_q1;
CREATE TABLE prova_q1.q1 (
	id_cliente SERIAL PRIMARY KEY,
	nome VARCHAR NOT NULL,
	valor INT NOT NULL,
	pacote VARCHAR NOT NULL
);

INSERT INTO prova_q1.q1(nome, valor, pacote) VALUES ('João', 80, 'Personalizado II');
INSERT INTO prova_q1.q1(nome, valor, pacote) VALUES ('João', 50, 'Personalizado I');
INSERT INTO prova_q1.q1(nome, valor, pacote) VALUES ('João', 00, 'Personalizado BACEN');
INSERT INTO prova_q1.q1(nome, valor, pacote) VALUES ('João', 50, 'Personalizado I');
INSERT INTO prova_q1.q1(nome, valor, pacote) VALUES ('João', 50, 'Personalizado I');
INSERT INTO prova_q1.q1(nome, valor, pacote) VALUES ('João', 80, 'Personalizado II');


SELECT sum(prova_q1.q1.valor) FROM prova_q1. q1 GROUP BY pacote ORDER BY 1 DESC;

