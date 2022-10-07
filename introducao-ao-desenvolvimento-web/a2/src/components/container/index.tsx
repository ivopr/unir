import { Flex, FlexProps } from "@chakra-ui/react";
import Head from "next/head";
import React, { ReactNode } from "react";

export interface ContainerProps extends FlexProps {
  children: ReactNode;
  pageTitle: string;
}

export function Container({
  children,
  pageTitle,
  ...rest
}: ContainerProps): JSX.Element {
  return (
    <Flex
      direction="column"
      paddingY={2.5}
      paddingX={{
        base: 4,
        md: 8,
        lg: 16,
      }}
      width="100%"
      {...rest}
    >
      <Head>
        <title>{pageTitle} | heavenly.cat</title>
      </Head>
      {children}
    </Flex>
  );
}
