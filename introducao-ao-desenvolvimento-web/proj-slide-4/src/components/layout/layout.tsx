import { Container, ContainerProps } from "@chakra-ui/react";
import Head from "next/head";

type LayoutProps = ContainerProps & {
	pageTitle: string
}

export function Layout({ children, pageTitle, ...rest }: LayoutProps) {
	return (
		<Container
			paddingX={{
				base: "1",
				md: "1.5",
				lg: "2.5"
			}}
			{...rest}
		>
			<Head>
				<title>{pageTitle} - Locadora</title>
			</Head>
			{children}
		</Container>
	)
}