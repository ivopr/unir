import { Button as ChakraButton, ButtonProps as ChakraButtonProps } from "@chakra-ui/react"

type ButtonProps = ChakraButtonProps;

export function Button({ children, ...rest }: ButtonProps) {
	return (
		<ChakraButton
			_hover={{
				backgroundColor: "primary.700",
				color: "white"
			}}
			backgroundColor="primary.500"
			color="gray.100"
			{...rest}
		>
			{children}
		</ChakraButton>
	)
}