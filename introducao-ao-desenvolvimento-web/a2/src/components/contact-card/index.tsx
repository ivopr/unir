import {
  Box,
  Button,
  Icon,
  Modal,
  ModalBody,
  ModalContent,
  ModalFooter,
  ModalHeader,
  ModalOverlay,
  Text,
  useColorModeValue,
  useDisclosure,
  useToast,
} from "@chakra-ui/react";
import { yupResolver } from "@hookform/resolvers/yup/dist/yup";
import { Contact } from "@prisma/client";
import React from "react";
import { SubmitHandler, useForm } from "react-hook-form";
import { RiPencilLine } from "react-icons/ri";
import {
  QueryObserverResult,
  RefetchOptions,
  RefetchQueryFilters,
} from "react-query";
import * as yup from "yup";

import { setupApiClient } from "../../services/api";
import { GetContactsResponse } from "../../services/react-query/hooks/use-contacts";
import { Input } from "../input";

const editContactFormSchema = yup.object().shape({
  number: yup.string(),
  email: yup.mixed(),
  cpf: yup.string(),
  obs: yup.string(),
});

interface ContactCardProps extends Contact {
  refetch: <TPageData>(
    options?: (RefetchOptions & RefetchQueryFilters<TPageData>) | undefined
  ) => Promise<QueryObserverResult<GetContactsResponse, unknown>>;
}

export function ContactCard({
  refetch,
  ...contact
}: ContactCardProps): JSX.Element {
  const { isOpen, onOpen, onClose } = useDisclosure();
  const {
    formState: { errors },
    handleSubmit,
    register,
    reset,
  } = useForm<Contact>({
    resolver: yupResolver(editContactFormSchema),
  });
  const toast = useToast();

  const contactBoxBackgroundColor = useColorModeValue(
    "primary.200",
    "primary.800"
  );

  const handleEdit: SubmitHandler<Contact> = async ({
    cpf,
    email,
    number,
    obs,
  }) => {
    const api = setupApiClient();

    await api
      .post("/contacts", {
        id: contact.id,
        name: contact.name,
        number: number !== "" ? number : contact.number,
        email: email !== "" ? email : contact.email,
        cpf: cpf !== "" ? cpf : contact.cpf,
        obs: obs !== "" ? obs : contact.obs,
      })
      .then(async () => {
        toast({
          duration: 5000,
          title: `Contato de ${contact.name} atualizado`,
          status: "success",
        });
        await refetch();
      })
      .catch(() => {
        toast({
          duration: 5000,
          title: `Não foi possível atualizar o contato de ${contact.name}`,
          status: "error",
        });
      });
  };

  return (
    <>
      <Box
        backgroundColor={contactBoxBackgroundColor}
        borderRadius="lg"
        cursor="pointer"
        onClick={onOpen}
        padding={4}
        position="relative"
      >
        <Icon as={RiPencilLine} fontSize="lg" position="absolute" right={4} />
        <Text>Nome: {contact.name}</Text>
        <Text>CPF: {contact.cpf}</Text>
        <Text>Email: {contact.email}</Text>
        <Text>Telefone: {contact.number}</Text>
        <Text>Observação: {contact.obs}</Text>
      </Box>
      <Modal isOpen={isOpen} onClose={onClose}>
        <ModalOverlay />
        <ModalContent as="form" onSubmit={handleSubmit(handleEdit)} padding={0}>
          <ModalHeader padding={3}>
            Editar Contato de {contact.name}
          </ModalHeader>
          <ModalBody padding={3}>
            <Input
              autoComplete="none"
              error={errors.cpf}
              label="CPF (com pontos e traço)"
              placeholder={contact.cpf}
              {...register("cpf")}
            />
            <Input
              autoComplete="none"
              error={errors.email}
              label="Email"
              placeholder={contact.email}
              {...register("email")}
            />
            <Input
              autoComplete="none"
              error={errors.number}
              label="Número"
              placeholder={contact.number}
              {...register("number")}
            />
            <Input
              autoComplete="none"
              error={errors.obs}
              label="Observação"
              placeholder={contact.obs}
              {...register("obs")}
            />
          </ModalBody>

          <ModalFooter padding={3}>
            <Button colorScheme="green" mr={2} type="submit" width="full">
              Salvar
            </Button>
            <Button
              colorScheme="red"
              onClick={() => {
                reset();
                onClose();
              }}
              variant="ghost"
            >
              Cancelar
            </Button>
          </ModalFooter>
        </ModalContent>
      </Modal>
    </>
  );
}
