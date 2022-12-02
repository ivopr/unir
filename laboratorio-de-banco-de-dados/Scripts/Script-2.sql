-- Insert Municipios
INSERT INTO modelo.municipio(municipio, estado_sigla) SELECT DISTINCT c.municipio, c."Estado - Sigla" as estado_sigla FROM combustivel.ca c;

-- Insert Bandeiras
INSERT INTO modelo.bandeira(bandeira) SELECT DISTINCT c.bandeira FROM combustivel.ca c;

-- Insert Produtos
INSERT INTO modelo.produto(produto, unidade) SELECT DISTINCT c.produto, c."Unidade de Medida" as unidade FROM combustivel.ca c;

-- Insert Enderecos
INSERT INTO modelo.endereco(bairro, id_municipio, cep, rua, numero) SELECT DISTINCT c.bairro, m.id_municipio, c.cep, c."Nome da Rua" as rua, c."Numero Rua" as numero FROM combustivel.ca c INNER JOIN modelo.municipio m ON c.municipio = m.municipio AND c."Estado - Sigla" = m.estado_sigla;

-- Insert Revenda
INSERT INTO modelo.revenda(id_endereco, revenda, complemento, cnpj) SELECT DISTINCT b.id_endereco, c.revenda, c.complemento, c."CNPJ da Revenda" as cnpj FROM combustivel.ca c INNER JOIN modelo.endereco b ON c."Nome da Rua" = b.rua AND c."Numero Rua" = b.numero AND c.bairro = b.bairro AND c.cep = b.cep;

-- Insert Revenda-Bandeiras
INSERT INTO modelo.revenda_bandeira(id_bandeira, id_revenda, data_coleta) SELECT DISTINCT b.id_bandeira, r.id_revenda, min(TO_DATE(c."Data da Coleta", 'DD/MM/YYYY')) as data_coleta FROM combustivel.temps c INNER JOIN modelo.revenda r ON r.revenda = c.revenda AND r.cnpj = c."CNPJ da Revenda" INNER JOIN modelo.bandeira b ON c.bandeira = b.bandeira GROUP BY 1,2;

-- Insert Coleta
INSERT INTO modelo.coleta(compra_valor, venda_valor, data_coleta, id_produto, id_revenda) SELECT  FROM combustivel.ca c JOIN ;


