CREATE DATABASE prova_ivo_vieira_20221;

--drop table alunos ,aulas ,instrutores ,provas ,status_pagamento ,tipo_carteira , tipo_pagamento , tipo_servico ,tipo_veiculo , valores , veiculos, veiculos_em_uso;

-- AUXILIAR 1
--- 1 A
--- 2 B
--- 3 AB
CREATE TABLE tipo_carteira (
	id_tipo SERIAL PRIMARY KEY,
	tipo VARCHAR
);

-- PRINCIPAL 1
CREATE TABLE alunos (
	id_aluno SERIAL PRIMARY KEY,
	nome VARCHAR,
	cpf INT,
	idade INT,
	fk_id_tipo_carteira INT,
	
	CONSTRAINT alunos_fk_id_tipo_carteira_fkey FOREIGN KEY (fk_id_tipo_carteira) REFERENCES public.tipo_carteira(id_tipo)
);

-- PRINCIPAL 2
CREATE TABLE instrutores (
	id_instrutor SERIAL PRIMARY KEY,
	nome VARCHAR,
	cpf INT,
	fk_id_tipo_carteira INT,
	
	CONSTRAINT instrutores_fk_id_tipo_carteira_fkey FOREIGN KEY (fk_id_tipo_carteira) REFERENCES public.tipo_carteira(id_tipo)

);

-- AUXILIAR 2
-- 1 Moto
-- 2 Carro
CREATE TABLE tipo_veiculo (
	id_tipo SERIAL PRIMARY KEY,
	tipo VARCHAR
);

-- PRINCIPAL 3
CREATE TABLE veiculos (
	id_veiculo SERIAL PRIMARY KEY,
	fk_id_tipo_veiculo INT,
	cor VARCHAR,
	modelo VARCHAR,
	marca VARCHAR,
	
	CONSTRAINT veiculos_fk_id_tipo_veiculo_fkey FOREIGN KEY (fk_id_tipo_veiculo) REFERENCES public.tipo_veiculo(id_tipo)

);

-- AUXILIAR 3
--- 1 Aula Teorica
--- 2 Aula Prática
--- 3 Prova Teorica
--- 4 Prova Prática
CREATE TABLE tipo_servico (
	id_tipo SERIAL PRIMARY KEY,
	tipo VARCHAR
);

-- PRINCIPAL 4
CREATE TABLE aulas (
	id_aula SERIAL PRIMARY KEY,
	fk_id_aluno INT,
	fk_id_tipo_servico INT,
	fk_id_veiculo INT,
	fk_id_instrutor INT,
	
	CONSTRAINT aulas_fk_id_aluno_fkey FOREIGN KEY (fk_id_aluno) REFERENCES public.alunos(id_aluno),
	CONSTRAINT aulas_fk_id_instrutor_fkey FOREIGN KEY (fk_id_instrutor) REFERENCES public.instrutores(id_instrutor),
	CONSTRAINT aulas_fk_id_tipo_servico_fkey FOREIGN KEY (fk_id_tipo_servico) REFERENCES public.tipo_servico(id_tipo),
	CONSTRAINT aulas_fk_id_veiculo_fkey FOREIGN KEY (fk_id_veiculo) REFERENCES public.veiculos(id_veiculo)
);

-- PRINCIPAL 5
CREATE TABLE provas (
	id_prova SERIAL PRIMARY KEY,
	fk_id_aluno INT,
	fk_id_tipo_servico INT,
	fk_id_veiculo INT,
	fk_id_instrutor INT,
	nota INT,
	
	CONSTRAINT provas_fk_id_aluno_fkey FOREIGN KEY (fk_id_aluno) REFERENCES public.alunos(id_aluno),
	CONSTRAINT provas_fk_id_instrutor_fkey FOREIGN KEY (fk_id_instrutor) REFERENCES public.instrutores(id_instrutor),
	CONSTRAINT provas_fk_id_tipo_servico_fkey FOREIGN KEY (fk_id_tipo_servico) REFERENCES public.tipo_servico(id_tipo),
	CONSTRAINT provas_fk_id_veiculo_fkey FOREIGN KEY (fk_id_veiculo) REFERENCES public.veiculos(id_veiculo)
);

-- AUXILIAR 4
--- 1 Boleto
--- 2 Dinheiro
--- 3 Cartão
CREATE TABLE tipo_pagamento (
	id_tipo SERIAL PRIMARY KEY,
	tipo VARCHAR NOT NULL,
	numero_cartao INT,
	vencimento DATE
);

-- AUXILIAR 5
--- 1 Adimplente
--- 2 Inadimplente
CREATE TABLE status_pagamento (
	id_status SERIAL PRIMARY KEY,
	status VARCHAR
);

-- PRINCIPAL 6
CREATE TABLE valores (
	id_pagamento SERIAL PRIMARY KEY,
	fk_id_aluno INT,
	fk_id_tipo_pagamento INT,
	fk_id_tipo_servico INT,
	fk_id_status INT,
	vencimento DATE,
	
	CONSTRAINT valores_fk_id_aluno_fkey FOREIGN KEY (fk_id_aluno) REFERENCES public.alunos(id_aluno),
	CONSTRAINT valores_fk_id_tipo_pagamento_fkey FOREIGN KEY (fk_id_tipo_pagamento) REFERENCES public.tipo_pagamento(id_tipo),
	CONSTRAINT valores_fk_id_tipo_servico_fkey FOREIGN KEY (fk_id_tipo_servico) REFERENCES public.tipo_servico(id_tipo),
	CONSTRAINT valores_fk_id_status_fkey FOREIGN KEY (fk_id_status) REFERENCES public.status_pagamento(id_status)
);

-- AUXILIAR 6
CREATE TABLE veiculos_em_uso (
	fk_id_aluno INT,
	fk_id_veiculo INT,
	comeca DATE,
	termina DATE
);
