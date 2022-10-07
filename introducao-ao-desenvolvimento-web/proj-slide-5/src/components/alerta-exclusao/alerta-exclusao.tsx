import {
	Button,
	Flex,
	Heading,
	Modal,
	ModalBody,
	ModalCloseButton,
	ModalContent,
	ModalFooter,
	ModalHeader,
	ModalOverlay,
	useDisclosure,
	useToast
} from "@chakra-ui/react";
import { PersonDeleteFilled } from "@fluentui/react-icons";
import { yupResolver } from "@hookform/resolvers/yup";
import { useRouter } from "next/router";
import { SubmitHandler, useForm } from "react-hook-form";
import * as yup from "yup";
import { useUsuarios } from "../../queries/useUsuarios";

import { setupApiClient } from "../../services/api";
import { FormInput } from "../input/input";

type AlertaExclusaoProps = {
	username: string;
}

type DeletionData = {
	senha: string;
}

const DeletionShape = yup.object().shape({
	senha: yup.string().min(3).required(),
});

export function AlertaExclusao({ username }: AlertaExclusaoProps) {
  const { isOpen, onOpen, onClose } = useDisclosure();
	const { watch, formState, handleSubmit, register, reset } = useForm<DeletionData>({
		resolver: yupResolver(DeletionShape),
	});
	const toast = useToast();
	const router = useRouter();
	const { senha } = watch();
	const { refetch } = useUsuarios(1);

	const deletarUsuario: SubmitHandler<DeletionData> = async ({
		senha
	}) => {
		const api = setupApiClient();

		await api.delete(`usuario?identificador=${username}&senha=${senha}`).then(() => {
			toast({
				title: "Usuário Deletado!",
				duration: 5000,
				status: "success",
				variant: "solid",
				position: "top"
			});
			reset();
			refetch();
			router.push("/");
		}).catch(() => {
			toast({
				title: "Não foi possível deletar o usuário!",
				duration: 5000,
				status: "error",
				variant: "solid",
				position: "top"
			});
			reset();
			onClose();
		});
	}

  return (
    <>
			<Button
				_hover={{
					backgroundColor: "red.800",
					color: "white"
				}}
				backgroundColor="red.700"
				color="gray.100"
				leftIcon={<PersonDeleteFilled fontSize="22" />}
				onClick={onOpen}
				size="lg"
			>
				Excluir
			</Button>

      <Modal isOpen={isOpen} onClose={onClose}>
        <ModalOverlay />
        <ModalContent>
          <ModalHeader>Cuidado!</ModalHeader>
          <ModalCloseButton />
          <ModalBody as="form" onSubmit={handleSubmit(deletarUsuario)}>
						Tem certeza que deseja excluir sua conta?
						Confirme sua senha para continuar:
						<FormInput type="password" error={formState.errors.senha} {...register("senha")} />

						<Flex justifyContent="space-between" marginTop="5">
							<Button
								_hover={{
									backgroundColor: "red.800",
									color: "white"
								}}
								backgroundColor="red.700"
								color="gray.100"
								disabled={!(senha?.length >= 3)}
								leftIcon={<PersonDeleteFilled fontSize="22" />}
								type="submit"
								width="48%"
							>
								Deletar
							</Button>

							<Button onClick={onClose} variant="ghost" width="48%">
								Cancelar
							</Button>
						</Flex>
          </ModalBody>
        </ModalContent>
      </Modal>
    </>
  )
}