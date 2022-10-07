import {
  createStyles,
  Navbar as MantineNavbar,
  NavbarProps as MantineNavbarProps,
  ScrollArea,
} from "@mantine/core";
import { useSession } from "next-auth/react";
import React from "react";
import { Box, Home, User } from "tabler-icons-react";

import { LinksGroup } from "./links-group";

const useStyles = createStyles((theme) => ({
  navbar: {
    paddingBottom: 0,
    paddingLeft: theme.spacing.md,
    paddingRight: theme.spacing.md,
    paddingTop: 0,
  },

  header: {
    padding: theme.spacing.md,
    paddingTop: 0,
    marginLeft: -theme.spacing.md,
    marginRight: -theme.spacing.md,
    color: theme.colorScheme === "dark" ? theme.white : theme.black,
    borderBottom: `1px solid ${
      theme.colorScheme === "dark" ? theme.colors.dark[4] : theme.colors.gray[3]
    }`,
  },

  links: {
    marginLeft: -theme.spacing.md,
    marginRight: -theme.spacing.md,
  },

  linksInner: {
    paddingTop: 0,
    paddingBottom: theme.spacing.xl,
  },

  footer: {
    marginLeft: -theme.spacing.md,
    marginRight: -theme.spacing.md,
    borderTop: `1px solid ${
      theme.colorScheme === "dark" ? theme.colors.dark[4] : theme.colors.gray[3]
    }`,
  },
}));

type NavbarProps = Omit<MantineNavbarProps, "children"> & {
  onClose: () => void;
};

export function Navbar({ onClose, ...rest }: NavbarProps): JSX.Element {
  const { status, data } = useSession();

  const mockdata = [
    { label: "Home", icon: Home, link: "/" },
    data?.role === "ADMIN" && { label: "(ADMIN) Products", icon: Box, link: "/products" },
    data?.role === "ADMIN" && { label: "(ADMIN) Users", icon: Box, link: "/users" },
    {
      label: "Account",
      initiallyOpened: false,
      icon: User,
      links:
        status === "authenticated"
          ? [{ label: "My Account", link: "/account" }]
          : [
              { label: "Login", link: "/login" },
              { label: "Register", link: "/register" },
            ],
    },
  ];

  const { classes } = useStyles();
  const links = mockdata.map(
    (item) =>
      item !== undefined &&
      item !== false && <LinksGroup onClose={onClose} {...item} key={item.label} />
  );

  return (
    <MantineNavbar className={classes.navbar} {...rest}>
      <MantineNavbar.Section grow className={classes.links} component={ScrollArea}>
        <div className={classes.linksInner}>{links}</div>
      </MantineNavbar.Section>
    </MantineNavbar>
  );
}
