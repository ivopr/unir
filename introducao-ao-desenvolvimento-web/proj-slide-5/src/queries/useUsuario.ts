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

export async function getUsuario(username: string): Promise<Usuario> {
	const api = setupApiClient();
	const { data } = await api.get(`usuario?username=${username}`);

	const usuario: Usuario = data.usuario;

	return usuario;
}

export function useUsuario(
	username: string,
	options?: UseQueryOptions<Usuario, unknown>
): UseQueryResult<Usuario, unknown> {
	return useQuery(["usuario", username], () => getUsuario(username), {
		staleTime: 1000 * 60 * 1,
		...options
	});
}