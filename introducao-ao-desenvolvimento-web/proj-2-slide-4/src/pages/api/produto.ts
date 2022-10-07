import { NextApiRequest, NextApiResponse } from "next";
import { prisma } from "../../services/prisma";

export default async function handler(req: NextApiRequest, res: NextApiResponse) {
  if (req.method === "POST") {
    const { nome, descricao, idCategoria, preco } = req.body;

		if (nome === "" || nome === undefined || descricao === "" || descricao === undefined ||
				idCategoria === "" || idCategoria === undefined || preco === "" || preco === undefined
		) {
			res.status(400).json({
				code: "produto.falha",
				message: "Alguns campos estão vazios"
			});
		}

		const produto = await prisma.produto.findFirst({
			where: {
				nome,
			}
		});

		if (produto) {
			res.status(400).json({
				code: "produto.existe",
				message: "Produto já existente"
			});
		}


		const novoProduto = await prisma.produto.create({
			data: {
				nome,
				preco: Number(preco),
				categoria: {
					connect: {
						id: idCategoria,
					}
				},
				descricao,
			},
			include: {
				categoria: true,
			}
		});

		res.status(201).json({
			code: "produto.criado",
			produto: novoProduto
		});
  } else if (req.method === "GET") {
    const produtos = await prisma.produto.findMany();

    res.json({
      quantidade: produtos.length,
      produtos,
    })
  }
}
