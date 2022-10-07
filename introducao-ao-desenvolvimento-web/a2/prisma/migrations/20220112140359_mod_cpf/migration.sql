/*
  Warnings:

  - Changed the type of `cpf` on the `Contact` table. No cast exists, the column would be dropped and recreated, which cannot be done if there is data, since the column is required.

*/
-- AlterTable
ALTER TABLE "Contact" DROP COLUMN "cpf",
ADD COLUMN     "cpf" INTEGER NOT NULL;
