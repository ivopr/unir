import { Button } from "@chakra-ui/react";
import NextLink from "next/link";
import { useRouter } from "next/router";
import React from "react";

import { NavItem } from "../../types/navigation";

interface NavigationButtonProps extends NavItem {
  isMobile?: boolean;
  closeMobile?: () => void;
}

export function NavigationButton({
  isMobile = false,
  closeMobile,
  ...rest
}: NavigationButtonProps): JSX.Element {
  const { asPath } = useRouter();

  let isActive = false;

  if (asPath === rest.href) {
    isActive = true;
  }

  return (
    <NextLink href={rest.href} passHref>
      <Button
        as="a"
        colorScheme={isActive ? "primary" : "gray"}
        rounded="none"
        variant="ghost"
        onClick={closeMobile ? () => closeMobile() : () => null}
        width={isMobile ? "full" : "auto"}
      >
        {rest.label}
      </Button>
    </NextLink>
  );
}
