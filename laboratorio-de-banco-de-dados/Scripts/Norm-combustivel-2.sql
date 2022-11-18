drop table combustivel.revenda_bandeira;

SELECT DISTINCT r.id_revenda, b.id_bandeira, min(c."Data da Coleta") as data_coleta INTO combustivel.revenda_bandeira FROM combustivel.ca c INNER JOIN combustivel.revenda r ON r.revenda = c.revenda AND r.cnpj = c."CNPJ da Revenda" INNER JOIN combustivel.bandeira b ON c.bandeira = b.bandeira GROUP BY 1, 2;

SELECT DISTINCT r.id_revenda, b.id_bandeira, min(c."Data da Coleta") FROM combustivel.ca c INNER JOIN combustivel.revenda r ON r.revenda = c.revenda AND r.cnpj = c."CNPJ da Revenda" INNER JOIN combustivel.bandeira b ON c.bandeira = b.bandeira GROUP BY 1, 2 LIMIT 200000;


ALTER TABLE combustivel.revenda_bandeira ADD FOREIGN KEY (id_revenda) REFERENCES combustivel.revenda(id_revenda);

ALTER TABLE combustivel.revenda_bandeira ADD FOREIGN KEY (id_bandeira) REFERENCES combustivel.bandeira(id_bandeira);

CREATE OR REPLACE VIEW combustivel.vi_revenda_bandeira AS SELECT * FROM combustivel.revenda_bandeira rb;

DROP VIEW combustivel.vi_revenda_bandeira;

CREATE MATERIALIZED VIEW combustivel.vim_revenda_bandeira AS SELECT * FROM combustivel.revenda_bandeira rb;

DROP VIEW combustivel.vim_revenda_bandeira;

SELECT * FROM combustivel.vi_revenda_bandeira vrb;

SELECT * FROM combustivel.vim_revenda_bandeira vrb;

CREATE VIEW vi_revenda AS SELECT DISTINCT * FROM combustivel.vi_revenda_bandeira vrb JOIN combustivel.revenda USING (id_revenda) JOIN combustivel.bandeira b USING (id_bandeira); 
