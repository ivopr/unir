-- ATIVIDADE 1

---- QUESTÃO 1
------ SQL UTILIZADO PARA CRIAÇÃO DE TABELAS
CREATE SCHEMA atividade1;

CREATE TABLE atividade1.cliente (
	cid SERIAL PRIMARY KEY, -- CRIA cid COMO SERIAL E CHAVE PRIMÁRIA
	cnome VARCHAR(50), -- CRIA cnome COMO VARYING DE ATÉ 50 CARACTERES
	uf VARCHAR(2) -- CRIA uf COMO VARYING DE ATÉ 2 CARACTERES
);

CREATE TABLE atividade1.carro (
	carid SERIAL PRIMARY KEY, -- CRIA carid COMO SERIAL E CHAVE PRIMÁRIA
	carnome VARCHAR(50), -- CRIA carnome COMO VARYING DE ATÉ 50 CARACTERES
	carcategoria VARCHAR(50), -- CRIA carcategoria COMO VARYING DE ATÉ 50 CARACTERES
	carplaca VARCHAR(50), -- CRIA carplaca COMO VARYING DE ATÉ 50 CARACTERES
	carano INTEGER -- CRIA carano COMO INTEIRO
);

CREATE TABLE atividade1.aluguel (
	aid SERIAL PRIMARY KEY, -- CRIA aid COMO SERIAL E CHAVE PRIMÁRIA
	cid INTEGER REFERENCES atividade1.cliente (cid), -- CRIA cid COMO INTEIRO E O RELACIONA COM cid NA TABELA cliente
	adatainicio DATE, -- CRIA adatainicio COMO DATA
	adatafim DATE, -- CRIA adatafim COMO DATA
	apreco INTEGER -- CRIA apreco COMO INTEIRO, O VALOR ESTÁ EM CENTAVOS
);

CREATE TABLE atividade1.aluguel_carro (
	aid INTEGER REFERENCES atividade1.aluguel (aid), -- CRIA aid COMO INTEIRO E RELACIONA COM aid NA TABELA aluguel
	carid INTEGER REFERENCES atividade1.carro (carid) -- CRIA carid COMO INTEIRO E RELACIONA COM carid NA TABELA carro
);

-- INSERIR DADOS
---- TABELA CLIENTE -- COMO cid É SERIAL, NÃO É NECESSÁRIO PREENCHÊ-LO
INSERT INTO atividade1.cliente (cnome, uf) VALUES ('Murilo', 'RO');
INSERT INTO atividade1.cliente (cnome, uf) VALUES ('Ivo', 'PR');
INSERT INTO atividade1.cliente (cnome, uf) VALUES ('Judeu', 'RJ');
---- TABELA CARRO -- COMO carid É SERIAL, NÃO É NECESSÁRIO PREENCHÊ-LO
INSERT INTO atividade1.carro (carnome, carcategoria, carplaca, carano) VALUES ('RAM 2500 Laramie', 'Picape', 'ABC-1234', 2020);
INSERT INTO atividade1.carro (carnome, carcategoria, carplaca, carano) VALUES ('Ford Ka', 'Hatch', 'BCD-2345', 2022);
INSERT INTO atividade1.carro (carnome, carcategoria, carplaca, carano) VALUES ('Audi A3 Sedan S Line Limited 1.4 TFSI', 'Sedan', 'CDE-3456', 2023);
---- TABELA ALUGUEL -- COMO aid É SERIAL, NÃO É NECESSÁRIO PREENCHÊ-LO
INSERT INTO atividade1.aluguel (cid, adatainicio, adatafim, apreco) VALUES (1, NOW(), NOW() + INTERVAL '3 days', 100000);
INSERT INTO atividade1.aluguel (cid, adatainicio, adatafim, apreco) VALUES (2, NOW(), NOW() + INTERVAL '30 days', 500000);
INSERT INTO atividade1.aluguel (cid, adatainicio, adatafim, apreco) VALUES (3, NOW(), NOW() + INTERVAL '10 days', 1000000);
---- TABEL ALUGUEL_CARRO
INSERT INTO atividade1.aluguel_carro (aid, carid) VALUES (1, 1);
INSERT INTO atividade1.aluguel_carro (aid, carid) VALUES (2, 2);
INSERT INTO atividade1.aluguel_carro (aid, carid) VALUES (3, 3);

-- CONSULTAS
---- CONSULTA 1
SELECT carnome 
	FROM atividade1.carro c JOIN atividade1.aluguel_carro ac ON c.carid = ac.carid 
	WHERE c.carcategoria = 'SUV';
---- CONSULTA 2
SELECT carplaca, carano 
	FROM (atividade1.carro c JOIN atividade1.aluguel_carro ac ON c.carid = ac.carid), (atividade1.cliente c4 JOIN atividade1.aluguel a ON c4.cid = a.cid)
	WHERE c4.uf = 'RJ';
---- CONSULTA 3
SELECT cnome 
	FROM atividade1.cliente c 
	WHERE c.uf = 'RJ';
---- CONSULTA 4
SELECT carplaca, cnome 
	FROM (atividade1.carro c2 JOIN atividade1.aluguel_carro ac ON c2.carid = ac.carid), (atividade1.cliente c3 JOIN atividade1.aluguel a ON c3.cid = a.cid)
	WHERE c2.carcategoria = 'Sedan' AND c2.carano = 2020 AND c3.cnome != 'Daniel';
---- CONSULTA 5
SELECT cnome, cid 
	FROM atividade1.cliente c 
	WHERE c.uf = 'MG';

-- QUESTÃO 2 
---- As colunas na Projeção da Consulta 2 são: carplaca e carano

-- QUESTÃO 3
---- A seleção da Consulta 5 é se a UF do cliente for Minas Gerais (MG)



