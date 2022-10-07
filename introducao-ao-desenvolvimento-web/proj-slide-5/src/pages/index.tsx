import { Box, Flex, Heading, SimpleGrid, Spinner, VStack } from "@chakra-ui/react";
import { Home32Filled, PersonAddFilled } from "@fluentui/react-icons";
import Router from "next/router"
import { useState } from "react";

import { Button, CartaoUsuario, Layout } from "../components";
import { useUsuarios } from "../queries/useUsuarios";

export default function Home() {
  const [page, setPage] = useState(1);
  const { data, isError } = useUsuarios(page);

  return (
    <Layout pageTitle="Todos os Usuários">
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
					<Home32Filled />
				</Box>
				<Heading fontSize={["xl", "2xl", "3xl"]}>Todos os Usuários</Heading>
        <Button
					leftIcon={<PersonAddFilled fontSize="22" />}
          onClick={() => Router.push("/cadastrar")}
					size="lg"
				>
					Cadastrar
				</Button>
			</Flex>

      {data !== undefined ? (
        <VStack marginY="5" spacing="2.5">
          <Heading fontSize={["xl", "2xl", "3xl"]}>
            Existem {data.quantidade} usuários no banco de dados
          </Heading>

          <SimpleGrid columns={[1, 2, 4]} gap="1.5">
            {data.usuarios.map(usuario => <CartaoUsuario key={usuario.id} usuario={usuario} />)}
          </SimpleGrid>
        </VStack>
      ) : isError ? (
        <Heading>Requisição Falhou.</Heading>
      ) : (
        <VStack marginY="10">
          <Spinner emptyColor="gray.200" color="primary.500" thickness="2px" size="xl" />
        </VStack>
      )}
    </Layout>
  );
}
