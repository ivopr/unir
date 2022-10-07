-- CreateEnum
CREATE TYPE "Posicao" AS ENUM ('ADMIN', 'USUARIO');

-- CreateTable
CREATE TABLE "Usuario" (
    "id" TEXT NOT NULL,
    "nome" TEXT NOT NULL,
    "email" TEXT NOT NULL,
    "username" TEXT NOT NULL,
    "senha" TEXT NOT NULL,
    "nascimento" TIMESTAMP(3) NOT NULL,
    "celular" TEXT NOT NULL,
    "ativo" BOOLEAN NOT NULL DEFAULT false,
    "posicao" "Posicao" NOT NULL DEFAULT E'USUARIO',

    CONSTRAINT "Usuario_pkey" PRIMARY KEY ("id")
);

-- CreateIndex
CREATE UNIQUE INDEX "Usuario_email_key" ON "Usuario"("email");

-- CreateIndex
CREATE UNIQUE INDEX "Usuario_username_key" ON "Usuario"("username");
