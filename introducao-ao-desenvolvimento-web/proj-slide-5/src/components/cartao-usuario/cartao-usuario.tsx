import { Button, Badge, Box, Image } from "@chakra-ui/react";
import Router from "next/router";
import { PersonEditFilled } from "@fluentui/react-icons";

import { Usuario } from "../../queries/useUsuarios";

type CartaoUsuarioProps = {
	usuario: Usuario;
}

export function CartaoUsuario({ usuario }: CartaoUsuarioProps) {
  return (
    <Box
			borderWidth="1px"
			borderRadius="lg"
			maxWidth="sm"
			onClick={() => Router.push(`/${usuario.username}`)}
			overflow="hidden"
			position="relative"
		>
			<Button
				colorScheme="primary"
				leftIcon={<PersonEditFilled fontSize="22" />}
				position="absolute"
				right="1"
				size="sm"
				top="1"
				variant="ghost"
			>
				Editar
			</Button>
      <Image src="https://placekitten.com/400/200" alt={usuario.nome} />

      <Box padding="6">
        <Box alignItems="baseline" display="flex">
          <Badge borderRadius="full" colorScheme={usuario.posicao === "ADMIN" ? "red" : "primary"} paddingX="2">
            {usuario.posicao}
          </Badge>
          <Box
            color="gray.500"
            fontWeight="semibold"
            letterSpacing="wide"
            fontSize="xs"
            textTransform="uppercase"
            marginLeft="2"
          >
            {usuario.ativo ? "Ativo " : "Não Ativo "}
						&bull;
						{" " + new Date(usuario.nascimento).toLocaleDateString("pt-BR", {
							day: "2-digit",
							month: "long",
							year: "numeric"
						})}
          </Box>
        </Box>

        <Box
          marginTop="1"
          fontWeight="semibold"
          as="h4"
          lineHeight="tight"
          isTruncated
        >
          {usuario.username} &bull; {usuario.nome}
        </Box>

        <Box>
          <b>Email:</b> {usuario.email}
        </Box>

        <Box>
					<b>Celular:</b> {usuario.celular}
        </Box>
      </Box>
    </Box>
  )
}