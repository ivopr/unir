-- Produto e Unidade de Medida
SELECT DISTINCT c.produto, c."Unidade de Medida" as unidade INTO combustivel.produto FROM combustivel.ca c;
ALTER TABLE combustivel.produto ADD COLUMN id_produto SERIAL NOT NULL PRIMARY KEY;

-- Bandeira
SELECT DISTINCT c.bandeira INTO combustivel.bandeira FROM combustivel.ca c;
ALTER TABLE combustivel.bandeira ADD COLUMN id_bandeira SERIAL NOT NULL PRIMARY KEY;

-- Municipio
SELECT DISTINCT c.municipio, c."Estado - Sigla" as estado_sigla INTO combustivel.municipio FROM combustivel.ca c;
ALTER TABLE combustivel.municipio ADD COLUMN id_municipio SERIAL NOT NULL PRIMARY KEY;

-- Endereco
SELECT DISTINCT c.bairro, m.id_municipio, c.cep, c."Nome da Rua" as nome_rua, c."Numero Rua" as numero_rua INTO combustivel.endereco FROM combustivel.ca c INNER JOIN combustivel.municipio m ON c.municipio  = m.municipio AND c."Estado - Sigla" = m.estado_sigla;
ALTER TABLE combustivel.endereco ADD COLUMN id_endereco SERIAL NOT NULL PRIMARY KEY;

-- Quantidade de bairros em uma cidade
SELECT DISTINCT COUNT (c.bairro) FROM combustivel.endereco c INNER JOIN combustivel.municipio b ON c.id_municipio=b.id_municipio WHERE UPPER (b.municipio) = UPPER('Sao Paulo');

-- Quantidade de bairros em uma cidade sem repetição de nomes
SELECT COUNT (DISTINCT c.bairro) AS numero_bairro FROM combustivel.endereco c INNER JOIN combustivel.municipio b ON c.id_municipio=b.id_municipio WHERE UPPER (b.municipio) = UPPER('Sao Paulo');

-- Quantidade de bairros por cidade, sem repetição de nomes
SELECT b.municipio, COUNT (DISTINCT c.bairro) AS numero_bairro FROM combustivel.endereco c INNER JOIN combustivel.municipio b ON c.id_municipio=b.id_municipio WHERE b.estado_sigla='SP' GROUP BY b.municipio;

-- Quantidade de repetições de nome de bairros, apenas os 10 mais repetidos
SELECT c.bairro, COUNT(b.municipio) FROM combustivel.endereco c INNER JOIN combustivel.municipio b ON c.id_municipio=b.id_municipio GROUP BY 1 ORDER BY 2 DESC LIMIT 10;


-- QUE PORRA É ESSA AQUI JUDEU????
SELECT c.bairro, count (b.municipio) FROM combustivel.endereco c INNER JOIN combustivel.municipio b ON c.id_municipio=b.id_municipio GROUP BY 1 HAVING count (b.municipio)>111 ORDER BY 2 DESC;


-- Deleta a view
DROP VIEW combustivel.vi_bairro_municipio;

-- Cria a view com base no conjunto de dados passado após o 'AS'
CREATE VIEW combustivel.vi_bairro_municipio AS SELECT c.bairro, count (b.municipio) AS numero_municipio FROM combustivel.endereco c INNER JOIN combustivel.municipio b ON c.id_municipio=b.id_municipio GROUP BY 1 HAVING count (B.municipio)>111 ORDER BY 2 DESC;

-- Retorna a soma dos valores dos elementos na view
SELECT sum(c.numero_municipio) FROM combustivel.vi_bairro_municipio c;

-- Retorna os campos dentro da view
SELECT c.* FROM combustivel.vi_bairro_municipio c



-- Revenda
SELECT DISTINCT b.id_municipio, c.revenda, c.complemento, c."CNPJ da Revenda" as cnpj INTO combustivel.revenda FROM combustivel.ca c INNER JOIN combustivel.municipio b ON c.municipio = b.municipio AND c."Estado - Sigla" = b.estado_sigla;

-- Atividade (Relacionar NxN Revenda e Bandeira)
--- Cria campo de id da revenda
ALTER TABLE combustivel.revenda ADD COLUMN id_revenda SERIAL NOT NULL PRIMARY KEY;

drop table combustivel.revenda_bandeiras;

SELECT DISTINCT r.id_revenda, b.id_bandeira INTO combustivel.revenda_bandeiras FROM combustivel.ca c INNER JOIN combustivel.revenda r ON r.revenda = c.revenda AND r.cnpj = c."CNPJ da Revenda" INNER JOIN combustivel.bandeira b ON c.bandeira = b.bandeira;


ALTER TABLE combustivel.revenda_bandeiras ADD FOREIGN KEY (id_revenda) REFERENCES combustivel.revenda(id_revenda);

ALTER TABLE combustivel.revenda_bandeiras ADD FOREIGN KEY (id_bandeira) REFERENCES combustivel.bandeira(id_bandeira);


