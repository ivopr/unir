-- 4.2
SELECT a.nome FROM alunos a JOIN tipo_carteira tc ON a.fk_id_tipo_carteira = tc.id_tipo AND tc.tipo = 'B';

-- 4.3
SELECT a.nome FROM alunos a JOIN tipo_carteira tc ON a.fk_id_tipo_carteira = tc.id_tipo AND tc.tipo = 'AB';


SELECT COUNT(p.fk_id_aluno) FROM provas p;

-- 4.4
SELECT a.nome, p.nota FROM provas p INNER JOIN alunos a ON p.fk_id_aluno = a.id_aluno GROUP BY 2 HAVING COUNT(p.fk_id_aluno) > 1;

-- 4.5
SELECT a.nome FROM valores v INNER JOIN alunos a ON a.id_aluno = v.fk_id_aluno AND v.fk_id_status = 2 GROUP BY 1;

-- 4.6
SELECT * FROM alunos a ORDER BY a.idade DESC LIMIT 1;