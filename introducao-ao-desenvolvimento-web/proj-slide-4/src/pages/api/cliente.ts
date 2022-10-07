import { NextApiRequest, NextApiResponse } from "next";
import { prisma } from "../../services/prisma";

function checkIsNotEmptyOrUndefined(toCheck: string | undefined) {
  if (toCheck === undefined || toCheck === "") {
    return true;
  }

  return false;
}

export default async function handler(req: NextApiRequest, res: NextApiResponse) {
  if (req.method === "POST") {
    const { nome, telefone, celular, email, rua, numero, bairro, cidade, estado, cep, complemento } = req.body;

    if (checkIsNotEmptyOrUndefined(nome) || checkIsNotEmptyOrUndefined(email) ||
        checkIsNotEmptyOrUndefined(rua) || checkIsNotEmptyOrUndefined(numero) ||
        checkIsNotEmptyOrUndefined(bairro) || checkIsNotEmptyOrUndefined(cidade) ||
        checkIsNotEmptyOrUndefined(estado) || checkIsNotEmptyOrUndefined(cep) ||
        checkIsNotEmptyOrUndefined(complemento)
    ) {
      res.status(400).json({
        code: "cliente.falha",
        message: "Alguns campos estão vazios"
      });
    }

    const cliente = await prisma.cliente.findFirst({
      where: {
        email:  { equals: email },
      }
    });

    if (cliente) {
      res.status(400).json({
        code: "cliente.existe",
        message: "Cliente já existente"
      });
    }

    const endereco = await prisma.endereco.create({
      data: {
        bairro,
        cep,
        cidade,
        complemento,
        estado,
        numero: Number(numero),
        rua,
      }
    });

    if (checkIsNotEmptyOrUndefined(endereco.id)) {
      res.status(400).json({
        code: "cliente.endereco.falha",
        message: "Não foi possivel criar o endereço"
      });
    }

    const novoCliente = await prisma.cliente.create({
      data: {
        email,
        nome,
        celular,
        endereco: {
          connect: {
            id: endereco.id
          }
        }
      },
      include: {
        endereco: true,
      }
    })

    res.status(201).json({
      code: "cliente.criado",
      cliente: novoCliente
    })
  } else if (req.method === "GET") {
    const clientes = await prisma.cliente.findMany({
      include: {
        endereco: true,
      }
    });

    res.json({
      quantidade: clientes.length,
      clientes,
    });
  }
}
