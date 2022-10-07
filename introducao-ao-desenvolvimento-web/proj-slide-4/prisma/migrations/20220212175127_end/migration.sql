/*
  Warnings:

  - You are about to drop the column `id_cliente` on the `endereco` table. All the data in the column will be lost.
  - A unique constraint covering the columns `[idEndereco]` on the table `cliente` will be added. If there are existing duplicate values, this will fail.
  - Added the required column `idEndereco` to the `cliente` table without a default value. This is not possible if the table is not empty.

*/
-- DropForeignKey
ALTER TABLE "endereco" DROP CONSTRAINT "endereco_id_cliente_fkey";

-- DropIndex
DROP INDEX "endereco_id_cliente_key";

-- AlterTable
ALTER TABLE "cliente" ADD COLUMN     "idEndereco" TEXT NOT NULL;

-- AlterTable
ALTER TABLE "endereco" DROP COLUMN "id_cliente";

-- CreateIndex
CREATE UNIQUE INDEX "cliente_idEndereco_key" ON "cliente"("idEndereco");

-- AddForeignKey
ALTER TABLE "cliente" ADD CONSTRAINT "cliente_idEndereco_fkey" FOREIGN KEY ("idEndereco") REFERENCES "endereco"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
