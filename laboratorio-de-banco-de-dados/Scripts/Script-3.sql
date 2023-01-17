CREATE TABLE alternativas (
	codigo_alternativa SERIAL PRIMARY KEY,
	alternativa VARCHAR(1)
);

INSERT INTO alternativas(alternativa) VALUES ('A');
INSERT INTO alternativas(alternativa) VALUES ('B');
INSERT INTO alternativas(alternativa) VALUES ('C');
INSERT INTO alternativas(alternativa) VALUES ('D');
INSERT INTO alternativas(alternativa) VALUES ('E');
INSERT INTO alternativas(alternativa) VALUES ('F');
INSERT INTO alternativas(alternativa) VALUES ('G');
INSERT INTO alternativas(alternativa) VALUES ('H');
INSERT INTO alternativas(alternativa) VALUES ('I');
INSERT INTO alternativas(alternativa) VALUES ('J');
INSERT INTO alternativas(alternativa) VALUES ('K');

CREATE TABLE estados (
	codigo_estado INTEGER PRIMARY KEY,
	estado VARCHAR(50)
);

INSERT INTO estados(codigo_estado, estado) VALUES (11, 'Rondônia (RO)');
INSERT INTO estados(codigo_estado, estado) VALUES (12, 'Acre (AC)');
INSERT INTO estados(codigo_estado, estado) VALUES (13, 'Amazonas (AM)');
INSERT INTO estados(codigo_estado, estado) VALUES (14, 'Roraima (RR)');
INSERT INTO estados(codigo_estado, estado) VALUES (15, 'Pará (PA)');
INSERT INTO estados(codigo_estado, estado) VALUES (16, 'Amapa (AP)');
INSERT INTO estados(codigo_estado, estado) VALUES (17, 'Tocantins (TO)');
INSERT INTO estados(codigo_estado, estado) VALUES (21, 'Maranhão (MA)');
INSERT INTO estados(codigo_estado, estado) VALUES (22, 'Piauí (PI)');
INSERT INTO estados(codigo_estado, estado) VALUES (23, 'Ceará (CE)');
INSERT INTO estados(codigo_estado, estado) VALUES (24, 'Rio Grande do Norte (RN)');
INSERT INTO estados(codigo_estado, estado) VALUES (25, 'Paraíba (PB)');
INSERT INTO estados(codigo_estado, estado) VALUES (26, 'Pernambuco (PE)');
INSERT INTO estados(codigo_estado, estado) VALUES (27, 'Alagoas (AL)');
INSERT INTO estados(codigo_estado, estado) VALUES (28, 'Sergipe (SE)');
INSERT INTO estados(codigo_estado, estado) VALUES (29, 'Bahia (BA)');
INSERT INTO estados(codigo_estado, estado) VALUES (31, 'Minas gerais (MG)');
INSERT INTO estados(codigo_estado, estado) VALUES (32, 'Espírito Santo (ES)');
INSERT INTO estados(codigo_estado, estado) VALUES (33, 'Rio de Janeiro (RJ)');
INSERT INTO estados(codigo_estado, estado) VALUES (35, 'São Paulo (SP)');
INSERT INTO estados(codigo_estado, estado) VALUES (41, 'Paraná (PR)');
INSERT INTO estados(codigo_estado, estado) VALUES (42, 'Santa Catarina (SC)');
INSERT INTO estados(codigo_estado, estado) VALUES (43, 'Rio Grande do Sul (RS)');
INSERT INTO estados(codigo_estado, estado) VALUES (50, 'Mato Grosso do Sul (MS)');
INSERT INTO estados(codigo_estado, estado) VALUES (51, 'Mato Grosso (MT)');
INSERT INTO estados(codigo_estado, estado) VALUES (52, 'Goiás (GO)');
INSERT INTO estados(codigo_estado, estado) VALUES (53, 'Distrito federal (DF)');
INSERT INTO estados(codigo_estado, estado) VALUES (99, 'Não se aplica');

CREATE TABLE questao1 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao2 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao3 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao4 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao5 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

INSERT INTO questao5 (resposta, cod_curso)
SELECT b.codigo_alternativa, a.co_curso FROM a11b a JOIN alternativas b ON a.qe_i05 = b.alternativa;

CREATE TABLE questao6 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao7 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao8 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

INSERT INTO questao8 (resposta, cod_curso)
SELECT b.codigo_alternativa, a.co_curso FROM a14b a JOIN alternativas b ON a.qe_i08 = b.alternativa;

CREATE TABLE questao9 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao10 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao11 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao12 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao13 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao14 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao15 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao16 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

INSERT INTO questao16 (resposta, cod_curso)
SELECT b.codigo_estado, a.co_curso FROM a22 a JOIN estados b ON a.qe_i16 = b.codigo_estado;

CREATE TABLE questao17 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao18 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao19 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao20 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao21 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao22 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao23 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao24 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao25 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

CREATE TABLE questao26 (
	id SERIAL PRIMARY KEY,
	resposta INTEGER,
	cod_curso INTEGER
);

-- Questão 3.2
--- RESPOSTA = 6,670
SELECT COUNT(a.resposta) FROM questao8 a JOIN alternativas a2 ON a.resposta = a2.codigo_alternativa WHERE a2.alternativa = 'G';

-- Questão 3.3
--- RESPOSTA 78.435
SELECT COUNT(a.resposta) FROM questao5 a JOIN alternativas a2 ON a.resposta = a2.codigo_alternativa WHERE a2.alternativa = 'E';

-- Questão 3.4
--- RESPOSTA 3.646
SELECT COUNT(a.resposta) FROM questao16 a JOIN estados e ON a.resposta = e.codigo_estado WHERE e.codigo_estado = 11;

-- Questão 3.5
SELECT DISTINCT a.cod_curso FROM questao16 a JOIN estados e ON a.resposta = e.codigo_estado WHERE e.codigo_estado = 11;




