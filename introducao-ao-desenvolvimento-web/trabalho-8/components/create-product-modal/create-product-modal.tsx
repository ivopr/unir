import { Button, Group, Modal, NumberInput, TextInput } from "@mantine/core";
import { useForm, zodResolver } from "@mantine/form";
import { useNotifications } from "@mantine/notifications";
import { useSession } from "next-auth/react";
import { useTranslation } from "next-i18next";
import { useState } from "react";
import { Plus } from "tabler-icons-react";
import { z } from "zod";

import { useGetMyProductsQuery, usePostCreateProductMutation } from "../../store/api/product";

const CreateProductSchema = z.object({
  quantity: z.number().nonnegative({ message: "You can't have a negative stock" }),
  name: z.string().nonempty({ message: "Your product must have a name" }),
  price: z.number().nonnegative({ message: "You can't pay your customers to buy your products" }),
  type: z.string(),
});

export function CreateProductModal(): JSX.Element {
  const [opened, setOpened] = useState(false);
  const [createProduct] = usePostCreateProductMutation();
  const form = useForm<z.infer<typeof CreateProductSchema>>({
    schema: zodResolver(CreateProductSchema),
    initialValues: {
      name: "",
      price: 0,
      quantity: 0,
      type: "",
    },
  });
  const notifications = useNotifications();
  const accountTL = useTranslation("account");

  const { data: sessionData } = useSession();
  const { refetch } = useGetMyProductsQuery(sessionData?.user?.email as string);

  const onSubmit = form.onSubmit(async ({ name, price, quantity, type }) => {
    // Handle your credentials login here
    await createProduct({ name, price, quantity, type })
      .unwrap()
      .then((data) => {
        notifications.showNotification({
          message: `Product ${data.name} created`,
          color: "green",
        });

        refetch();
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
        title={accountTL.t("modal.title")}
      >
        <form onSubmit={onSubmit}>
          <TextInput label={accountTL.t("modal.name")} {...form.getInputProps("name")} />
          <NumberInput
            hideControls
            label={accountTL.t("modal.price")}
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
            label={accountTL.t("modal.quantity")}
            mt="md"
            {...form.getInputProps("quantity")}
          />
          <TextInput label={accountTL.t("modal.type")} mt="md" {...form.getInputProps("type")} />
          <Button type="submit" leftIcon={<Plus size={18} />} fullWidth mt="xl">
            {accountTL.t("modal.title")}
          </Button>
        </form>
      </Modal>

      <Group position="center">
        <Button color="green" fullWidth mb="md" size="lg" onClick={() => setOpened(true)}>
          {accountTL.t("modal.title")}
        </Button>
      </Group>
    </>
  );
}
