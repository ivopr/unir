import { GetServerSidePropsContext } from "next";
import { useQuery, UseQueryOptions, UseQueryResult } from "react-query";
import { setupApiClient } from "../services/api";

export type Usuario = {
	ativo: boolean;
	celular: string;
	email: string;
	id: string;
	nascimento: string;
	nome: string;
	posicao: "USUARIO" | "ADMIN";
	username: string;
}

export type RespostaGetUsuarios = {
	usuarios: Usuario[];
	quantidade: number;
}

export async function getUsuarios(
	page = 1,
	context?: GetServerSidePropsContext
): Promise<RespostaGetUsuarios> {
	const api = setupApiClient();
	const { data } = await api.get(`usuario?page=${page}`);

	const usuarios: Usuario[] = data.usuarios;
	const quantidade = Number(data.quantidade);

	return { usuarios, quantidade };
}

export function useUsuarios(
	page: number,
	options?: UseQueryOptions<RespostaGetUsuarios, unknown>
): UseQueryResult<RespostaGetUsuarios, unknown> {
	return useQuery(["usuarios", page], () => getUsuarios(page), {
		staleTime: 1000 * 60 * 1,
		...options
	});
}