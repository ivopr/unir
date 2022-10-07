import { Box, Button, Flex, Heading, Image, VStack, Spinner, useToast } from "@chakra-ui/react";
import { yupResolver } from "@hookform/resolvers/yup";
import { ArrowLeft32Filled, PersonDeleteFilled, PersonEditFilled } from "@fluentui/react-icons";
import { useRouter } from "next/router";
import { SubmitHandler, useForm } from "react-hook-form";
import * as yup from "yup";

import { FormInput, Layout } from "../components";
import { useUsuario } from "../queries/useUsuario";
import { setupApiClient } from "../services/api";
import { useEffect } from "react";
import { AlertaExclusao } from "../components/alerta-exclusao/alerta-exclusao";
import { useUsuarios } from "../queries/useUsuarios";

type UserData = {
	nome: string;
	username: string;
	email: string;
	celular: string;
	nascimento: string;
	senha: string;
	confirmarSenha: string;
}

const UserShape = yup.object().shape({
	nome: yup.string().required(),
	username: yup.string().required(),
	email: yup.string().email().required(),
	celular: yup.string().required(),
	senha: yup.string().min(3).required(),
	confirmarSenha: yup.string().min(3).oneOf([yup.ref('senha'), null]).required(),
});

export default function Usuario() {
	const router = useRouter();
	const { username } = router.query;
	const { data, isError, refetch } = useUsuario(String(username));
	const { refetch: refetchUsuarios } = useUsuarios(1);
	const { formState, handleSubmit, register, setValue } = useForm<UserData>({
		resolver: yupResolver(UserShape),
	});
	const toast = useToast();

	useEffect(() => {
		const nascimento = new Date(data?.nascimento).toLocaleDateString("pt-BR", {
			day: "2-digit",
			month: "long",
			year: "numeric"
		});
		setValue("nome", data?.nome);
		setValue("celular", data?.celular);
		setValue("email", data?.email);
		setValue("nascimento", nascimento);
		setValue("username", data?.username);
	}, [data, setValue]);

	const atualizarUsuario: SubmitHandler<UserData> = async ({
		celular,
		email,
		nome,
		senha,
		username
	}) => {
		const api = setupApiClient();

		await api.put("usuario", {
			identificador: username,
			senha,
			email,
			celular,
			nome
		}).then(() => {
			toast({
				title: "Usuário atualizado!",
				duration: 5000,
				status: "success",
				variant: "solid",
				position: "top"
			});
			refetch();
			refetchUsuarios();
		}).catch(() => {
			toast({
				title: "Não foi possível atualizar o usuário",
				duration: 5000,
				status: "error",
				variant: "solid",
				position: "top"
			});
		});
	}

	return (
		<Layout pageTitle={username as string}>
			<Flex
				alignItems="center"
				borderBottomColor="gray.700"
				borderBottomWidth="thin"
				height="20"
				justifyContent="space-between"
				paddingX="5"
				width="full"
			>
				<Box paddingX={["0.5", "2.5", "5"]}>
					<ArrowLeft32Filled cursor="pointer" onClick={() => router.push("/")} />
				</Box>
				<Heading fontSize={["xl", "2xl", "3xl"]}>Perfil de {username}</Heading>
				<AlertaExclusao username={username as string} />
			</Flex>

			{data !== undefined ? (
				<VStack marginX="auto" marginY="5" spacing="5" maxWidth="1080px">
					<Image alt={data.nome} borderRadius="base" src="https://placekitten.com/1080/512" />

					<VStack
						as="form"
						onSubmit={handleSubmit(atualizarUsuario)}
						spacing="2.5"
						width="full"
					>
						<FormInput disabled label="Nome de Usuário" error={formState.errors.username} {...register("username")} />
						<FormInput label="Email" error={formState.errors.email} {...register("email")} />
						<FormInput label="Nome" error={formState.errors.nome} {...register("nome")} />
						<FormInput disabled label="Data de Nascimento" error={formState.errors.nascimento} {...register("nascimento")} />
						<FormInput label="Número de Celular" error={formState.errors.celular} {...register("celular")} />
						<FormInput label="Senha" type="password" error={formState.errors.senha} {...register("senha")} />
						<FormInput label="Confirmar Senha" type="password" error={formState.errors.confirmarSenha} {...register("confirmarSenha")} />
						<Button
							_hover={{
								backgroundColor: "green.700",
								color: "white"
							}}
							backgroundColor="green.500"
							color="gray.200"
							disabled={formState.isSubmitting}
							rightIcon={<PersonEditFilled fontSize="22" />}
							size="lg"
							type="submit"
							width="full"
						>
							Cnfirmar Edição
						</Button>
					</VStack>
				</VStack>
			) : isError ? (
				<Heading>Não foi possível carregar o usuário <b>{username}</b></Heading>
			) : (
        <VStack marginY="10">
          <Spinner emptyColor="gray.200" color="primary.500" thickness="2px" size="xl" />
        </VStack>
			)}
		</Layout>
	)
} 