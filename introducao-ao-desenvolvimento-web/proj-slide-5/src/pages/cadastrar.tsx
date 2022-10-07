import { Box, Flex, Heading, useToast, VStack } from "@chakra-ui/react";
import { yupResolver } from "@hookform/resolvers/yup"
import { ArrowLeft32Filled, ArrowForwardDownPersonFilled } from "@fluentui/react-icons";
import Router from "next/router";
import { SubmitHandler, useForm } from "react-hook-form";
import * as yup from "yup";

import { Button, FormInput, Layout } from "../components";
import { setupApiClient } from "../services/api";
import { useUsuarios } from "../queries/useUsuarios";

type NewUserData = {
	nome: string;
	username: string;
	email: string;
	celular: string;
	nascimento: string;
	senha: string;
	confirmarSenha: string;
}

const NewUserShape = yup.object().shape({
	nome: yup.string().required(),
	username: yup.string().required(),
	email: yup.string().email().required(),
	nascimento: yup.date().required(),
	celular: yup.string().required(),
	senha: yup.string().min(3).required(),
	confirmarSenha: yup.string().min(3).oneOf([yup.ref('senha'), null]).required(),
});

export default function Cadastrar() {
	const toast = useToast();
	const { formState, handleSubmit, register, reset } = useForm<NewUserData>({
		resolver: yupResolver(NewUserShape)
	});
	const { refetch } = useUsuarios(1);

	const cadastrarUsuario: SubmitHandler<NewUserData> = async ({
		celular,
		email,
		nascimento,
		nome,
		senha,
		username
	}) => {
		const api = setupApiClient();

		await api.post("usuario", {
			celular,
			email,
			nascimento,
			nome,
			senha,
			username
		}).then(() => {
			toast({
				title: "Usuário cadastrado!",
				duration: 5000,
				status: "success",
				variant: "solid",
				position: "top"
			});
			reset();
			refetch();
			Router.push("/");
		}).catch(() => {
			toast({
				title: "Não foi possível cadastrar o usuário!",
				duration: 5000,
				status: "error",
				variant: "solid",
				position: "top"
			});
		})
	};

	return (
		<Layout pageTitle="Novo Usuário">
			<Flex alignItems="center" justifyContent="space-between" borderBottomColor="gray.700" borderBottomWidth="thin" height="20" paddingX="5" width="full">
				<Box paddingX={["0.5", "2.5", "5"]}>
					<ArrowLeft32Filled cursor="pointer" onClick={() => Router.push("/")} />
				</Box>
				<Heading fontSize={["xl", "2xl", "3xl"]}>Cadastrar Usuário</Heading>
				<Box />
			</Flex>

			<VStack
				as="form"
				marginX="auto"
				marginY="5"
				maxWidth={{
					base: "95%",
					md: "75%",
					lg: "35%"
				}}
				onSubmit={handleSubmit(cadastrarUsuario)}
				spacing="2.5"
			>
				<FormInput label="Nome de Usuário" error={formState.errors.username} {...register("username")} />
				<FormInput label="Email" error={formState.errors.email} {...register("email")} />
				<FormInput label="Nome" error={formState.errors.nome} {...register("nome")} />
				<FormInput type="date" label="Data de Nascimento" error={formState.errors.nascimento} {...register("nascimento")} />
				<FormInput label="Número de Celular" error={formState.errors.celular} {...register("celular")} />
				<FormInput type="password" label="Senha" error={formState.errors.senha} {...register("senha")} />
				<FormInput type="password" label="Confirmar Senha" error={formState.errors.confirmarSenha} {...register("confirmarSenha")} />
				<Button
					disabled={formState.isSubmitting}
					rightIcon={<ArrowForwardDownPersonFilled fontSize="22" />}
					size="lg"
					type="submit"
					width="full"
				>
					Cadastrar
				</Button>
			</VStack>
		</Layout>
	)
}