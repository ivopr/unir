import { Button, Container, Group, Paper, SimpleGrid, Text, Title } from "@mantine/core";
import { useNotifications } from "@mantine/notifications";
import { Product } from "@prisma/client";
import { GetServerSideProps } from "next";
import Head from "next/head";
import { getSession, useSession } from "next-auth/react";
import { useTranslation } from "next-i18next";
import { serverSideTranslations } from "next-i18next/serverSideTranslations";
import { Trash } from "tabler-icons-react";

import { EditProductModal } from "../components/edit-product-modal/edit-product-modal";
import { Loader } from "../components/loader";
import { generateProductsReport } from "../components/report-generator";
import { withSSRAdmin } from "../hocs/with-ssr-admin";
import { useDeleteProductMutation, useGetAllProductsQuery } from "../store/api/product";

export default function Producs(): JSX.Element {
  const { data } = useSession();
  const { data: products, refetch } = useGetAllProductsQuery(null);
  const [deleteProduct] = useDeleteProductMutation();
  const notifications = useNotifications();
  const commonTL = useTranslation("common");
  const productsTL = useTranslation("products");

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
          {productsTL.t("title")} &bull; {commonTL.t("app-name")}
        </title>
      </Head>
      <Title align="center" sx={(theme) => ({ color: theme.colors[theme.primaryColor][3] })}>
        {productsTL.t("title")}
      </Title>
      <Button fullWidth onClick={() => generateProductsReport(products as Product[])}>
        {productsTL.t("report")}
      </Button>
      {products &&
        products?.length > 0 &&
        products?.map((prod: Product) => (
          <Paper key={prod.id} withBorder my="xs" p="md">
            <SimpleGrid
              breakpoints={[
                { maxWidth: "sm", cols: 1 },
                { maxWidth: "md", cols: 2 },
                { minWidth: "md", cols: 4 },
              ]}
            >
              <Group direction="column" spacing={0}>
                <Text color="dimmed">{productsTL.t("modal.name")}</Text>
                <Text>{prod.name}</Text>
              </Group>
              <Group direction="column" spacing={0}>
                <Text color="dimmed">{productsTL.t("modal.price")}</Text>
                <Text>
                  {Intl.NumberFormat("pt-BR", {
                    currency: "BRL",
                    style: "currency",
                  }).format(prod.price / 100)}
                </Text>
              </Group>
              <Group direction="column" spacing={0}>
                <Text color="dimmed">{productsTL.t("modal.quantity")}</Text>
                <Text>{prod.quantity}</Text>
              </Group>
              <Group direction="column" spacing={0}>
                <Text color="dimmed">{productsTL.t("modal.type")}</Text>
                <Text>{prod.type}</Text>
              </Group>

              <Group direction="column" spacing={0}>
                <Text color="dimmed">{productsTL.t("modal.provider")}</Text>
                <Text>{prod.providerEmail}</Text>
              </Group>

              <Group direction="column" spacing={0}>
                <Text color="dimmed">{productsTL.t("actions")}</Text>
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

export const getServerSideProps: GetServerSideProps = withSSRAdmin(async (context) => {
  const session = await getSession(context);

  return {
    props: {
      session,
      ...(await serverSideTranslations(context.locale ?? "en", ["common", "products"])),
    },
  };
});
