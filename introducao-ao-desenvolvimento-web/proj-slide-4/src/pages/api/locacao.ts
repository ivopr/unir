import { NextApiRequest, NextApiResponse } from "next";
import { prisma } from "../../services/prisma";

export default async function handler(req: NextApiRequest, res: NextApiResponse) {
  if (req.method === "POST") {
    const { idCliente, idFilme, dataEmprestimo, dataDevolucao } = req.body;

    if (idCliente === "" || idCliente === undefined || idFilme === "" || idFilme === undefined ||
        dataEmprestimo === "" || dataEmprestimo === undefined || dataDevolucao === "" || dataDevolucao === undefined
    ) {
      res.status(401).json({
        code: "locacao.falha",
        message: "Alguns campos estão vazios"
      });
    }

    const novaMidia = await prisma.midia.create({
      data: {
        filme: {
          connect: {
            id: idFilme,
          }
        },
      }
    });

    const novaLocacao = await prisma.locacao.create({
      data: {
        cliente: {
          connect: {
            id: idCliente,
          }
        },
        midia: {
          connect: {
            id: novaMidia.id
          }
        },
        dataDevolucao,
        dataEmprestimo
      },
      select: {
        cliente: {
          select: {
            nome: true,
            email: true,
          }
        },
        dataDevolucao: true,
        dataEmprestimo: true,
        id: true,
        midia: true,
      }
    });

    res.json({
      code: "locacao.criada",
      locacao: novaLocacao
    });
  } else if (req.method === "GET") {
    const locacoes = await prisma.locacao.findMany({
      include: {
        midia: true,
      }
    });

    res.json({
      quantidade: locacoes.length,
      locacoes,
    });
  }
}
