import { Avatar, Button, Container, Group, Paper, SimpleGrid, Text, Title } from "@mantine/core";
import { GetServerSideProps } from "next";
import Head from "next/head";
import { useRouter } from "next/router";
import { getSession, signOut, useSession } from "next-auth/react";
import { useTranslation } from "next-i18next";
import { serverSideTranslations } from "next-i18next/serverSideTranslations";
import { Logout, Pencil, Trash } from "tabler-icons-react";

import { Loader } from "../components/loader";
import { withSSRAuth } from "../hocs/with-ssr-auth";
import { useGetAllAccountsQuery } from "../store/api/account";

export default function Account(): JSX.Element {
  const { data } = useSession();
  const { data: users } = useGetAllAccountsQuery(null);
  const router = useRouter();
  const accountTL = useTranslation("account");
  const commonTL = useTranslation("common");

  if (!data) {
    return <Loader />;
  }

  return (
    <Container size="md">
      <Head>
        <title>
          {data.user?.name} &bull; {commonTL.t("app-name")}
        </title>
      </Head>
      <Avatar mb="sm" mx="auto" size="xl" src={data.user?.image} />
      <Text align="center">{accountTL.t("welcome")}</Text>
      <Title align="center" sx={(theme) => ({ color: theme.colors[theme.primaryColor][3] })}>
        {data?.user?.name}
      </Title>
      <Button
        fullWidth
        leftIcon={<Logout size={18} />}
        my="md"
        onClick={() => signOut({ redirect: false }).then(() => router.push("/login"))}
      >
        {accountTL.t("logout")}
      </Button>
      {users &&
        users.length > 0 &&
        users.map((user) => (
          <Paper key={user.email} withBorder my="xs" p="md">
            <SimpleGrid
              breakpoints={[
                { maxWidth: "sm", cols: 1 },
                { maxWidth: "md", cols: 2 },
                { minWidth: "md", cols: data.role === "ADMIN" ? 4 : 3 },
              ]}
            >
              <Group direction="column" spacing={0}>
                <Text color="dimmed">{accountTL.t("name")}</Text>
                <Text>{user.name}</Text>
              </Group>
              <Group direction="column" spacing={0}>
                <Text color="dimmed">{accountTL.t("email")}</Text>
                <Text>{user.email}</Text>
              </Group>
              <Group direction="column" spacing={0}>
                <Text color="dimmed">{accountTL.t("role")}</Text>
                <Text>{user.role}</Text>
              </Group>

              {data.role === "ADMIN" && (
                <Group direction="column" spacing={0}>
                  <Text color="dimmed">{accountTL.t("actions")}</Text>
                  <Group align="baseline" spacing="xs">
                    <Button color="blue">
                      <Pencil />
                    </Button>
                    <Button color="red">
                      <Trash />
                    </Button>
                  </Group>
                </Group>
              )}
            </SimpleGrid>
          </Paper>
        ))}
    </Container>
  );
}

export const getServerSideProps: GetServerSideProps = withSSRAuth(async (context) => {
  const session = await getSession(context);

  return {
    props: {
      session,
      ...(await serverSideTranslations(context.locale ?? "en", ["account", "common"])),
    },
  };
});
