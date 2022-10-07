import { Flex, Heading, Icon } from "@chakra-ui/react";
import React from "react";
import { GiCat } from "react-icons/gi";

export function Logo(): JSX.Element {
  return (
    <Flex
      alignItems="center"
      cursor="pointer"
      direction="row"
      role="group"
      userSelect="none"
      width="fit-content"
    >
      <Icon
        as={GiCat}
        color="primary.500"
        height={9}
        transform="rotate(-15deg)"
        transition="color 0.4s ease-in-out"
        width={9}
      />
      <Heading
        _groupFocus={{
          color: "primary.500",
        }}
        _groupHover={{
          color: "primary.500",
        }}
        color="primary.300"
        fontSize="xl"
        marginLeft={2.5}
        transition="color 0.4s ease-in-out"
      >
        {"heavenly.cat"}
      </Heading>
    </Flex>
  );
}
