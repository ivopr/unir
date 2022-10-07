import {
  Button,
  Flex,
  Heading,
  HStack,
  Icon,
  SimpleGrid,
  Spinner,
  useBreakpointValue,
  useToast,
} from "@chakra-ui/react";
import faker from "faker";
import React, { useState } from "react";
import {
  RiAddLine,
  RiDeleteBinLine,
  RiErrorWarningLine,
  RiFolderWarningLine,
} from "react-icons/ri";

import { ContactCard } from "../components/contact-card";
import { Container } from "../components/container";
import { Pagination } from "../components/pagination";
import { setupApiClient } from "../services/api";
import { useContactsQuery } from "../services/react-query/hooks/use-contacts";

export default function Home(): JSX.Element {
  const [page, setPage] = useState(1);
  const skip = useBreakpointValue({
    base: 10,
    lg: 15,
  });
  const { data, error, isLoading, isFetching, isRefetching, refetch } =
    useContactsQuery(page, skip);
  const toast = useToast();

  const addNewContact = async (): Promise<void> => {
    const api = setupApiClient();

    faker.locale = "pt_BR";
    const firstName = faker.name.firstName();
    const lastName = faker.name.lastName();
    await api
      .post("/contacts", {
        name: `${firstName} ${lastName}`,
        email: faker.internet.email(firstName, lastName, "heavenly.cat"),
        number: faker.phone.phoneNumber(),
        obs: faker.lorem.sentence(),
        cpf: `${faker.datatype.number({
          min: 111,
          max: 999,
        })}.${faker.datatype.number({
          min: 111,
          max: 999,
        })}.${faker.datatype.number({
          min: 111,
          max: 999,
        })}-${faker.datatype.number({
          min: 11,
          max: 99,
        })}`,
      })
      .then(async () => {
        toast({
          duration: 5000,
          title: "Novo contato criado.",
          status: "success",
        });
        await refetch();
      })
      .catch(() =>
        toast({
          duration: 5000,
          title: "Houve um erro ao criar um novo contato.",
          status: "error",
        })
      );

    await refetch();
  };

  const deleteAllContacts = async (): Promise<void> => {
    const api = setupApiClient();

    await api
      .delete("/contacts")
      .then(async () => {
        toast({
          duration: 5000,
          title: "Todos os contatos foram deletados.",
          status: "success",
        });
        await refetch();
      })
      .catch(() =>
        toast({
          duration: 5000,
          title: "Houve um erro ao deletar os contatos.",
          status: "error",
        })
      );
  };

  return (
    <Container pageTitle="Home">
      <Heading
        fontSize={{ base: "xl", md: "2xl", lg: "3xl" }}
        marginTop={4}
        textAlign="center"
      >
        Contatos
      </Heading>
      <HStack marginY={2} spacing={2} width="100%">
        <Button
          leftIcon={<Icon as={RiAddLine} />}
          onClick={addNewContact}
          width="full"
        >
          Adicionar Contato (Aleatório)
        </Button>
        <Button
          colorScheme="red"
          leftIcon={<Icon as={RiDeleteBinLine} />}
          onClick={deleteAllContacts}
          width="fit-content"
        >
          Apagar Tudo
        </Button>
      </HStack>
      {isLoading || isFetching || isRefetching ? (
        <Flex alignItems="center" direction="column">
          <Spinner size="xl" />
          <Heading fontSize={{ base: "lg", md: "xl", lg: "2xl" }}>
            Carregando...
          </Heading>
        </Flex>
      ) : error ? (
        <Flex alignItems="center" direction="column">
          <Icon as={RiErrorWarningLine} color="red.500" fontSize={64} />
          <Heading fontSize={{ base: "lg", md: "xl", lg: "2xl" }}>
            Erro ao buscar contatos
          </Heading>
        </Flex>
      ) : data && data.total >= 1 ? (
        <>
          <Pagination
            currentPage={page}
            onPageChange={setPage}
            totalRegisterCount={data.total}
            registersPerPage={skip}
          />
          <SimpleGrid
            columns={{
              base: 1,
              md: 2,
              lg: 3,
            }}
            gap={4}
            marginY={2}
          >
            {data.contacts.map((contact) => (
              <ContactCard
                key={contact.name + contact.id}
                refetch={refetch}
                {...contact}
              />
            ))}
          </SimpleGrid>
          <Pagination
            currentPage={page}
            onPageChange={setPage}
            totalRegisterCount={data.total}
            registersPerPage={skip}
          />
        </>
      ) : (
        <Flex alignItems="center" direction="column">
          <Icon as={RiFolderWarningLine} color="orange.500" fontSize={64} />
          <Heading fontSize={{ base: "lg", md: "xl", lg: "2xl" }}>
            Não há contatos cadastrados
          </Heading>
        </Flex>
      )}
    </Container>
  );
}
