SELECT c.municipio, c."Estado - Sigla", c."Regiao - Sigla", c."Valor de Venda" FROM combustivel.ca c WHERE c.municipio = 'ARAPONGAS'
UNION
SELECT c.municipio, c."Estado - Sigla", c."Regiao - Sigla", c."Valor de Venda" FROM combustivel.ca c WHERE c.municipio = 'ARAUCARIA';


SELECT c.municipio, c."Estado - Sigla", c."Regiao - Sigla", c."Valor de Venda" FROM combustivel.ca c WHERE c.municipio = 'ARAPONGAS' OR c.municipio = 'ARAUCARIA';

SELECT c.municipio, c."Estado - Sigla", c."Regiao - Sigla", c."Valor de Venda" FROM combustivel.ca c WHERE c.municipio IN ('ARAPONGAS', 'ARAUCARIA');

SELECT c.municipio FROM combustivel.ca c WHERE c."Estado - Sigla" = 'BA'
INTERSECT
SELECT c.municipio FROM combustivel.ca c WHERE c."Estado - Sigla" = 'RJ';

SELECT c.municipio FROM combustivel.ca c WHERE c."Estado - Sigla" = 'BA'
UNION
SELECT c.municipio FROM combustivel.ca c WHERE c."Estado - Sigla" = 'RJ';


SELECT DISTINCT c.produto FROM combustivel.ca c;
SELECT DISTINCT c.bandeira FROM combustivel.ca c;
SELECT DISTINCT c."Regiao - Sigla" FROM combustivel.ca c;
SELECT DISTINCT c."Estado - Sigla" FROM combustivel.ca c;
SELECT DISTINCT c.municipio FROM combustivel.ca c;
SELECT DISTINCT c.revenda, c.bandeira FROM combustivel.ca c;