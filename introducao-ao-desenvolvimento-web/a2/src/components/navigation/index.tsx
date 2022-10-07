import {
  Box,
  chakra,
  CloseButton,
  Flex,
  HStack,
  IconButton,
  useColorMode,
  useColorModeValue,
  useDisclosure,
  VStack,
} from "@chakra-ui/react";
import NextLink from "next/link";
import React from "react";
import { AiOutlineMenu } from "react-icons/ai";
import { RiMoonLine, RiSunLine } from "react-icons/ri";

import { NAV_ITEMS } from "../../settings/navigation";
import { Logo } from "../logo";
import { NavigationButton } from "./navigation-button";

export function Navigation(): JSX.Element {
  const { toggleColorMode, colorMode } = useColorMode();
  const bg = useColorModeValue("white", "gray.800");
  const mobileNav = useDisclosure();

  return (
    <React.Fragment>
      <chakra.header
        background={bg}
        paddingX={{ base: 2, sm: 4 }}
        paddingY={4}
        position="sticky"
        top={0}
        shadow="md"
        width="full"
        zIndex="sticky"
      >
        <Flex alignItems="center" justifyContent="space-between" mx="auto">
          <Flex as={NextLink} href="/" passHref>
            <chakra.a alignItems="center" display="flex" title={"Home"}>
              <Logo />
            </chakra.a>
          </Flex>
          <HStack alignItems="center" display="flex" spacing={1}>
            <HStack
              display={{ base: "none", md: "inline-flex" }}
              marginRight={1}
              spacing={1}
            >
              {NAV_ITEMS.map((item) => (
                <NavigationButton key={item.label + item.href} {...item} />
              ))}
            </HStack>
            <IconButton
              aria-label="Toggle theme"
              borderRadius="none"
              color={useColorModeValue("gray.800", "inherit")}
              fontSize="20px"
              icon={colorMode === "dark" ? <RiSunLine /> : <RiMoonLine />}
              onClick={toggleColorMode}
              variant="ghost"
            />
            <Box display={{ base: "inline-flex", md: "none" }}>
              <IconButton
                aria-label="Open menu"
                borderRadius="none"
                color={useColorModeValue("gray.800", "inherit")}
                display={{ base: "flex", md: "none" }}
                fontSize="20px"
                icon={<AiOutlineMenu />}
                onClick={mobileNav.onOpen}
                variant="ghost"
              />

              <VStack
                background={bg}
                display={mobileNav.isOpen ? "flex" : "none"}
                flexDirection="column"
                left={0}
                padding={2}
                paddingBottom={4}
                position="absolute"
                right={0}
                rounded="none"
                shadow="md"
                spacing={3}
                top={0}
                zIndex={10}
              >
                <CloseButton
                  aria-label="Close menu"
                  borderRadius="none"
                  onClick={mobileNav.onClose}
                />

                {NAV_ITEMS.map((item) => (
                  <NavigationButton
                    isMobile
                    closeMobile={mobileNav.onClose}
                    key={item.label + item.href}
                    {...item}
                  />
                ))}
              </VStack>
            </Box>
          </HStack>
        </Flex>
      </chakra.header>
    </React.Fragment>
  );
}
