import { NextApiRequest, NextApiResponse } from "next";
import { prisma } from "../../services/prisma";

export default async function handler(req: NextApiRequest, res: NextApiResponse) {
  if (req.method === "POST") {
    const { nome, idCategoria, descricao, ano } = req.body;

    if (nome === "" || nome === undefined ||
        idCategoria === "" || idCategoria === undefined ||
        descricao === "" || descricao === undefined ||
        ano === "" || ano === undefined
    ) {
      res.status(400).json({
        code: "filme.falha",
        message: "Alguns campos estão vazios"
      });
    }

    const filme = await prisma.filme.findFirst({
      where: {
        nome: nome
      }
    })

    if (filme) {
      res.status(400).json({
        code: "filme.existente",
        message: "Filme já existente"
      });
    }
    
    const novoFilme = await prisma.filme.create({
      data: {
        ano,
        descricao,
        nome,
        categoria: {
          connect: {
            id: idCategoria
          }
        }
      }
    });

    res.status(201).json({
      code: "filme.criado",
      filme: novoFilme
    });
  } else if (req.method === "GET") {
    const filmes = await prisma.filme.findMany({
      include: {
        categoria: true,
      },
    });

    res.json({
      quantidade: filmes,
      filmes,
    });
  }
}
