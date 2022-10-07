/*
  Warnings:

  - A unique constraint covering the columns `[nome]` on the table `filme` will be added. If there are existing duplicate values, this will fail.
  - Added the required column `nome` to the `filme` table without a default value. This is not possible if the table is not empty.

*/
-- AlterTable
ALTER TABLE "filme" ADD COLUMN     "nome" TEXT NOT NULL;

-- CreateIndex
CREATE UNIQUE INDEX "filme_nome_key" ON "filme"("nome");
