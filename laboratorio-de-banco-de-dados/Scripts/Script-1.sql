--
-- PostgreSQL database dump
--

DROP SCHEMA modelo CASCADE;

-- Dumped from database version 10.22
-- Dumped by pg_dump version 11.1

-- Started on 2022-12-01 14:52:46

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 7 (class 2615 OID 73831)
-- Name: modelo; Type: SCHEMA; Schema: -; Owner: postgres
--

CREATE SCHEMA modelo;

CREATE TABLE modelo.bandeira (
	id_bandeira SERIAL PRIMARY KEY,
	bandeira VARCHAR
);

--
-- TOC entry 235 (class 1259 OID 74225)
-- Name: coleta; Type: TABLE; Schema: modelo; Owner: postgres
--

CREATE TABLE modelo.coleta (
    compra_valor double precision,
    venda_valor double precision,
    data_coleta date,
    id_produto integer,
    id_revenda integer,
    id_coleta integer NOT NULL
);


ALTER TABLE modelo.coleta OWNER TO postgres;

--
-- TOC entry 236 (class 1259 OID 74232)
-- Name: coleta_id_coleta_seq; Type: SEQUENCE; Schema: modelo; Owner: postgres
--

CREATE SEQUENCE modelo.coleta_id_coleta_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE modelo.coleta_id_coleta_seq OWNER TO postgres;

--
-- TOC entry 2941 (class 0 OID 0)
-- Dependencies: 236
-- Name: coleta_id_coleta_seq; Type: SEQUENCE OWNED BY; Schema: modelo; Owner: postgres
--

ALTER SEQUENCE modelo.coleta_id_coleta_seq OWNED BY modelo.coleta.id_coleta;


--
-- TOC entry 229 (class 1259 OID 74181)
-- Name: endereco; Type: TABLE; Schema: modelo; Owner: postgres
--

CREATE TABLE modelo.endereco (
    bairro character varying,
    id_municipio integer,
    cep character varying,
    rua character varying,
    numero character varying,
    id_endereco integer NOT NULL
);


ALTER TABLE modelo.endereco OWNER TO postgres;

--
-- TOC entry 230 (class 1259 OID 74187)
-- Name: endereco_id_endereco_seq; Type: SEQUENCE; Schema: modelo; Owner: postgres
--

CREATE SEQUENCE modelo.endereco_id_endereco_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE modelo.endereco_id_endereco_seq OWNER TO postgres;

--
-- TOC entry 2942 (class 0 OID 0)
-- Dependencies: 230
-- Name: endereco_id_endereco_seq; Type: SEQUENCE OWNED BY; Schema: modelo; Owner: postgres
--

ALTER SEQUENCE modelo.endereco_id_endereco_seq OWNED BY modelo.endereco.id_endereco;


--
-- TOC entry 227 (class 1259 OID 74162)
-- Name: municipio; Type: TABLE; Schema: modelo; Owner: postgres
--

CREATE TABLE modelo.municipio (
    municipio character varying,
    estado_sigla character varying,
    id_municipio integer NOT NULL
);


ALTER TABLE modelo.municipio OWNER TO postgres;

--
-- TOC entry 228 (class 1259 OID 74169)
-- Name: municipio_id_municipio_seq; Type: SEQUENCE; Schema: modelo; Owner: postgres
--

CREATE SEQUENCE modelo.municipio_id_municipio_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE modelo.municipio_id_municipio_seq OWNER TO postgres;

--
-- TOC entry 2943 (class 0 OID 0)
-- Dependencies: 228
-- Name: municipio_id_municipio_seq; Type: SEQUENCE OWNED BY; Schema: modelo; Owner: postgres
--

ALTER SEQUENCE modelo.municipio_id_municipio_seq OWNED BY modelo.municipio.id_municipio;


--
-- TOC entry 223 (class 1259 OID 74126)
-- Name: produto; Type: TABLE; Schema: modelo; Owner: postgres
--

CREATE TABLE modelo.produto (
    produto character varying,
    unidade character varying,
    id_produto integer NOT NULL
);


ALTER TABLE modelo.produto OWNER TO postgres;

--
-- TOC entry 224 (class 1259 OID 74132)
-- Name: produto_id_produto_seq; Type: SEQUENCE; Schema: modelo; Owner: postgres
--

CREATE SEQUENCE modelo.produto_id_produto_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE modelo.produto_id_produto_seq OWNER TO postgres;

--
-- TOC entry 2944 (class 0 OID 0)
-- Dependencies: 224
-- Name: produto_id_produto_seq; Type: SEQUENCE OWNED BY; Schema: modelo; Owner: postgres
--

ALTER SEQUENCE modelo.produto_id_produto_seq OWNED BY modelo.produto.id_produto;


--
-- TOC entry 231 (class 1259 OID 74199)
-- Name: revenda; Type: TABLE; Schema: modelo; Owner: postgres
--

CREATE TABLE modelo.revenda (
    id_endereco integer,
    revenda character varying,
    complemento character varying,
    cnpj character varying,
    id_revenda integer NOT NULL
);


ALTER TABLE modelo.revenda OWNER TO postgres;

--
-- TOC entry 234 (class 1259 OID 74221)
-- Name: revenda_bandeira; Type: TABLE; Schema: modelo; Owner: postgres
--

CREATE TABLE modelo.revenda_bandeira (
    id_revenda_bandeira integer NOT NULL,
    id_bandeira integer,
    id_revenda integer,
    data_coleta date
);


ALTER TABLE modelo.revenda_bandeira OWNER TO postgres;

--
-- TOC entry 233 (class 1259 OID 74219)
-- Name: revenda_bandeira_id_revenda_bandeira_seq; Type: SEQUENCE; Schema: modelo; Owner: postgres
--

CREATE SEQUENCE modelo.revenda_bandeira_id_revenda_bandeira_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE modelo.revenda_bandeira_id_revenda_bandeira_seq OWNER TO postgres;

--
-- TOC entry 2945 (class 0 OID 0)
-- Dependencies: 233
-- Name: revenda_bandeira_id_revenda_bandeira_seq; Type: SEQUENCE OWNED BY; Schema: modelo; Owner: postgres
--

ALTER SEQUENCE modelo.revenda_bandeira_id_revenda_bandeira_seq OWNED BY modelo.revenda_bandeira.id_revenda_bandeira;


--
-- TOC entry 232 (class 1259 OID 74207)
-- Name: revenda_id_revenda_seq; Type: SEQUENCE; Schema: modelo; Owner: postgres
--

CREATE SEQUENCE modelo.revenda_id_revenda_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE modelo.revenda_id_revenda_seq OWNER TO postgres;

--
-- TOC entry 2946 (class 0 OID 0)
-- Dependencies: 232
-- Name: revenda_id_revenda_seq; Type: SEQUENCE OWNED BY; Schema: modelo; Owner: postgres
--

ALTER SEQUENCE modelo.revenda_id_revenda_seq OWNED BY modelo.revenda.id_revenda;

--
-- TOC entry 2788 (class 2604 OID 74234)
-- Name: coleta id_coleta; Type: DEFAULT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.coleta ALTER COLUMN id_coleta SET DEFAULT nextval('modelo.coleta_id_coleta_seq'::regclass);


--
-- TOC entry 2785 (class 2604 OID 74189)
-- Name: endereco id_endereco; Type: DEFAULT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.endereco ALTER COLUMN id_endereco SET DEFAULT nextval('modelo.endereco_id_endereco_seq'::regclass);


--
-- TOC entry 2784 (class 2604 OID 74171)
-- Name: municipio id_municipio; Type: DEFAULT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.municipio ALTER COLUMN id_municipio SET DEFAULT nextval('modelo.municipio_id_municipio_seq'::regclass);


--
-- TOC entry 2782 (class 2604 OID 74134)
-- Name: produto id_produto; Type: DEFAULT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.produto ALTER COLUMN id_produto SET DEFAULT nextval('modelo.produto_id_produto_seq'::regclass);


--
-- TOC entry 2786 (class 2604 OID 74209)
-- Name: revenda id_revenda; Type: DEFAULT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.revenda ALTER COLUMN id_revenda SET DEFAULT nextval('modelo.revenda_id_revenda_seq'::regclass);


--
-- TOC entry 2787 (class 2604 OID 74224)
-- Name: revenda_bandeira id_revenda_bandeira; Type: DEFAULT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.revenda_bandeira ALTER COLUMN id_revenda_bandeira SET DEFAULT nextval('modelo.revenda_bandeira_id_revenda_bandeira_seq'::regclass);

--
-- TOC entry 2802 (class 2606 OID 74236)
-- Name: coleta coleta_pkey; Type: CONSTRAINT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.coleta
    ADD CONSTRAINT coleta_pkey PRIMARY KEY (id_coleta);


--
-- TOC entry 2796 (class 2606 OID 74191)
-- Name: endereco endereco_pkey; Type: CONSTRAINT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.endereco
    ADD CONSTRAINT endereco_pkey PRIMARY KEY (id_endereco);


--
-- TOC entry 2794 (class 2606 OID 74173)
-- Name: municipio municipio_pkey; Type: CONSTRAINT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.municipio
    ADD CONSTRAINT municipio_pkey PRIMARY KEY (id_municipio);


--
-- TOC entry 2790 (class 2606 OID 74136)
-- Name: produto produto_pkey; Type: CONSTRAINT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.produto
    ADD CONSTRAINT produto_pkey PRIMARY KEY (id_produto);


--
-- TOC entry 2800 (class 2606 OID 74242)
-- Name: revenda_bandeira revenda_bandeira_pkey; Type: CONSTRAINT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.revenda_bandeira
    ADD CONSTRAINT revenda_bandeira_pkey PRIMARY KEY (id_revenda_bandeira);


--
-- TOC entry 2798 (class 2606 OID 74211)
-- Name: revenda revenda_pkey; Type: CONSTRAINT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.revenda
    ADD CONSTRAINT revenda_pkey PRIMARY KEY (id_revenda);


--
-- TOC entry 2807 (class 2606 OID 74248)
-- Name: coleta coleta_fk; Type: FK CONSTRAINT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.coleta
    ADD CONSTRAINT coleta_fk FOREIGN KEY (id_produto) REFERENCES modelo.produto(id_produto);


--
-- TOC entry 2808 (class 2606 OID 74258)
-- Name: coleta coleta_fk1; Type: FK CONSTRAINT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.coleta
    ADD CONSTRAINT coleta_fk1 FOREIGN KEY (id_revenda) REFERENCES modelo.revenda(id_revenda);


--
-- TOC entry 2803 (class 2606 OID 74243)
-- Name: endereco endereco_fk; Type: FK CONSTRAINT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.endereco
    ADD CONSTRAINT endereco_fk FOREIGN KEY (id_municipio) REFERENCES modelo.municipio(id_municipio);


--
-- TOC entry 2805 (class 2606 OID 74263)
-- Name: revenda_bandeira revenda_bandeira_fk; Type: FK CONSTRAINT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.revenda_bandeira
    ADD CONSTRAINT revenda_bandeira_fk FOREIGN KEY (id_revenda) REFERENCES modelo.revenda(id_revenda);


--
-- TOC entry 2806 (class 2606 OID 74268)
-- Name: revenda_bandeira revenda_bandeira_fk1; Type: FK CONSTRAINT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.revenda_bandeira
    ADD CONSTRAINT revenda_bandeira_fk1 FOREIGN KEY (id_bandeira) REFERENCES modelo.bandeira(id_bandeira);


--
-- TOC entry 2804 (class 2606 OID 74273)
-- Name: revenda revenda_fk; Type: FK CONSTRAINT; Schema: modelo; Owner: postgres
--

ALTER TABLE ONLY modelo.revenda
    ADD CONSTRAINT revenda_fk FOREIGN KEY (id_endereco) REFERENCES modelo.endereco(id_endereco);


-- Completed on 2022-12-01 14:52:47

--
-- PostgreSQL database dump complete
--

