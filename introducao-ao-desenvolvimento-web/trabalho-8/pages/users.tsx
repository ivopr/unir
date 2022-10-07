import { Button, Container, Group, Paper, SimpleGrid, Text, Title } from "@mantine/core";
import { useNotifications } from "@mantine/notifications";
import { User } from "@prisma/client";
import { GetServerSideProps } from "next";
import Head from "next/head";
import { getSession } from "next-auth/react";
import { useTranslation } from "next-i18next";
import { serverSideTranslations } from "next-i18next/serverSideTranslations";
import { Key, Trash } from "tabler-icons-react";

import { EditUserModal } from "../components/edit-account-modal/edit-account-modal";
import { generateUsersReport } from "../components/report-generator";
import { withSSRAdmin } from "../hocs/with-ssr-admin";
import {
  useDeleteAccountMutation,
  useGetAllAccountsQuery,
  useToggleAccountActiveMutation,
} from "../store/api/account";

export default function Characters(): JSX.Element {
  const { data: accounts, refetch } = useGetAllAccountsQuery(null);
  const [deleteAccount] = useDeleteAccountMutation();
  const [toggleAccountActive] = useToggleAccountActiveMutation();
  const notifications = useNotifications();
  const accountsTL = useTranslation("accounts");
  const commonTL = useTranslation("common");

  const onDelete = async (id: string): Promise<void> => {
    await deleteAccount(id)
      .unwrap()
      .then((res) => {
        if (res.message === "deleted") {
          notifications.showNotification({
            message: "Account deleted",
            color: "green",
          });

          refetch();
        }
      });
  };

  const onToggleActive = async (id: string): Promise<void> => {
    await toggleAccountActive(id)
      .unwrap()
      .then((res) => {
        if (res.message === "toggled") {
          notifications.showNotification({
            message: "Account activated/deactivated",
            color: "green",
          });

          refetch();
        }
      })
      .catch((res) => {
        if (res.data.message === "cannot-deactivate-yourself") {
          notifications.showNotification({
            message: "You can't deactivate yourself",
            color: "yellow",
          });
        }
      });
  };

  return (
    <Container size="md">
      <Head>
        <title>
          {accountsTL.t("title")} &bull; {commonTL.t("app-name")}
        </title>
      </Head>
      <Title>{accountsTL.t("title")}</Title>
      <Button fullWidth onClick={() => generateUsersReport(accounts as User[])}>
        {accountsTL.t("report")}
      </Button>
      {accounts &&
        accounts?.length > 0 &&
        accounts.map((user: User) => (
          <Paper key={user.id} withBorder my="xs" p="md">
            <SimpleGrid
              breakpoints={[
                { maxWidth: "sm", cols: 1 },
                { maxWidth: "md", cols: 2 },
                { minWidth: "md", cols: 4 },
              ]}
            >
              <Group direction="column" spacing={0}>
                <Text color="dimmed">{accountsTL.t("modal.name")}</Text>
                <Text>{user.name}</Text>
              </Group>
              <Group direction="column" spacing={0}>
                <Text color="dimmed">{accountsTL.t("modal.email")}</Text>
                <Text>{user.email}</Text>
              </Group>
              <Group direction="column" spacing={0}>
                <Text color="dimmed">{accountsTL.t("modal.role")}</Text>
                <Text>{user.role}</Text>
              </Group>
              <Group direction="column" spacing={0}>
                <Text color="dimmed">{accountsTL.t("actions")}</Text>
                <Group align="baseline" spacing="xs">
                  <Button
                    color={user.active ? "blue" : "gray"}
                    onClick={() => onToggleActive(user.id)}
                  >
                    <Key />
                  </Button>
                  <EditUserModal user={user} />
                  <Button color="red" onClick={() => onDelete(user.id)}>
                    <Trash />
                  </Button>
                </Group>
              </Group>
            </SimpleGrid>
          </Paper>
        ))}
    </Container>
  );
}

export const getServerSideProps: GetServerSideProps = withSSRAdmin(async (context) => {
  const session = await getSession({ ctx: context });

  return {
    props: {
      session,
      ...(await serverSideTranslations(context.locale ?? "en", ["accounts", "common"])),
    },
  };
});
