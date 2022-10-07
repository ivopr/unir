import { Box, BoxProps } from "@chakra-ui/react";
import Head from "next/head";

type LayoutProps = BoxProps & {
	pageTitle: string
}

export function Layout({ children, pageTitle, ...rest }: LayoutProps) {
	return (
		<Box
			paddingX={{
				base: "1",
				md: "1.5",
				lg: "2.5"
			}}
			{...rest}
		>
			<Head>
				<title>{pageTitle} - Usuários</title>
			</Head>
			{children}
		</Box>
	)
}