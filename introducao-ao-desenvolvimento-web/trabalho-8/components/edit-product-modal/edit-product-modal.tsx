import { Button, Group, Modal, NumberInput, TextInput } from "@mantine/core";
import { useForm, zodResolver } from "@mantine/form";
import { useNotifications } from "@mantine/notifications";
import { Product } from "@prisma/client";
import { useSession } from "next-auth/react";
import { useTranslation } from "next-i18next";
import { useState } from "react";
import { Pencil } from "tabler-icons-react";
import { z } from "zod";

import {
  useGetAllProductsQuery,
  useGetMyProductsQuery,
  usePutUpdateProductMutation,
} from "../../store/api/product";

const EditProductSchema = z.object({
  quantity: z.number().nonnegative({ message: "You can't have a negative stock" }),
  name: z.string().nonempty({ message: "Your product must have a name" }),
  price: z.number().nonnegative({ message: "You can't pay your customers to buy your products" }),
  type: z.string(),
});

type EditProductModal = {
  product: Product;
};

export function EditProductModal({ product }: EditProductModal): JSX.Element {
  const [opened, setOpened] = useState(false);
  const [updateProduct] = usePutUpdateProductMutation();
  const form = useForm<z.infer<typeof EditProductSchema>>({
    schema: zodResolver(EditProductSchema),
    initialValues: {
      name: product.name,
      price: product.price,
      quantity: product.quantity ?? 0,
      type: product.type ?? "",
    },
  });
  const notifications = useNotifications();
  const productsTL = useTranslation("products");

  const { data: sessionData } = useSession();
  const { refetch } = useGetAllProductsQuery(null);
  const { refetch: refetchSessionProducts } = useGetMyProductsQuery(
    sessionData?.user?.email as string
  );

  const onSubmit = form.onSubmit(async ({ name, price, quantity, type }) => {
    // Handle your credentials login here
    await updateProduct({ id: product.id, name, price, quantity, type })
      .unwrap()
      .then((data) => {
        notifications.showNotification({
          message: `Product ${data.name} updated`,
          color: "green",
        });

        refetch();
        refetchSessionProducts();
        setOpened(false);
        form.reset();
      })
      .catch(() => {
        notifications.showNotification({
          message: "There was an error creating your product",
          color: "red",
        });
      });
  });

  return (
    <>
      <Modal
        centered
        opened={opened}
        onClose={() => setOpened(false)}
        title={productsTL.t("modal.title")}
      >
        <form onSubmit={onSubmit}>
          <TextInput label={productsTL.t("modal.name")} {...form.getInputProps("name")} />
          <NumberInput
            label={productsTL.t("modal.price")}
            mt="md"
            parser={(value) => value?.replace(/\D+/g, "")}
            formatter={(value) =>
              !Number.isNaN(Number(value))
                ? Intl.NumberFormat("pt-BR", {
                    currency: "BRL",
                    style: "currency",
                  }).format(Number(value) / 100)
                : Intl.NumberFormat("pt-BR", {
                    currency: "BRL",
                    style: "currency",
                  }).format(0)
            }
            {...form.getInputProps("price")}
          />
          <NumberInput
            label={productsTL.t("modal.quantity")}
            mt="md"
            {...form.getInputProps("quantity")}
          />
          <TextInput label={productsTL.t("modal.type")} mt="md" {...form.getInputProps("type")} />
          <Button type="submit" leftIcon={<Pencil size={18} />} fullWidth mt="xl">
            {productsTL.t("modal.title")}
          </Button>
        </form>
      </Modal>

      <Group position="center">
        <Button color="blue" onClick={() => setOpened(true)}>
          <Pencil />
        </Button>
      </Group>
    </>
  );
}
