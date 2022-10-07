-- DropForeignKey
ALTER TABLE "cliente" DROP CONSTRAINT "cliente_id_fkey";

-- AddForeignKey
ALTER TABLE "endereco" ADD CONSTRAINT "endereco_id_cliente_fkey" FOREIGN KEY ("id_cliente") REFERENCES "cliente"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
