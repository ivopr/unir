drop table atividade2.coordenadores;

-- DROPANDO COLUNAS NÃO UTILIZADAS
ALTER TABLE atividade2.alunos
	DROP COLUMN nivel_ensino;

ALTER TABLE atividade2.alunos
	DROP COLUMN convenio_academico;




-- CRIANDO TABELA DE COORDENADORES
SELECT DISTINCT a.id_coordenador, a.coordenador INTO atividade2.coordenadores 
FROM atividade2.alunos a
WHERE a.id_coordenador IS NOT NULL;

-- DROPANDO COLUNA DE NOME DE COORDENADOR
ALTER TABLE atividade2.alunos
	DROP COLUMN coordenador;




-- CRIANDO TABELA DE GRAU ACADEMICO
SELECT DISTINCT a.grau_academico INTO atividade2.grau_academico
FROM atividade2.alunos a 
WHERE a.grau_academico IS NOT NULL;

-- DEFININDO CHAVE PRIMÁRIA DA NOVA TABELA DE GRAU ACADEMICO
ALTER TABLE atividade2.grau_academico
	ADD COLUMN id_grau_academico SERIAL NOT NULL PRIMARY KEY;

-- ADICIONANDO UMA COLUNA DE ID PARA REFERENCIAR UM GRAU ACADEMICO
ALTER TABLE atividade2.alunos
	ADD COLUMN id_grau_academico int;

-- REFERENCIANDO O GRAU ACADEMICO
UPDATE atividade2.alunos a
SET id_grau_academico = 
	(SELECT ga.id_grau_academico 
	 FROM atividade2.grau_academico ga 
	 WHERE ga.grau_academico = a.grau_academico);

-- REMOVENDO ANTIGA COLUNA DE GRAU ACADEMICO
ALTER TABLE atividade2.alunos 
	DROP COLUMN grau_academico;
	
-- CRIANDO TABELA DE NOMES DE CURSO
SELECT DISTINCT a.nome INTO atividade2.nome_curso 
FROM atividade2.alunos a
WHERE a.nome IS NOT NULL;

-- DEFININDO CHAVE PRIMÁRIA DA NOVA TABELA DE NOMES DE CURSO
ALTER TABLE atividade2.nome_curso
	ADD COLUMN id_nome_curso SERIAL NOT NULL PRIMARY KEY;

-- ADICIONANDO UMA COLUNA DE ID PARA REFERENCIAR UM GRAU ACADEMICO
ALTER TABLE atividade2.alunos
	ADD COLUMN id_nome_curso int;

-- REFERENCIANDO O NOME DO CURSO
UPDATE atividade2.alunos a
SET id_nome_curso = 
	(SELECT nc.id_nome_curso 
	 FROM atividade2.nome_curso nc 
	 WHERE nc.nome = a.nome);

-- REMOVENDO COLUNA NÃO UTILIZADA
ALTER TABLE atividade2.alunos
	DROP COLUMN nome;




-- CRIANDO TABELA DE SITUAÇÃO
SELECT DISTINCT a.situacao_curso INTO atividade2.situacao 
FROM atividade2.alunos a
WHERE a.situacao_curso IS NOT NULL;

-- DEFININDO CHAVE PRIMÁRIA DA NOVA TABELA DE SITUACAO DE CURSO
ALTER TABLE atividade2.situacao
	ADD COLUMN id_situacao SERIAL NOT NULL PRIMARY KEY;

-- ADICIONANDO UMA COLUNA DE ID PARA REFERENCIAR UMA SITUACAO DE CURSO
ALTER TABLE atividade2.alunos
	ADD COLUMN id_situacao int;

-- REFERENCIANDO O SITUACAO DO CURSO
UPDATE atividade2.alunos a
SET id_situacao = 
	(SELECT s.id_situacao 
	 FROM atividade2.situacao s 
	 WHERE s.situacao_curso = a.situacao_curso);

-- REMOVENDO COLUNA NÃO UTILIZADA
ALTER TABLE atividade2.alunos
	DROP COLUMN situacao_curso;




-- CRIANDO TABELA DE SITUAÇÃO
SELECT DISTINCT a.modalidade_educacao INTO atividade2.modalidades 
FROM atividade2.alunos a
WHERE a.modalidade_educacao IS NOT NULL;

-- DEFININDO CHAVE PRIMÁRIA DA NOVA TABELA DE NOMES DE CURSO
ALTER TABLE atividade2.modalidades
	ADD COLUMN id_modalidade SERIAL NOT NULL PRIMARY KEY;

-- ADICIONANDO UMA COLUNA DE ID PARA REFERENCIAR UM GRAU ACADEMICO
ALTER TABLE atividade2.alunos
	ADD COLUMN id_modalidade int;

-- REFERENCIANDO O NOME DO CURSO
UPDATE atividade2.alunos a
SET id_modalidade = 
	(SELECT m.id_modalidade 
	 FROM atividade2.modalidades m 
	 WHERE m.modalidade_educacao = a.modalidade_educacao);

-- REMOVENDO COLUNA NÃO UTILIZADA
ALTER TABLE atividade2.alunos
	DROP COLUMN modalidade_educacao;





-- CRIANDO TABELA DE SITUAÇÃO
SELECT DISTINCT a.area_conhecimento INTO atividade2.area_conhecimento 
FROM atividade2.alunos a
WHERE a.area_conhecimento IS NOT NULL;

-- DEFININDO CHAVE PRIMÁRIA DA NOVA TABELA DE NOMES DE CURSO
ALTER TABLE atividade2.area_conhecimento
	ADD COLUMN id_area_conhecimento SERIAL NOT NULL PRIMARY KEY;

-- ADICIONANDO UMA COLUNA DE ID PARA REFERENCIAR UM GRAU ACADEMICO
ALTER TABLE atividade2.alunos
	ADD COLUMN id_area_conhecimento int;

-- REFERENCIANDO O NOME DO CURSO
UPDATE atividade2.alunos a
SET id_area_conhecimento = 
	(SELECT m.id_area_conhecimento 
	 FROM atividade2.area_conhecimento m 
	 WHERE m.area_conhecimento = a.area_conhecimento);

-- REMOVENDO COLUNA NÃO UTILIZADA
ALTER TABLE atividade2.alunos
	DROP COLUMN area_conhecimento;



-- CRIANDO TABELA DE SITUAÇÃO
SELECT DISTINCT a.tipo_oferta INTO atividade2.oferta 
FROM atividade2.alunos a
WHERE a.tipo_oferta IS NOT NULL;

-- DEFININDO CHAVE PRIMÁRIA DA NOVA TABELA DE NOMES DE CURSO
ALTER TABLE atividade2.oferta
	ADD COLUMN id_oferta SERIAL NOT NULL PRIMARY KEY;

-- ADICIONANDO UMA COLUNA DE ID PARA REFERENCIAR UM GRAU ACADEMICO
ALTER TABLE atividade2.alunos
	ADD COLUMN id_oferta int;

-- REFERENCIANDO O NOME DO CURSO
UPDATE atividade2.alunos a
SET id_oferta = 
	(SELECT m.id_oferta 
	 FROM atividade2.oferta m 
	 WHERE m.tipo_oferta = a.tipo_oferta);

-- REMOVENDO COLUNA NÃO UTILIZADA
ALTER TABLE atividade2.alunos
	DROP COLUMN tipo_oferta;




-- CRIANDO TABELA DE SITUAÇÃO
SELECT DISTINCT a.turno INTO atividade2.turno 
FROM atividade2.alunos a
WHERE a.turno IS NOT NULL;

-- DEFININDO CHAVE PRIMÁRIA DA NOVA TABELA DE NOMES DE CURSO
ALTER TABLE atividade2.turno
	ADD COLUMN id_turno SERIAL NOT NULL PRIMARY KEY;

-- ADICIONANDO UMA COLUNA DE ID PARA REFERENCIAR UM GRAU ACADEMICO
ALTER TABLE atividade2.alunos
	ADD COLUMN id_turno int;

-- REFERENCIANDO O NOME DO CURSO
UPDATE atividade2.alunos a
SET id_turno = 
	(SELECT m.id_turno 
	 FROM atividade2.turno m 
	 WHERE m.turno = a.turno);

-- REMOVENDO COLUNA NÃO UTILIZADA
ALTER TABLE atividade2.alunos
	DROP COLUMN turno;



-- CRIANDO TABELA DE SITUAÇÃO
SELECT DISTINCT a.tipo_ciclo_formacao INTO atividade2.ciclo 
FROM atividade2.alunos a
WHERE a.tipo_ciclo_formacao IS NOT NULL;

-- DEFININDO CHAVE PRIMÁRIA DA NOVA TABELA DE NOMES DE CURSO
ALTER TABLE atividade2.ciclo
	ADD COLUMN id_ciclo SERIAL NOT NULL PRIMARY KEY;

-- ADICIONANDO UMA COLUNA DE ID PARA REFERENCIAR UM GRAU ACADEMICO
ALTER TABLE atividade2.alunos
	ADD COLUMN id_ciclo int;

-- REFERENCIANDO O NOME DO CURSO
UPDATE atividade2.alunos a
SET id_ciclo = 
	(SELECT m.id_ciclo 
	 FROM atividade2.ciclo m 
	 WHERE m.tipo_ciclo_formacao = a.tipo_ciclo_formacao);

-- REMOVENDO COLUNA NÃO UTILIZADA
ALTER TABLE atividade2.alunos
	DROP COLUMN tipo_ciclo_formacao;


-- CRIANDO TABELA DE SITUAÇÃO
SELECT DISTINCT a.municipio INTO atividade2.municipio 
FROM atividade2.alunos a
WHERE a.municipio  IS NOT NULL;

-- DEFININDO CHAVE PRIMÁRIA DA NOVA TABELA DE NOMES DE CURSO
ALTER TABLE atividade2.municipio
	ADD COLUMN id_municipio SERIAL NOT NULL PRIMARY KEY;

-- ADICIONANDO UMA COLUNA DE ID PARA REFERENCIAR UM GRAU ACADEMICO
ALTER TABLE atividade2.alunos
	ADD COLUMN id_municipio int;

-- REFERENCIANDO O NOME DO CURSO
UPDATE atividade2.alunos a
SET id_municipio = 
	(SELECT m.id_municipio 
	 FROM atividade2.municipio m 
	 WHERE m.modalidade_educacao = a.modalidade_educacao);

-- REMOVENDO COLUNA NÃO UTILIZADA
ALTER TABLE atividade2.alunos
	DROP COLUMN modalidade_educacao;


