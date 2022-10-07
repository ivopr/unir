import { ChakraProvider, Flex } from "@chakra-ui/react";
import { AppProps } from "next/app";
import React from "react";
import { QueryClientProvider } from "react-query";
import { ReactQueryDevtools } from "react-query/devtools";

import { Navigation } from "../components/navigation";
import { queryClient } from "../services/react-query/query-client";
import { theme } from "../theme";

export default function MyApp({ Component, pageProps }: AppProps): JSX.Element {
  return (
    <QueryClientProvider client={queryClient}>
      <ChakraProvider theme={theme}>
        <Flex direction="column" minHeight="100vh">
          <Navigation />
          <Flex alignItems="center" direction="column" minHeight="100%">
            <Component {...pageProps} />
          </Flex>
        </Flex>
      </ChakraProvider>

      {process.env.NODE_ENV === "development" && <ReactQueryDevtools />}
    </QueryClientProvider>
  );
}
