-- CreateTable
CREATE TABLE "cliente" (
    "id" TEXT NOT NULL,
    "nome" TEXT NOT NULL,
    "telefone" TEXT,
    "celular" TEXT,
    "email" TEXT NOT NULL,

    CONSTRAINT "cliente_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "endereco" (
    "id" TEXT NOT NULL,
    "id_cliente" TEXT NOT NULL,
    "rua" TEXT NOT NULL,
    "numero" INTEGER NOT NULL,
    "bairro" TEXT NOT NULL,
    "cidade" TEXT NOT NULL,
    "estado" TEXT NOT NULL,
    "cep" TEXT NOT NULL,
    "complemento" TEXT NOT NULL,

    CONSTRAINT "endereco_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "locacao" (
    "id" TEXT NOT NULL,
    "id_cliente" TEXT NOT NULL,
    "id_midia" TEXT NOT NULL,
    "data_emprestimo" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "data_devolucao" TIMESTAMP(3) NOT NULL,

    CONSTRAINT "locacao_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "midia" (
    "id" TEXT NOT NULL,
    "id_filme" TEXT NOT NULL,

    CONSTRAINT "midia_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "filme" (
    "id" TEXT NOT NULL,
    "id_caregoria" TEXT NOT NULL,
    "descricao" TEXT NOT NULL,
    "ano" TIMESTAMP(3) NOT NULL,

    CONSTRAINT "filme_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "categoria" (
    "id" TEXT NOT NULL,
    "descricao" TEXT NOT NULL,

    CONSTRAINT "categoria_pkey" PRIMARY KEY ("id")
);

-- CreateIndex
CREATE UNIQUE INDEX "cliente_email_key" ON "cliente"("email");

-- CreateIndex
CREATE UNIQUE INDEX "endereco_id_cliente_key" ON "endereco"("id_cliente");

-- AddForeignKey
ALTER TABLE "cliente" ADD CONSTRAINT "cliente_id_fkey" FOREIGN KEY ("id") REFERENCES "endereco"("id_cliente") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "locacao" ADD CONSTRAINT "locacao_id_cliente_fkey" FOREIGN KEY ("id_cliente") REFERENCES "cliente"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "locacao" ADD CONSTRAINT "locacao_id_midia_fkey" FOREIGN KEY ("id_midia") REFERENCES "midia"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "midia" ADD CONSTRAINT "midia_id_filme_fkey" FOREIGN KEY ("id_filme") REFERENCES "filme"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "filme" ADD CONSTRAINT "filme_id_caregoria_fkey" FOREIGN KEY ("id_caregoria") REFERENCES "categoria"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
