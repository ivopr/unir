import { Avatar, Button, Container, Group, Paper, SimpleGrid, Text, Title } from "@mantine/core";
import { useNotifications } from "@mantine/notifications";
import { Product } from "@prisma/client";
import { GetServerSideProps } from "next";
import Head from "next/head";
import { useRouter } from "next/router";
import { getSession, signOut, useSession } from "next-auth/react";
import { useTranslation } from "next-i18next";
import { serverSideTranslations } from "next-i18next/serverSideTranslations";
import { Logout, Trash } from "tabler-icons-react";

import { CreateProductModal } from "../components/create-product-modal/create-product-modal";
import { EditProductModal } from "../components/edit-product-modal/edit-product-modal";
import { Loader } from "../components/loader";
import { withSSRAuth } from "../hocs/with-ssr-auth";
import { useDeleteProductMutation, useGetMyProductsQuery } from "../store/api/product";

export default function Account(): JSX.Element {
  const { data } = useSession();
  const { data: products, refetch } = useGetMyProductsQuery(data?.user?.email as string);
  const [deleteProduct] = useDeleteProductMutation();
  const router = useRouter();
  const notifications = useNotifications();
  const accountTL = useTranslation("account");
  const commonTL = useTranslation("common");

  const onDelete = async (id: string): Promise<void> => {
    await deleteProduct(id)
      .unwrap()
      .then((res) => {
        if (res.message === "deleted") {
          notifications.showNotification({
            message: "Product deleted",
            color: "green",
          });

          refetch();
        }
      });
  };

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
      {data.role === "PROVIDER" && <CreateProductModal />}
      {products &&
        products?.length > 0 &&
        products?.map((prod: Product) => (
          <Paper key={prod.id} withBorder my="xs" p="md">
            <SimpleGrid
              breakpoints={[
                { maxWidth: "sm", cols: 1 },
                { maxWidth: "md", cols: 2 },
                { minWidth: "md", cols: 5 },
              ]}
            >
              <Group direction="column" spacing={0}>
                <Text color="dimmed">{accountTL.t("name")}</Text>
                <Text>{prod.name}</Text>
              </Group>
              <Group direction="column" spacing={0}>
                <Text color="dimmed">{accountTL.t("modal.price")}</Text>
                <Text>
                  {Intl.NumberFormat("pt-BR", {
                    currency: "BRL",
                    style: "currency",
                  }).format(prod.price / 100)}
                </Text>
              </Group>
              <Group direction="column" spacing={0}>
                <Text color="dimmed">{accountTL.t("modal.quantity")}</Text>
                <Text>{prod.quantity}</Text>
              </Group>
              <Group direction="column" spacing={0}>
                <Text color="dimmed">{accountTL.t("modal.type")}</Text>
                <Text>{prod.type}</Text>
              </Group>

              <Group direction="column" spacing={0}>
                <Text color="dimmed">{accountTL.t("actions")}</Text>
                <Group align="baseline" spacing="xs">
                  <EditProductModal product={prod} />
                  <Button color="red" onClick={() => onDelete(prod.id)}>
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

export const getServerSideProps: GetServerSideProps = withSSRAuth(async (context) => {
  const session = await getSession(context);

  return {
    props: {
      session,
      ...(await serverSideTranslations(context.locale ?? "en", ["account", "common", "products"])),
    },
  };
});
