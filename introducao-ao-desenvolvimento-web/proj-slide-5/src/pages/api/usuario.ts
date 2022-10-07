import { NextApiRequest, NextApiResponse } from "next"
import { prisma } from "../../services/prisma"
import { compare, hash } from "bcryptjs"

export default async function handle(req: NextApiRequest, res: NextApiResponse) {
	if (req.method === "POST") {
		const {
			celular,
			email,
			nascimento,
			nome,
			senha,
			username
		} = req.body;

		if (
			celular === "" || celular === undefined ||
			email === "" || email === undefined ||
			nascimento === "" || nascimento === undefined ||
			nome === "" || nome === undefined ||
			senha === "" || senha === undefined ||
			username === "" || username === undefined
		) {
			return res.status(400).json({
				code: "usuario.criar",
				message: "Algum(ns) campo(s) está(ão) vazio(s)"
			});
		}

		const usuario = await prisma.usuario.findFirst({
			where: {
				OR: [
					{ username: { equals: username } },
					{ email: { equals: email } }
				]
			}
		});

		if (usuario) {
			return res.status(400).json({
				code: "usuario.existe",
				message: "Usuário já existe com esse username/email"
			});
		}

		const senhaHasheada = await hash(senha, 8);

		const novoUsuario = await prisma.usuario.create({
			data: {
				celular,
				email,
				nascimento,
				nome,
				senha: senhaHasheada,
				username,
			},
			select: {
				celular: true,
				email: true,
				nascimento: true,
				nome: true,
				senha: false,
				username: true,
			}
		});

		return res.status(201).json({
			code: "usuario.criado",
			usuario: novoUsuario
		});
	} else if (req.method === "PUT") {
		const { identificador, senha, email, celular, nome } = req.body;

		const usuario = await prisma.usuario.findFirst({
			where: {
				OR: [
					{ username: { equals: identificador } },
					{ email: { equals: identificador } }
				]
			},
		});

		if (!usuario) {
			return res.status(400).json({
				code: "usuario.atualizacao",
				message: "Não há usuário com esse email/username"
			});
		}

		const senhasBatem = await compare(senha, usuario.senha);

		if (!senhasBatem) {
			return res.status(400).json({
				code: "usuario.atualizacao",
				message: "A sua senha não é válida"
			});
		}

		if (email !== usuario.email) {
			const emailDeOutroUsuario = await prisma.usuario.findFirst({
				where: {
					email: { equals: email }
				}
			});

			if (emailDeOutroUsuario) {
				return res.status(400).json({
					code: "usuario.atualizacao",
					message: "Seu novo email já está sendo usado.",
				});
			}
		}

		const usuarioAtualizado = await prisma.usuario.update({
			data: {
				nome,
				email,
				celular
			},
			where: {
				id: usuario.id
			},
			select: {
				ativo: true,
				celular: true,
				email: true,
				nascimento: true,
				nome: true,
				posicao: true,
				username: true,
			}
		});

		return res.json({
			code: "usuario.atualizado",
			usuario: usuarioAtualizado,
		});
	} else if (req.method === "DELETE") {
		const { identificador, senha } = req.query;

		if (
			identificador === "" || identificador === undefined ||
			senha === "" || senha === undefined
		) {
			return res.status(400).json({
				code: "usuario.deletar",
				message: "Alguns dados estão faltando."
			});
		}

		const usuario = await prisma.usuario.findFirst({
			where: {
				OR: [
					{ email: { equals: identificador as string } },
					{ username: { equals: identificador as string } }
				]
			}
		});

		if (!usuario) {
			return res.status(400).json({
				code: "usuario.deletar",
				message: "Não existe um usuario com esse email/username"
			});
		}

		const senhasBatem = await compare(senha as string, usuario.senha);

		if (!senhasBatem) {
			return res.status(400).json({
				code: "usuario.deletar",
				message: "As senhas estão erradas."
			});
		}

		await prisma.usuario.delete({
			where: {
				id: usuario.id,
			}
		});

		return res.json({
			code: "usuario.deletado",
			message: "Usuário deletado com sucesso"
		});
	} else if (req.method === "GET") {
		const { username, page } = req.query;

		if (username === "" || username === undefined) {
			const usuarios = await prisma.usuario.findMany({
				take: 12,
				skip: 12 * (Number(page) - 1),
				select: {
					ativo: true,
					celular: true,
					email: true,
					id: true,
					nascimento: true,
					nome: true,
					posicao: true,
					senha: false,
					username: true
				}
			});

			return res.json({
				quantidade: usuarios.length,
				usuarios
			});
		}

		const usuario = await prisma.usuario.findFirst({
			where: {
				username: { equals: String(username) }
			},
			select: {
				ativo: true,
				celular: true,
				email: true,
				id: true,
				nascimento: true,
				nome: true,
				posicao: true,
				senha: false,
				username: true
			}
		});

		if (!usuario) {
			return res.status(400).json({
				code: "usuario.falha",
				message: "O usuário buscado não existe"
			});
		}

		return res.json({
			usuario,
		});
	}
}