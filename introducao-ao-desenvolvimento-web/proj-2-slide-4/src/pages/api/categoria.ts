import { NextApiRequest, NextApiResponse } from "next";
import { prisma } from "../../services/prisma";

export default async function handler(req: NextApiRequest, res: NextApiResponse) {
  if (req.method === "POST") {
    const { nome, descricao } = req.body;

    if (nome === "" || nome === undefined || descricao === "" || descricao === undefined) {
      res.status(400).json({
        code: "categoria.falha",
        message: "Alguns campos estão vazios"
      })
    }
    
    const categoria = await prisma.categoria.findFirst({
      where: {
        nome: { equals: req.body.nome }
      }
    });

    if (categoria) {
      res.status(400).json({
        code: "categoria.existe",
        message: "Categoria já existente"
      });
    }

    const novaCategoria = await prisma.categoria.create({
      data: {
        nome: req.body.nome,
        descricao: req.body.descricao
      }
    });

    res.status(201).json({
      code: "categoria.criada",
      categoria: novaCategoria
    });
  } else if (req.method === "GET") {
    const categorias = await prisma.categoria.findMany();

    res.json({
      quantidade: categorias.length,
      categorias,
    })
  }
}
