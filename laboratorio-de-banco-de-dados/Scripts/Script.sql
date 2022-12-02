CREATE SCHEMA combustivel_normalizado;

CREATE TABLE combustivel_normalizado.bandeira (
	id_bandeira SERIAL PRIMARY KEY,
	bandeira VARCHAR
);

CREATE TABLE combustivel_normalizado.endereco (
	id_endereco SERIAL PRIMARY KEY,
	bairro VARCHAR,
	id_municipio INTEGER FOREIGN KEY REFERENCES combustivel_normalizado.municipio(id_municipio),
	cep VARCHAR,
	rua VARCHAR,
	numero VARCHAR,
);

CREATE TABLE combustivel_normalizado.coleta (
	id_coleta SERIAL PRIMARY KEY,
	id_produto INTEGER FOREIGN KEY REFERENCES combustivel_normalizado.produto(id_produto),
	id_revenda INTEGER FOREIGN KEY REFERENCES combustivel_normalizado.revenda(id_revenda),
	compra_valor DOUBLE PRECISION,
	venda_valor DOUBLE PRECISION,
	data_coleta DATE
);
