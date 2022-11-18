-- INSERT TIPO_CARTEIRA
INSERT INTO tipo_carteira(tipo) VALUES ('A');
INSERT INTO tipo_carteira(tipo) VALUES ('B');
INSERT INTO tipo_carteira(tipo) VALUES ('AB');

-- INSERT ALUNO
INSERT INTO alunos(nome, cpf, fk_id_tipo_carteira, idade) VALUES ('ivo', 123, 2, 22);
INSERT INTO alunos(nome, cpf, fk_id_tipo_carteira, idade) VALUES ('murilo', 234, 1, 15);
INSERT INTO alunos(nome, cpf, fk_id_tipo_carteira, idade) VALUES ('joão', 345, 3, 34);

-- INSERT INSTRUTOR
INSERT INTO instrutores(nome, cpf, fk_id_tipo_carteira) VALUES ('Jacinto', 456, 1);
INSERT INTO instrutores(nome, cpf, fk_id_tipo_carteira) VALUES ('Abílio', 567, 2);
INSERT INTO instrutores(nome, cpf, fk_id_tipo_carteira) VALUES ('Orismar', 678, 3);

-- INSERT TIPO VEICULO
INSERT INTO tipo_veiculo(tipo) VALUES ('Moto');
INSERT INTO tipo_veiculo(tipo) VALUES ('Carro');

-- INSERT VEICULO
INSERT INTO veiculos(fk_id_tipo_veiculo, cor, modelo, marca) VALUES (2, 'Prata', 'Spacefox', 'Volkswagen');
INSERT INTO veiculos(fk_id_tipo_veiculo, cor, modelo, marca) VALUES (2, 'Vermelho', 'Kwid', 'Renault');
INSERT INTO veiculos(fk_id_tipo_veiculo, cor, modelo, marca) VALUES (1, 'Azul', 'POP 100', 'Honda');
INSERT INTO veiculos(fk_id_tipo_veiculo, cor, modelo, marca) VALUES (1, 'Verde', 'Titan 150', 'Honda');

-- INSERT TIPO SERVICO
INSERT INTO tipo_servico(tipo) VALUES ('Aula Teórica');
INSERT INTO tipo_servico(tipo) VALUES ('Aula Prática');
INSERT INTO tipo_servico(tipo) VALUES ('Prova Teórica');
INSERT INTO tipo_servico(tipo) VALUES ('Prova Prática');

-- INSERT AULAS
INSERT INTO aulas(fk_id_aluno, fk_id_tipo_servico, fk_id_veiculo, fk_id_instrutor) VALUES (1, 1, NULL, NULL);
INSERT INTO aulas(fk_id_aluno, fk_id_tipo_servico, fk_id_veiculo, fk_id_instrutor) VALUES (2, 2, 3, 1);
INSERT INTO aulas(fk_id_aluno, fk_id_tipo_servico, fk_id_veiculo, fk_id_instrutor) VALUES (3, 1, NULL, NULL);

-- INSERT PROVAS
INSERT INTO provas(fk_id_aluno, fk_id_tipo_servico, fk_id_veiculo, fk_id_instrutor, nota) VALUES (1, 4, 1, 3, 8);
INSERT INTO provas(fk_id_aluno, fk_id_tipo_servico, fk_id_veiculo, fk_id_instrutor, nota) VALUES (2, 3, NULL, NULL, 3);
INSERT INTO provas(fk_id_aluno, fk_id_tipo_servico, fk_id_veiculo, fk_id_instrutor, nota) VALUES (2, 3, NULL, NULL, 5);
INSERT INTO provas(fk_id_aluno, fk_id_tipo_servico, fk_id_veiculo, fk_id_instrutor, nota) VALUES (3, 4, 1, 3, 9);

-- INSERT TIPO PAGAMENTO
INSERT INTO tipo_pagamento(tipo) VALUES ('Boleto');

-- INSERT STATUS PAGAMENTO
INSERT INTO status_pagamento(status) VALUES ('Adimplente');
INSERT INTO status_pagamento(status) VALUES ('Indimplente');

-- INSERT VALORES
INSERT INTO valores(fk_id_aluno, fk_id_tipo_pagamento, fk_id_status) VALUES (1, 1, 1);
INSERT INTO valores(fk_id_aluno, fk_id_tipo_pagamento, fk_id_status) VALUES (1, 1, 2);
INSERT INTO valores(fk_id_aluno, fk_id_tipo_pagamento, fk_id_status) VALUES (1, 1, 2);
INSERT INTO valores(fk_id_aluno, fk_id_tipo_pagamento, fk_id_status) VALUES (2, 1, 1);
INSERT INTO valores(fk_id_aluno, fk_id_tipo_pagamento, fk_id_status) VALUES (3, 1, 2);




