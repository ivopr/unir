import { ChakraProvider } from "@chakra-ui/react"
import { AppProps } from "next/app"
import { QueryClientProvider } from "react-query"
import { ReactQueryDevtools } from "react-query/devtools"

import { queryClient } from "../services/react-query"
import { theme } from "../theme"

export default function MyApp({ Component, pageProps }: AppProps) {
  return (
    <QueryClientProvider client={queryClient}>
      <ChakraProvider theme={theme}>
        <Component {...pageProps} />

				{process.env.NODE_ENV === "development" && <ReactQueryDevtools />}
      </ChakraProvider>
    </QueryClientProvider>
  )
}
